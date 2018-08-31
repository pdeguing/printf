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

void	width_format(char **format, t_flags *flags)
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
	int	len;

	format = (char **)malloc(sizeof(char *));
	if (!format)
		return (-1);
	if (!(*format = init_format(flags, args)))
		return (-1);
	if (ft_strlen(*format) < flags->minimal_width)
		width_format(format, flags);
	len = ft_strlen(*format);
	ft_putstr(*format);
	ft_strdel(format);
	return (len);
}
