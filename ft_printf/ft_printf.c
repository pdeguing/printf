/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 19:09:41 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/13 14:30:59 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	args_list;
	int		char_count;
	int		i;

	va_start(args_list, format);
	i = 0;
	char_count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			char_count += init_conversion(&i, format, args_list);
		}
		else if (format[i])
		{
			ft_putchar(format[i]);
			char_count++;
			i++;
		}
	}
	va_end(args_list);
	return (char_count);
}
