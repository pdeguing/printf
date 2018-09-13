/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:11:26 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/13 13:58:33 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Creating the structure to hold f informations
*/

t_f		*f_new(void)
{
	t_f	*new;

	new = (t_f *)malloc(sizeof(t_f));
	if (!new)
		return (NULL);
	new->hash = 0;
	new->zero = 0;
	new->dash = 0;
	new->sign = 0;
	new->neg = 0;
	new->space = 0;
	new->minimal_width = 0;
	new->precision = -1;
	new->modifier = 0;
	new->specifier = 0;
	new->null = 0;
	new->error = 0;
	return (new);
}

int		init_conversion(int *i, const char *format, va_list args)
{
	t_f		*f;
	int		ret;

	f = f_new();
	if (!f)
		return (0);
	flags_init(f, i, format);
	if (f->error == 1)
	{
		free(f);
		f = NULL;
		return (0);
	}
	ret = get_conversion(f, args);
	free(f);
	f = NULL;
	return (ret);
}
