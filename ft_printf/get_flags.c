/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 12:08:26 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/13 12:08:27 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Setting bolean for each present flag
*/

void		flags_set(t_f *f, int *i, const char *format)
{
	while (format[*i] && ft_strchr("#0-+ ", format[*i]))
	{
		if (format[*i] == '#')
			f->hash = 1;
		if (format[*i] == '0' && f->dash == 0)
			f->zero = 1;
		if (format[*i] == '-')
		{
			f->dash = 1;
			f->zero = 0;
		}
		if (format[*i] == '+')
			f->sign = 1;
		if (format[*i] == ' ')
			f->space = 1;
		*i = *i + 1;
	}
}

/*
** Setting modifier as the sum of specified options
*/

void		flags_modifier(t_f *f, int *i, const char *format)
{
	if (format[*i] && ft_strchr("hljz", format[*i]))
	{
		f->modifier = format[*i];
		*i = *i + 1;
		if (format[*i] && ft_strchr("hljz", format[*i]))
		{
			f->modifier += format[*i];
			*i = *i + 1;
		}
	}
}

/*
** Storing specifier and adjusting modifier if necessary
*/

void		flags_specifier(t_f *f, int *i, const char *format)
{
	if (format[*i] && ft_strchr("SDOUC", format[*i]))
		f->modifier = 'l';
	if (!format[*i] || !ft_strchr("sSpdDioOuUxXcC%", format[*i]))
		f->error = 1;
	else
		f->specifier = format[*i];
	if (ft_strchr("SDOUC", format[*i]))
		f->specifier = ft_tolower(format[*i]);
	if (f->specifier == 'c')
		f->precision = 0;
	if (f->specifier != 'i' && f->specifier != 'd')
	{
		f->sign = 0;
		f->space = 0;
	}
	*i = *i + 1;
}

/*
** Filling the structure with f informations
*/

void		flags_init(t_f *f, int *i, const char *format)
{
	if (!format[*i])
	{
		f->error = 1;
		return ;
	}
	flags_set(f, i, format);
	if (ft_isdigit(format[*i]))
	{
		f->minimal_width = ft_atoi(&format[*i]);
		while (format[*i] && ft_isdigit(format[*i]))
			*i = *i + 1;
	}
	if (format[*i] == '.')
	{
		*i = *i + 1;
		f->precision = ft_atoi(&format[*i]);
		if (f->precision != -1)
			f->zero = 0;
		while (format[*i] && ft_isdigit(format[*i]))
			*i = *i + 1;
	}
	if (format[*i])
		flags_modifier(f, i, format);
	flags_specifier(f, i, format);
}
