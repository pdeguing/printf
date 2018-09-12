/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 10:01:17 by pdeguing          #+#    #+#             */
/*   Updated: 2018/07/20 09:36:47 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*new;

	i = 0;
	k = ft_strlen(s) - 1;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (s[i] == '\0')
		return (new = ft_strdup(""));
	while (k > 0 && (s[k] == ' ' || s[k] == '\n' || s[k] == '\t'))
		k--;
	if (!(new = (char *)malloc(sizeof(char) * (k - i + 2))))
		return (NULL);
	new[k - i + 1] = '\0';
	j = 0;
	k = k - i + 1;
	while (j < k && s[i])
	{
		new[j] = s[i];
		i++;
		j++;
	}
	return (new);
}
