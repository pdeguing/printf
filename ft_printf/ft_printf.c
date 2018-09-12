/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 19:09:41 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/12 11:31:48 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	args_list;
	int		char_count;
	int		ret;
	int		i;

	va_start(args_list, format);
	i = 0;
	char_count = 0;
	ret = 0;
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
			if ((ret = start_parsing(&i, format, args_list)) == -1)
				return (char_count);
			else 
				char_count += ret;
		}
	}
	va_end(args_list);
	return (char_count);
}
