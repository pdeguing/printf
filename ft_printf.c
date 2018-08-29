/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 19:09:41 by pdeguing          #+#    #+#             */
/*   Updated: 2018/08/29 13:16:28 by pdeguing         ###   ########.fr       */
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
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			char_count++;
			i++;
		}
		else
		{
			i++;
			char_count += get_specifier(&i, format, args_list);
		}
	}
	va_end(args_list);
	return (char_count);
}
