#include "ft_printf.h"

void	hash_format(t_flags *flags, char **format)
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
	*format = ft_strfjoin(affix, *format);
}

void	precision_format(t_flags *flags, char **format)
{
	char	*affix;
	int	size;

	size = flags->precision - ft_strlen(*format);
	if (!(affix = ft_strnew(size)))
		return ;
	ft_memset(affix, '0', size);
	*format = ft_strfjoin(affix, *format);
}

void	width_format(t_flags *flags, char **format)
{
	char	*affix;
	int	size;

	size = flags->minimal_width - ft_strlen(*format);
	if (flags->hash == 1 && flags->zero == 1)
		size -= 2;
	if(!(affix = ft_strnew(size)))
		return ;
	if (flags->zero == 1)
		ft_memset(affix, '0', size);
	else
		ft_memset(affix, ' ', size);
	if (flags->dash == 1)
		*format = ft_strfjoin(*format, affix);
	else
		*format = ft_strfjoin(affix, *format);
}

void	master_format(t_flags *flags, char **format)
{
	if (!**format)
		*format = ft_strnew(1);
	if (ft_strlen(*format) < flags->precision)
		precision_format(flags, format);
	if (flags->plus == 1 && !ft_strchr(*format, '-'))
		*format = ft_strfljoin("+", *format);
	if (flags->space == 1)
		*format = ft_strfljoin(" ", *format);
	if ((flags->zero == 0 && flags->hash == 1) || flags->specifier == 'p')
		hash_format(flags, format);
	if (ft_strlen(*format) < flags->minimal_width)
		width_format(flags, format);
	if ((flags->zero == 1 && flags->hash == 1) || flags->specifier == 'p')
		hash_format(flags, format);

}
