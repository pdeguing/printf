/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 16:43:47 by pdeguing          #+#    #+#             */
/*   Updated: 2018/08/21 17:11:19 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_hexa(int n)
{
	int		char_count;

	char_count = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 16)
		char_count += put_octal(n / 16);
	if ((n % 16) == 10)
		ft_putchar('a');
	if ((n % 16) == 11)
		ft_putchar('b');
	if ((n % 16) == 12)
		ft_putchar('c');
	if ((n % 16) == 13)
		ft_putchar('d');
	if ((n % 16) == 14)
		ft_putchar('e');
	if ((n % 16) == 15)
		ft_putchar('f');
	else if ((n % 16) <= 9)
		ft_putchar((n % 16) + '0');
	return (char_count);
}
