/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 10:39:41 by pdeguing          #+#    #+#             */
/*   Updated: 2018/07/19 18:25:14 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**t;

	i = 0;
	j = 0;
	if (!(t = (char **)malloc(sizeof(char*) * (ft_wrdc((char *)s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] == '\0')
			break ;
		if (!(t[j] = (char *)malloc(sizeof(char) *
						(ft_wrdlen((char *)&s[i], c) + 1))))
			return (NULL);
		k = 0;
		while (s[i] != c && s[i])
			t[j][k++] = s[i++];
		t[j++][k] = '\0';
	}
	t[j] = NULL;
	return (t);
}
