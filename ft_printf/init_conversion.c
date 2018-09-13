/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:11:26 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/13 11:30:41 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Creating the structure to hold flags informations
*/

t_flags		*flags_new(void)
{
	t_flags	*new;

	new = (t_flags *)malloc(sizeof(t_flags));
	if (!new)
		return (NULL);
	new->hash = 0;
	new->zero = 0;
	new->dash = 0;
	new->sign = 0;
	new->negative = 0;
	new->space = 0;
	new->minimal_width = 0;
	new->precision = -1;
	new->modifier = 0;
	new->specifier = 0;
	new->null = 0;
	new->error = 0;
	return (new);
}

int	init_conversion(int *i, const char *format, va_list args)
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
	ret = get_conversion(flags, args);
	free(flags);
	flags = NULL;
	return (ret);
}
