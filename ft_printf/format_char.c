/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:11:39 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/13 14:12:53 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_char(t_f *f, va_list args)
{
	int	c;

	if (f->specifier == '%')
	{
		f->space = 0;
		return (ft_ctostr('%'));
	}
	c = va_arg(args, int);
	if (!c || c == 0)
	{
		f->null = 1;
		return (ft_strnew(1));
	}
	if (f->modifier == 'l')
		return (ft_ctostr((wchar_t)c));
	else
		return (ft_ctostr(c));
}
