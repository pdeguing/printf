/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:11:03 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/13 12:01:17 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Getting the initial version of the format after conversion of the argument
*/

char	*init_format(t_f *f, va_list args)
{
	char	*format;

	if (f->specifier == '%')
	{
		f->space = 0;
		return (ft_ctostr('%'));
	}
	if (f->specifier == 's')
		return (format_str(f, args));
	if (f->specifier == 'c')
		return (format_char(f, args));
	if (ft_strchr("diouxX", f->specifier))
	{
		format = format_int(f, args);
		if (f->precision == 0 && *format == '0')
		{
			ft_strdel(&format);
			format = ft_strnew(1);
			if (f->specifier != 'o')
				f->hash = 0;
		}
		if (*format == '0' && ft_strlen(format) <= 1)
			f->hash = 0;
		return (format);
	}
	if (f->specifier == 'p')
		return (ft_utoa((u_int64_t)va_arg(args, void *), 16));
	return (NULL);
}

/*
** Formatting considering all specified options and printing the final format
*/

int		get_conversion(t_f *f, va_list args)
{
	char	**format;
	char	**prefix;
	char	**suffix;
	int		ret;

	if (!(format = (char **)malloc(sizeof(char *))))
		return (-1);
	*format = init_format(f, args);
	if (!(prefix = (char **)malloc(sizeof(char *))))
		return (-1);
	*prefix = ft_strnew(1);
	if (!(suffix = (char **)malloc(sizeof(char *))))
		return (-1);
	*suffix = ft_strnew(1);
	format_conversion(f, format, prefix, suffix);
	ret = print_format(f, prefix, format, suffix);
	free(format);
	free(prefix);
	free(suffix);
	return (ret);
}
