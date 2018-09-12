/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:29:28 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/12 11:51:20 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	start_parsing(int *i, const char *format, va_list args)
{
	t_flags		*flags;
	int			ret;

	flags = flags_new();
	if (!flags)
		return (-1);
	flags_init(flags, i, format);
	if (flags->error == 1)
	{
		free(flags);
		flags = NULL;
		return (-1);
	}
	ret = start_format(flags, args);
	free(flags);
	flags = NULL;
	return (ret);
}
