#include "ft_printf.h"

/*
** Getting the initial version of the format after conversion of the argument
*/

char	*init_format(t_flags *flags, va_list args)
{
	char	*format;

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
	{
		format = format_int(flags, args);
		if (flags->precision == 0 && *format == '0')
		{
			ft_strdel(&format);
			format = ft_strnew(1);
			if (flags->specifier != 'o')
				flags->hash = 0;
		}
		if (*format == '0' && ft_strlen(format) <= 1)
			flags->hash = 0;
		return (format);
	}
	if (flags->specifier == 'p')
		return (ft_utoa((u_int64_t)va_arg(args, void *), 16));
	return (NULL);
}

/*
** Formatting considering all specified options and printing the final format
*/

int	start_format(t_flags *flags, va_list args)
{
	char	**format;
	char	**prefix;
	char	**suffix;
	int		ret;

	if (!(format = (char **)malloc(sizeof(char *))))
		return (-1);
	*format = init_format(flags, args);
//	if (!**format)
//		*format = ft_strnew(1); // POTENTIAL LEAKS TO CHECK
	if (!(prefix = (char **)malloc(sizeof(char *))))
		return (-1);
	*prefix = ft_strnew(1);
	if (!(suffix = (char **)malloc(sizeof(char *))))
		return (-1);
	*suffix = ft_strnew(1);
	format_print(flags, format, prefix, suffix);
	ret = print_format(flags, prefix, format, suffix);
	free(format);
	free(prefix);
	free(suffix);
	return (ret);
}

// NEED TO CHANGE EVERYTHING TO NOT RETURN THE FORMAT BUT TO ACTUALLY PRINT IT WITH A DIFFERENT ORDER DEPENDING ON THE FLAGS
