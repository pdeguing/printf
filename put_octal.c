/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_octal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 16:31:26 by pdeguing          #+#    #+#             */
/*   Updated: 2018/08/21 16:43:38 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_octal(int n)
{
	int		char_count;

	char_count = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 8)
		char_count += put_octal(n / 8);
	ft_putchar((n % 8) + '0');
	return (char_count);
}
