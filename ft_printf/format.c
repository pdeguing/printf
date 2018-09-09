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

/*
** Getting the initial version of the format after conversion of the argument
*/

char	*init_format(t_flags *flags, va_list args)
{
	if (flags->specifier == '%')
	{
		flags->space = 0;
		return (char_to_str('%'));
	}
	if (flags->specifier == 's')
		return (format_s(flags, args));
	if (flags->specifier == 'c')
		return (format_c(flags, args));
	if (ft_strchr("diouxX", flags->specifier))
		return (format_int(flags, args));
	if (flags->specifier == 'p')
		return (ft_utoa((u_int64_t)va_arg(args, void *), 16));
	return (NULL);
}

/*
** Formatting considering all specified options and printing the final format
*/

int	print_format(t_flags *flags, va_list args)
{
	char	**format;
	int	len;

	format = (char **)malloc(sizeof(char *));
	if (!format)
		return (-1);
	if (!(*format = init_format(flags, args)))
		return (-1);
	if (ft_strlen(*format) < flags->precision)
		precision_format(flags, format);
	if (flags->plus == 1 && !ft_strchr(*format, '-'))
		*format = ft_strfljoin("+", *format);
	if (flags->space == 1)
		*format = ft_strfljoin(" ", *format);
	if (flags->hash == 1 || flags->specifier == 'p')
		hash_format(flags, format);
	if (ft_strlen(*format) < flags->minimal_width)
		width_format(flags, format);
	len = ft_strlen(*format);
	ft_putstr(*format);
	ft_strdel(format);
	return (len);
}
