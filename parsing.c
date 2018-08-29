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

int 	get_width(int *i, const char *format)
{
	char	*tmp;
	int		j;

	j = *i;
	while (ft_isnum(format[*i]))
		*i = *i + 1;
	tmp = ft_strsub(format, j, *i - j);
	return (ft_atoi(tmp));
}

int		start_parsing(int *i, const char *format, va_list arguments)
{
	if (ft_strchr("#0-+", format[*i]))
	{
		// KEEP TRACK OF THE FLAGS TO USE BEFORE PRINTING
	}
	if (ft_isnum(format[*i]))
	{
		// DETERMINE THE MINIMAL WIDTH OF THE FIELD TO PRINT
		// get_width(i, format);
	}
	if (format[*i] == ".")
	{
		// KEEP TRACK OF THE PRECISION TO USE BEFORE PRINTING 
	}
	if (ft_strchr("hljz", format[*i]))
	{
		// KEEP TRACK OF THE MODIFIER TO USE FOR CONVERSION 
	}
	// KEEP TRACK OF THE TYPE OF DATA TO PRINT
	return (char_count);
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
