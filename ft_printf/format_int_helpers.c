/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:14:00 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/13 14:15:32 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_hh(t_f *f, va_list args)
{
	if (f->specifier == 'd' || f->specifier == 'i')
		return (ft_itoa((char)va_arg(args, int), 10));
	if (f->specifier == 'o')
		return (ft_utoa((unsigned char)va_arg(args, int), 8));
	if (f->specifier == 'u')
		return (ft_utoa((unsigned char)va_arg(args, int), 10));
	if (f->specifier == 'x')
		return (ft_utoa((unsigned char)va_arg(args, int), 16));
	if (f->specifier == 'X')
		return (ft_capitalize(ft_utoa((unsigned char)va_arg(args, int), 16)));
	return (NULL);
}

char	*format_short(t_f *f, va_list args)
{
	if (f->specifier == 'd' || f->specifier == 'i')
		return (ft_itoa((short)va_arg(args, int), 10));
	if (f->specifier == 'o')
		return (ft_utoa((unsigned short)va_arg(args, int), 8));
	if (f->specifier == 'u')
		return (ft_utoa((unsigned short)va_arg(args, int), 10));
	if (f->specifier == 'x')
		return (ft_utoa((unsigned short)va_arg(args, int), 16));
	if (f->specifier == 'X')
		return (ft_capitalize(ft_utoa((unsigned short)va_arg(args, int), 16)));
	return (NULL);
}

char	*format_long(t_f *f, va_list args)
{
	if (f->specifier == 'd' || f->specifier == 'i')
		return (ft_itoa(va_arg(args, long), 10));
	if (f->specifier == 'o')
		return (ft_utoa(va_arg(args, unsigned long), 8));
	if (f->specifier == 'u')
		return (ft_utoa(va_arg(args, unsigned long), 10));
	if (f->specifier == 'x')
		return (ft_utoa(va_arg(args, unsigned long), 16));
	if (f->specifier == 'X')
		return (ft_capitalize(ft_utoa(va_arg(args, unsigned long), 16)));
	return (NULL);
}

char	*format_longlong(t_f *f, va_list args)
{
	if (f->specifier == 'd' || f->specifier == 'i')
		return (ft_itoa(va_arg(args, long long), 10));
	if (f->specifier == 'o')
		return (ft_utoa(va_arg(args, unsigned long long), 8));
	if (f->specifier == 'u')
		return (ft_utoa(va_arg(args, unsigned long long), 10));
	if (f->specifier == 'x')
		return (ft_utoa(va_arg(args, unsigned long long), 16));
	if (f->specifier == 'X')
		return (ft_capitalize(ft_utoa(va_arg(args, unsigned long long), 16)));
	return (NULL);
}

char	*format_z(t_f *f, va_list args)
{
	if (f->specifier == 'd' || f->specifier == 'i')
		return (ft_itoa(va_arg(args, ssize_t), 10));
	if (f->specifier == 'o')
		return (ft_utoa(va_arg(args, size_t), 8));
	if (f->specifier == 'u')
		return (ft_utoa(va_arg(args, size_t), 10));
	if (f->specifier == 'x')
		return (ft_utoa(va_arg(args, size_t), 16));
	if (f->specifier == 'X')
		return (ft_capitalize(ft_utoa(va_arg(args, size_t), 16)));
	return (NULL);
}
