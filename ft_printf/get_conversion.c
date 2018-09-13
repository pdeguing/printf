/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:11:03 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/13 11:21:54 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Getting the initial version of the format after conversion of the argument
*/

char	*init_format(t_flags *flags, va_list args)
{
	char	*format;

	if (flags->specifier == '%')
	{
		flags->space = 0;
		return (ft_ctostr('%'));
	}
	if (flags->specifier == 's')
		return (format_str(flags, args));
	if (flags->specifier == 'c')
		return (format_char(flags, args));
	if (ft_strchr("diouxX", flags->specifier))
	{
		format = format_int(flags, args);
		if (flags->precision == 0 && *format == '0')
		{
			ft_strdel(&format);
			format = ft_strnew(1);
			if (flags->specifier != 'o')
				flags->hash = 0;
		}
		if (*format == '0' && ft_strlen(format) <= 1)
			flags->hash = 0;
		return (format);
	}
	if (flags->specifier == 'p')
		return (ft_utoa((u_int64_t)va_arg(args, void *), 16));
	return (NULL);
}

/*
** Formatting considering all specified options and printing the final format
*/

int		get_conversion(t_flags *flags, va_list args)
{
	char	**format;
	char	**prefix;
	char	**suffix;
	int		ret;

	if (!(format = (char **)malloc(sizeof(char *))))
		return (-1);
	*format = init_format(flags, args);
	if (!(prefix = (char **)malloc(sizeof(char *))))
		return (-1);
	*prefix = ft_strnew(1);
	if (!(suffix = (char **)malloc(sizeof(char *))))
		return (-1);
	*suffix = ft_strnew(1);
	format_conversion(flags, format, prefix, suffix);
	ret = print_format(flags, prefix, format, suffix);
	free(format);
	free(prefix);
	free(suffix);
	return (ret);
}
