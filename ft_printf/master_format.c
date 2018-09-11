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
	int	size;

	size = flags->precision - len;
	if (!(affix = ft_strnew(size)))
		return ;
	ft_memset(affix, '0', size);
	*prefix = ft_strfjoin(affix, *prefix);
}

void	format_width(t_flags *flags, int len, char **prefix, char **suffix)
{
	char	*affix;
	int	size;

	size = flags->minimal_width - len;
	if (flags->hash == 1 && flags->zero == 1)
		size -= 2;
	if(!(affix = ft_strnew(size)))
		return ;
	if (flags->zero == 1)
		ft_memset(affix, '0', size);
	else
		ft_memset(affix, ' ', size);
	if (flags->dash == 1)
		*suffix = affix;
	else
		*prefix = ft_strfjoin(affix, *prefix);
}

void	format_print(t_flags *flags, char **format, char **prefix, char **suffix)
{
	int	len;

	len = ft_strlen(*format);
	if (flags->null == 1)
		len = 1;
	if (len < flags->precision)
		format_precision(flags, len, prefix);
	if (flags->plus == 1 && !ft_strchr(*format, '-'))
		*prefix = ft_strfljoin("+", *prefix);
	if (flags->space == 1 && flags->null == 0)
		*prefix = ft_strfljoin(" ", *prefix);
	if ((flags->zero == 0 && flags->hash == 1) || flags->specifier == 'p')
		format_hash(flags, prefix);
	len += ft_strlen(*prefix);
	if (len < flags->minimal_width)
		format_width(flags, len, prefix, suffix);
	if ((flags->zero == 1 && flags->hash == 1) || flags->specifier == 'p')
		format_hash(flags, prefix);
}
