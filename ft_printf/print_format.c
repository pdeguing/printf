/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 10:24:49 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/13 10:49:12 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** This function takes the initial argument format after conversion as input.
** Instead of creating a buffer to print, it will print each prefix/suffix
** and the format in a different order depending on the flags.
**
** Returns the number of characters printed.
**
** We adopt this method as it makes the printing of NULL characters easier and
** should accelerate drastically the speed of the function as we will reduce
** memory allocation and freeing.
**
** We will create a bunch of strings as affix and print them.
** If character is 0 we will print '\0' instead of format.
*/

int	print_format(t_flags *flags, char **prefix, char **format, char **suffix)
{
	int	printed;

	ft_putstr(*prefix);
	printed = ft_strlen(*prefix);
	if (flags->null == 1 && flags->specifier == 'c')
	{
		ft_putchar(0);
		printed++;
	}
	else
	{
		if (flags->negative == 1 || (flags->sign == 1 && flags->negative == 1))
		{
			ft_putstr(*format + 1);
			printed--;
		}
		else
			ft_putstr(*format);
		printed += ft_strlen(*format);
	}
	ft_putstr(*suffix);
	printed += ft_strlen(*suffix);
	ft_strdel(prefix);
	ft_strdel(format);
	ft_strdel(suffix);
	return (printed);
}
