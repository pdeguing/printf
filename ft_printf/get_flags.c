/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:11:16 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/13 11:11:17 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Setting bolean for each present flag
*/

void		flags_set(t_flags *flags, int *i, const char *format)
{
	while (format[*i] && ft_strchr("#0-+ ", format[*i]))
	{
		if (format[*i] == '#')
			flags->hash = 1;
		if (format[*i] == '0' && flags->dash == 0)
			flags->zero = 1;
		if (format[*i] == '-')
		{
			flags->dash = 1;
			flags->zero = 0;
		}
		if (format[*i] == '+')
			flags->sign = 1;
		if (format[*i] == ' ')
			flags->space = 1;
		*i = *i + 1;
	}
}

/*
** Setting modifier as the sum of specified options
*/

void		flags_modifier(t_flags *flags, int *i, const char *format)
{
	if (format[*i] && ft_strchr("hljz", format[*i]))
	{
		flags->modifier = format[*i];
		*i = *i + 1;
		if (format[*i] && ft_strchr("hljz", format[*i]))
		{
			flags->modifier += format[*i];
			*i = *i + 1;
		}
	}
}

/*
** Storing specifier and adjusting modifier if necessary
*/

void		flags_specifier(t_flags *flags, int *i, const char *format)
{
	if (format[*i] && ft_strchr("SDOUC", format[*i]))
		flags->modifier = 'l';
	if (!format[*i] || !ft_strchr("sSpdDioOuUxXcC%", format[*i]))
		flags->error = 1;
	else
		flags->specifier = format[*i];
	if (ft_strchr("SDOUC", format[*i]))
		flags->specifier = ft_tolower(format[*i]);
	if (flags->specifier == 'c')
		flags->precision = 0;
	if (flags->specifier != 'i' && flags->specifier != 'd')
	{
		flags->sign = 0;
		flags->space = 0;
	}
	*i = *i + 1;
}

/*
** Filling the structure with flags informations
*/

void		flags_init(t_flags *flags, int *i, const char *format)
{
	if (!format[*i])
	{
		flags->error = 1;
		return ;
	}
	flags_set(flags, i, format);
	if (ft_isdigit(format[*i]))
	{
		flags->minimal_width = ft_atoi(&format[*i]);
		while (format[*i] && ft_isdigit(format[*i]))
			*i = *i + 1;
	}
	if (format[*i] == '.')
	{
		*i = *i + 1;
		flags->precision = ft_atoi(&format[*i]);
		if (flags->precision != -1)
			flags->zero = 0;
		while (format[*i] && ft_isdigit(format[*i]))
			*i = *i + 1;
	}
	if (format[*i])
		flags_modifier(flags, i, format);
	flags_specifier(flags, i, format);
}
