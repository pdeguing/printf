/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 10:48:24 by pdeguing          #+#    #+#             */
/*   Updated: 2018/08/29 13:16:31 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		sort_specifier(int *i, const char *format, va_list arguments)
{
	if (format[*i] == '%')
	{
		ft_putchar('%');
		return (1);
	}
	if (format[*i] == 'd' || format[*i] == 'i')
	{
		return (ft_putnbr(va_arg(arguments, int)));
	}
	if (format[*i] == 's')
	{
		return (ft_putstr(va_arg(arguments, char *)));
	}
	if (format[*i] == 'c')
	{
		ft_putchar(va_arg(arguments, int));
		return (1);
	}
	if (format[*i] == 'o')
	{
		return (put_octal(va_arg(arguments, int)));
	}
	if (format[*i] == 'x')
	{
		return (put_hex(va_arg(arguments, int)));
	}
	if (format[*i] == 'X')
	{
		return (put_hexupper(va_arg(arguments, int)));
	}
	if (format[*i] == 'S')
	{
		// s with l modifier
	}
	if (format[*i] == 'p')
	{
		// void *pointer arg printed in hex as %#x
	}
	if (format[*i] == 'D')
	{
		// long to signed decimal
	}
	if (format[*i] == 'O')
	{
		// long to unsigned octal
	}
	if (format[*i] == 'u')
	{
		// unsigned base 10
	}
	if (format[*i] == 'U')
	{
		// long to unsigned decimal
	}
	if (format[*i] == 'C')
	{
		// c with l modifier
	}
	return (-1);
}


int		get_specifier(int *i, const char *format, va_list arguments)
{
	int		char_count;

	char_count = 0;
	if (!format[*i])
		return (-1);
	else
		char_count = sort_specifier(i, format, arguments);
	*i = *i + 1;
	return (char_count);
}
