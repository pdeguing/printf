/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:11:50 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/13 14:14:35 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_int(t_f *f, va_list args)
{
	if (f->modifier == 'h' + 'h')
		return (format_hh(f, args));
	if (f->modifier == 'h')
		return (format_short(f, args));
	if (f->modifier == 'l' || f->modifier == 'j')
		return (format_long(f, args));
	if (f->modifier == 'l' + 'l')
		return (format_longlong(f, args));
	if (f->modifier == 'z')
		return (format_z(f, args));
	if (f->specifier == 'd' || f->specifier == 'i')
		return (ft_itoa(va_arg(args, int), 10));
	if (f->specifier == 'o')
		return (ft_utoa(va_arg(args, unsigned int), 8));
	if (f->specifier == 'u')
		return (ft_utoa(va_arg(args, unsigned int), 10));
	if (f->specifier == 'x')
		return (ft_utoa(va_arg(args, unsigned int), 16));
	if (f->specifier == 'X')
		return (ft_capitalize(ft_utoa(va_arg(args, unsigned int), 16)));
	return (NULL);
}
