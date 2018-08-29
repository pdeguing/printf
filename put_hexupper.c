/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hexupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 21:33:27 by pdeguing          #+#    #+#             */
/*   Updated: 2018/08/28 10:26:31 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_hexupper(int n)
{
	static int	char_count = 0;
	int			rest;

	if (n >= 16)
		char_count += put_hexupper(n / 16);
	rest = n % 16;
	if (rest < 10)
		ft_putchar(rest + '0');
	if (rest >= 10)
		ft_putchar(rest + 55);
	char_count++;
	return (char_count);
}
