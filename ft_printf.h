/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 17:30:59 by pdeguing          #+#    #+#             */
/*   Updated: 2018/08/21 17:04:00 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

int		put_hexa(int n);
int		put_octal(int n);
int		start_conversion(int *i, const char *format, va_list args_list);

int		ft_printf(const char *format, ...);

#endif
