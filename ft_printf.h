/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 17:30:59 by pdeguing          #+#    #+#             */
/*   Updated: 2018/08/28 14:18:43 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

/*
** Using a structure seems more efficient than nesting a lot of if statements
** to handle the flags. It allows to check the flags only when they are
** relevant for formating.
*/

typedef struct		s_flags
{
	char		flag;
	int		minimal_width;
	int		precision;
	int		modifier;
	char		specifier;
}			t_flags;

t_flags			*flags_new(void);
void			flags_init(t_flags *flags, int *i, const char *format);

int			print_format(t_flags *flags, va_list args);

int			start_parsing(int *i, const char *format, va_list args);
int			ft_printf(const char *format, ...);

#endif
