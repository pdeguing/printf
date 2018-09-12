/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:30:32 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/12 12:30:47 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned long long n, int base)
{
	int					size;
	unsigned long long	reminder;
	char				*str;

	if (n == 0)
		return (ft_strdup("0"));
	size = ft_uintlen(n, base);
	if (!(str = ft_strnew(size)))
		return (NULL);
	str[size] = '\0';
	while (n != 0 && --size >= 0)
	{
		reminder = n % base;
		str[size] = (reminder > 9) ? (reminder - 10) + 'a' : reminder + '0';
		n /= base;
	}
	return (str);
}
