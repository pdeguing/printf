/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 14:12:26 by pdeguing          #+#    #+#             */
/*   Updated: 2018/08/21 17:11:16 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		x_conversion(int arg)
{
	return (put_hexa(arg));
}

int		o_conversion(int arg)
{
	return (put_octal(arg));
}

int		c_conversion(int arg)
{
	ft_putchar(arg);
	return (1);
}

int		s_conversion(char *arg)
{
	ft_putstr(arg);
	return (ft_strlen(arg));
}

int		i_conversion(int arg)
{
	ft_putnbr(arg);
	return (ft_intlen(arg));
}

int		d_conversion(int arg)
{
	ft_putnbr(arg);
	return (ft_intlen(arg));
}


int		start_conversion(int *i, const char *format, va_list args_list)
{
	int		char_count;

	char_count = 0;
	*i = *i + 1;
	while (format[*i] && !ft_isalpha(format[*i]))
	{
		if (format[*i] == '%')
		{
			ft_putchar('%');
			char_count++;
			*i = *i + 1;
			break ;
		}
		*i = *i + 1;
	}
	if (format[*i] && format[*i] == 'd')
	{
		char_count += d_conversion(va_arg(args_list, int));
		*i = *i + 1;
	}
	if (format[*i] && format[*i] == 'i')
	{
		char_count += i_conversion(va_arg(args_list, int));
		*i = *i + 1;
	}
	if (format[*i] && format[*i] == 's')
	{
		char_count += s_conversion(va_arg(args_list, char *));
		*i = *i + 1;
	}
	if (format[*i] && format[*i] == 'c')
	{
		char_count += c_conversion(va_arg(args_list, int));
		*i = *i + 1;
	}
	if (format[*i] && format[*i] == 'o')
	{
		char_count += o_conversion(va_arg(args_list, int));
		*i = *i + 1;
	}
	if (format [*i] && format[*i] == 'x')
	{
		char_count += x_conversion(va_arg(args_list, int));
		*i = *i + 1;
	}
	return (char_count);
}
