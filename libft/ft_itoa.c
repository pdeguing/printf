/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:26:51 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/12 12:37:05 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int64_t n, int base)
{
	int		size;
	int64_t	reminder;
	char	*str;
	int		sign;

	if (n == 0)
		return (ft_strdup("0"));
	size = ft_intlen(n, base) + 1;
	sign = (n < 0) ? -1 : 1;
	if (n >= 0)
		size--;
	if (!(str = ft_strnew(size)))
		return (NULL);
	str[size--] = '\0';
	while (n != 0 && size >= 0)
	{
		reminder = (n % base) * sign;
		str[size--] = (reminder > 9) ? (reminder - 10) + 'a' : reminder + '0';
		n /= base;
	}
	if (sign < 0)
		str[size] = '-';
	return (str);
}
