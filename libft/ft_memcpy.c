/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 09:03:57 by pdeguing          #+#    #+#             */
/*   Updated: 2018/07/20 10:03:23 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*original;
	char	*new;
	size_t	i;

	original = dst;
	new = (char *)src;
	i = 0;
	while (i < n)
	{
		*(original + i) = *(new + i);
		i++;
	}
	return (dst);
}
