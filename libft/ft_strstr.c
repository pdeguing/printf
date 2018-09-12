/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:13:16 by pdeguing          #+#    #+#             */
/*   Updated: 2018/07/20 09:29:10 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int k;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	i = 0;
	k = 0;
	while (haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			k = i;
			while (needle[j] && haystack[i++] == needle[j])
			{
				j++;
			}
			if (needle[j] == '\0')
				return ((char *)haystack + k);
			i = k;
		}
		i++;
	}
	return (NULL);
}
