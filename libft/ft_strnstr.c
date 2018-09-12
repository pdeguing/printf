/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:47:24 by pdeguing          #+#    #+#             */
/*   Updated: 2018/07/20 10:27:09 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	int	i;
	int	j;
	int	k;

	if (!ft_strlen(small))
		return ((char *)big);
	i = -1;
	k = 0;
	while (big[++i] && i < (int)len)
	{
		j = 0;
		if (big[i] == small[j])
		{
			k = i;
			while (small[j] && big[i] == small[j] && i < (int)len)
			{
				i++;
				j++;
			}
			if (small[j] == '\0')
				return ((char *)big + k);
			i = k;
		}
	}
	return (NULL);
}
