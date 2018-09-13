/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 17:30:59 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/13 11:16:20 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

/*
** Using a structure seems more efficient than nesting a lot of if statements
** to handle the flags. It allows to check the flags only when they are
** relevant for formating.
*/

typedef struct	s_flags
{
	int			hash;
	int			zero;
	int			dash;
	int			sign;
	int			negative;
	int			space;
	int			minimal_width;
	int			precision;
	int			modifier;
	char		specifier;
	int			null;
	int			error;
}				t_flags;

char			*get_utf_char(wchar_t wchar);
char			*get_utf_str(wchar_t *wstr);

char			*format_char(t_flags *flags, va_list args);
char			*format_str(t_flags *flags, va_list args);
char			*format_int(t_flags *flags, va_list args);

t_flags			*flags_new(void);
void			flags_init(t_flags *flags, int *i, const char *format);

int				print_format(t_flags *flags, char **prefix, char **format, char **suffix);
void			format_conversion(t_flags *flags, char **format, char **prefix, char **suffix);
int				get_conversion(t_flags *flags, va_list args);

int				init_conversion(int *i, const char *format, va_list args);
int				ft_printf(const char *format, ...);

#endif
