/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:10:51 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/13 11:57:18 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_hash(t_f *f, char **prefix)
{
	char	*affix;

	if (f->specifier == 'o')
		affix = ft_strdup("0");
	else if (f->specifier == 'x' || f->specifier == 'p')
		affix = ft_strdup("0x");
	else if (f->specifier == 'X')
		affix = ft_strdup("0X");
	else
		return ;
	if (!affix)
		return ;
	*prefix = ft_strfjoin(affix, *prefix);
}

void	format_precision(t_f *f, int len, char **prefix)
{
	char	*affix;
	int		size;

	size = f->precision - len;
	if (!(affix = ft_strnew(size)))
		return ;
	ft_memset(affix, '0', size);
	*prefix = ft_strfjoin(affix, *prefix);
	f->zero = 0;
}

void	format_width(t_f *f, int len, char **prefix, char **suffix)
{
	char	*affix;
	int		size;

	size = f->minimal_width - len;
	if (f->hash == 1 && f->zero == 1)
		size -= 2;
	if ((f->sign == 1 || f->neg == 1) && f->zero == 1)
		size--;
	if (!(affix = ft_strnew(size)))
		return ;
	if (f->zero == 1)
		ft_memset(affix, '0', size);
	else
		ft_memset(affix, ' ', size);
	if (f->dash == 1)
		*suffix = ft_strfjoin(*suffix, affix);
	else
		*prefix = ft_strfjoin(affix, *prefix);
}

void	format_sign(t_f *f, char **prefix)
{
	if (f->neg == 1)
		*prefix = ft_strfljoin("-", *prefix);
	else if (f->sign == 1)
		*prefix = ft_strfljoin("+", *prefix);
}

void	format_conversion(t_f *f, char **fmt, char **pref, char **suf)
{
	int	len;

	len = ft_strlen(*fmt);
	if (ft_strchr(*fmt, '-'))
	{
		f->neg = 1;
		len--;
	}
	if (f->null == 1)
		len = 1;
	if (len < f->precision)
		format_precision(f, len, pref);
	if (f->space == 1 && f->null == 0 && f->neg == 0 && f->sign == 0)
		*pref = ft_strfljoin(" ", *pref);
	if ((f->zero == 0 && f->hash == 1) || f->specifier == 'p')
		format_hash(f, pref);
	if (f->zero == 0)
		format_sign(f, pref);
	len += ft_strlen(*pref);
	if (len < f->minimal_width)
		format_width(f, len, pref, suf);
	if (f->zero == 1)
		format_sign(f, pref);
	if ((f->zero == 1 && f->hash == 1))
		format_hash(f, pref);
}
