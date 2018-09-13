/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:11:59 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/13 12:01:02 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_str(t_f *f, va_list args)
{
	char	*format;
	void	*arg;

	if (!(arg = va_arg(args, void *)))
		format = ft_strdup("(null)");
	else if (f->modifier == 'l')
		format = get_utf_str((wchar_t *)arg);
	else
		format = ft_strdup((char *)arg);
	if (f->precision >= 0 && f->precision < ft_strlen(format))
		ft_strclr(&format[f->precision]);
	f->precision = 0;
	return (format);
}
