/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:29:28 by pdeguing          #+#    #+#             */
/*   Updated: 2018/08/29 13:16:29 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
int	get_minimal_width(t_flags flags)
{
	char	**argument;

	if (flags->precision && flags->precision > flags->minimal_width)
		flags->minimal_width = flags->precision;
	*argument = get_argument(flags, va_list args);
	if (flags->minimal_width > ft_strlen(*argument))
		alter_format(flags, argument);
	ft_putstr(*argument);
	ft_strdel(argument);
	return (flags->minimal_width);
}
*/

int	start_parsing(int *i, const char *format, va_list args)
{
	t_flags		*flags;

	flags = flags_new();
	if (!flags)
		return (-1);
	flags_init(flags, i, format);
	return (start_format(flags, args));
}

// 1. PUT ALL THE DATA IN A STRUCT
// 2. IF FLOAT, KEEP TRACK OF THE WIDTH NEEDED FOR PRECISION AND POINT
// 3. SEND THE STRUCT TO A FUNCTION THAT WILL DETERMINE THE LENGHT TO PRINT
// 4. PREPARE THE STRING TO PRINT DEPENDING ON FLAGS AND MODIFIER
// 5. RETURN AND PRINT THE STRING
// 6. KEEP TRACK OF THE NUMBER OF CHAR PRINTED
//

// IN CASE OF WIDTH, WE JUST NEED TO SET THE FULL FIELD TO ' ' or 0:
// if (ft_strlen(to_print) < width)
//	ft_memset(ft_strnew(width), char, width);
