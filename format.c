#include "ft_printf.h"

/*
1. TRANSFORM ARGUMENT INTO A PRELIMINARY STRING FORMAT
	-> a. DISPATCH DEPENDING ON SPECIFIER AND MODIFIER
	-> b. CREATE PROPER STRING IN EACH CASE
	-> c. IF # THEN ALTER THE STRING
2. IF MINIMAL_WIDTH > STRLEN PRELIMINARY STRING THEN ALTER FORMAT
	-> a. SET PREFIX OR SET SUFFIX (IF - FLAG)
3. THEN PRINT FORMAT 

WE WILL APPLY PRECISION THE SAME WAY AS THE WIDTH UNTIL WE DECIDE 
TO IMPLEMENT THE FLOAT TYPE AS IT SEEMS TO BE NOT WORTH THE PAIN FOR
NOW
*/

void	hash_format(t_flags *flags, char **format) // NEED TO CHECK FOR ZERO
{
	char	*affix;
	char	*tmp;

	if (flags->specifier == 'o')
		affix = ft_strdup("0");
	else if (flags->specifier == 'x')
		affix = ft_strdup("0x");
	else if (flags->specifier == 'X')
		affix = ft_strdup("0X");
	else
		return ;
	if (!affix)
		return ;
	tmp = *format;
	*format = ft_strjoin(affix, *format);
	ft_strdel(&tmp);
}

void	precision_format(t_flags *flags, char **format)
{
	char	*affix;
	char	*tmp;
	int	size;

	size = flags->precision - ft_strlen(*format);
	if (!(affix = ft_strnew(size)))
		return ;
	ft_memset(affix, '0', size);
	tmp = *format;
	*format = ft_strjoin(affix, *format);
	ft_strdel(&tmp);
	ft_strdel(&affix);
}

void	width_format(t_flags *flags, char **format)
{
	char	*affix;
	char	*tmp;
	int	size;

	size = flags->minimal_width - ft_strlen(*format);
	if(!(affix = ft_strnew(size)))
		return ;
	if (flags->zero == 1)
		ft_memset(affix, '0', size);
	else
		ft_memset(affix, ' ', size);
	tmp = *format;
	if (flags->dash == 1)
		*format = ft_strjoin(*format, affix);
	else
		*format = ft_strjoin(affix, *format);
	ft_strdel(&tmp);
	ft_strdel(&affix);
}

char	*init_format(t_flags *flags, va_list args)
{
//	if (flags->specifier == '%')
//		return (char_format('%'));
	if (flags->specifier == 'd' || flags->specifier == 'i')
		return (ft_itoa(va_arg(args, int)));
	if (flags->specifier == 's')
		return (ft_strdup(va_arg(args, char *)));
//	if (flags->specifier == 'c')
//		return (char_format(va_arg(args, int)));
//	if (flags->specifier == 'o')
//		return (ft_itoa_base(va_arg(args, int), 8));
//	if (flags->specifier == 'u')
//		return (ft_itoa_unsigned(va_args(args, int));
//	if (flags->specifier == 'x')
//		return (ft_itoa_base(va_arg(args, int), 16));
//	if (flags->specifier == 'X')
//		return (ft_strtoupper(ft_itoa_base(va_arg(args, int), 16)));
	return (NULL);
}

int	print_format(t_flags *flags, va_list args)
{
	char	**format;
	char	*tmp;
	int	len;

	format = (char **)malloc(sizeof(char *));
	if (!format)
		return (-1);
	if (!(*format = init_format(flags, args)))
		return (-1);
	if (flags->space == 1)
	{
		tmp = *format;
		*format = ft_strjoin(" ", *format); // REPLACE STRJOIN WITH STRJOINFREE EVERYWHERE
		ft_strdel(&tmp);		// IN THIS CASE WE CAN PROBABLY USE CHAR_FORMAT
	}
	if (ft_strlen(*format) < flags->precision)
		precision_format(flags, format);
	if (flags->hash == 1)
		hash_format(flags, format);
	if (ft_strlen(*format) < flags->minimal_width)
		width_format(flags, format);
	len = ft_strlen(*format);
	ft_putstr(*format);
	ft_strdel(format);
	return (len);
}
