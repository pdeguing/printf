/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:10:51 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/13 11:14:53 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_hash(t_flags *flags, char **prefix)
{
	char	*affix;

	if (flags->specifier == 'o')
		affix = ft_strdup("0");
	else if (flags->specifier == 'x' || flags->specifier == 'p')
		affix = ft_strdup("0x");
	else if (flags->specifier == 'X')
		affix = ft_strdup("0X");
	else
		return ;
	if (!affix)
		return ;
	*prefix = ft_strfjoin(affix, *prefix);
}

void	format_precision(t_flags *flags, int len, char **prefix)
{
	char	*affix;
	int		size;

	size = flags->precision - len;
	if (!(affix = ft_strnew(size)))
		return ;
	ft_memset(affix, '0', size);
	*prefix = ft_strfjoin(affix, *prefix);
	flags->zero = 0;
}

void	format_width(t_flags *flags, int len, char **prefix, char **suffix)
{
	char	*affix;
	int		size;

	size = flags->minimal_width - len;
	if (flags->hash == 1 && flags->zero == 1)
		size -= 2;
	if ((flags->sign == 1 || flags->negative == 1) && flags->zero == 1)
		size--;
	if (!(affix = ft_strnew(size)))
		return ;
	if (flags->zero == 1)
		ft_memset(affix, '0', size);
	else
		ft_memset(affix, ' ', size);
	if (flags->dash == 1)
		*suffix = ft_strfjoin(*suffix, affix);
	else
		*prefix = ft_strfjoin(affix, *prefix);
}

void	format_sign(t_flags *flags, char **prefix)
{
	if (flags->negative == 1)
		*prefix = ft_strfljoin("-", *prefix);
	else if (flags->sign == 1)
		*prefix = ft_strfljoin("+", *prefix);
}

void	format_conversion(t_flags *flags, char **format, char **prefix, char **suffix)
{
	int	len;

	len = ft_strlen(*format);
	if (ft_strchr(*format, '-'))
	{
		flags->negative = 1;
		len--;
	}
	if (flags->null == 1)
		len = 1;
	if (len < flags->precision)
		format_precision(flags, len, prefix);
	if (flags->space == 1 && flags->null == 0 && flags->negative == 0 && flags->sign == 0)
		*prefix = ft_strfljoin(" ", *prefix);
	if ((flags->zero == 0 && flags->hash == 1) || flags->specifier == 'p')
		format_hash(flags, prefix);
	if (flags->zero == 0)
		format_sign(flags, prefix);
	len += ft_strlen(*prefix);
	if (len < flags->minimal_width)
		format_width(flags, len, prefix, suffix);
	if (flags->zero == 1)
		format_sign(flags, prefix);
	if ((flags->zero == 1 && flags->hash == 1))
		format_hash(flags, prefix);
}
