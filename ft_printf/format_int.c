#include "ft_printf.h"

char	*format_short(t_flags *flags, va_list args)
{
	if (flags->specifier == 'd' || flags->specifier == 'i')
		return (ft_itoa((short)va_arg(args, int), 10));
	if (flags->specifier == 'o')
		return (ft_utoa((short)va_arg(args, int), 8));
	if (flags->specifier == 'u')
		return (ft_utoa((short)va_arg(args, int), 10));
	if (flags->specifier == 'x')
		return (ft_utoa((short)va_arg(args, int), 16));
	if (flags->specifier == 'X')
		return (ft_capitalize(ft_utoa((short)va_arg(args, int), 16)));
	return (NULL);
}


char	*format_long(t_flags *flags, va_list args)
{
	if (flags->specifier == 'd' || flags->specifier == 'i')
		return (ft_itoa(va_arg(args, long), 10));
	if (flags->specifier == 'o')
		return (ft_utoa(va_arg(args, unsigned long), 8));
	if (flags->specifier == 'u')
		return (ft_utoa(va_arg(args, unsigned long), 10));
	if (flags->specifier == 'x')
		return (ft_utoa(va_arg(args, unsigned long), 16));
	if (flags->specifier == 'X')
		return (ft_capitalize(ft_utoa(va_arg(args, unsigned long), 16)));
	return (NULL);
}

char	*format_longlong(t_flags *flags, va_list args)
{
	if (flags->specifier == 'd' || flags->specifier == 'i')
		return (ft_itoa(va_arg(args, long long), 10));
	if (flags->specifier == 'o')
		return (ft_utoa(va_arg(args, unsigned long long), 8));
	if (flags->specifier == 'u')
		return (ft_utoa(va_arg(args, unsigned long long), 10));
	if (flags->specifier == 'x')
		return (ft_utoa(va_arg(args, unsigned long long), 16));
	if (flags->specifier == 'X')
		return (ft_capitalize(ft_utoa(va_arg(args, unsigned long long), 16)));
	return (NULL);
}

char	*format_z(t_flags *flags, va_list args)
{
	if (flags->specifier == 'd' || flags->specifier == 'i')
		return (ft_itoa(va_arg(args, ssize_t), 10));
	if (flags->specifier == 'o')
		return (ft_utoa(va_arg(args, size_t), 8));
	if (flags->specifier == 'u')
		return (ft_utoa(va_arg(args, size_t), 10));
	if (flags->specifier == 'x')
		return (ft_utoa(va_arg(args, size_t), 16));
	if (flags->specifier == 'X')
		return (ft_capitalize(ft_utoa(va_arg(args, size_t), 16)));
	return (NULL);
}


char	*format_int(t_flags *flags, va_list args)
{
	if (flags->modifier == 'h')
		return (format_short(flags, args));
	if (flags->modifier == 'l')
		return (format_long(flags, args));
	if (flags->modifier == 'l' + 'l')
		return (format_longlong(flags, args));
	if (flags->modifier == 'z')
		return (format_z(flags, args));
	if (flags->specifier == 'd' || flags->specifier == 'i')
		return (ft_itoa(va_arg(args, int), 10));
	if (flags->specifier == 'o')
		return (ft_utoa((unsigned int)va_arg(args, int), 8));
	if (flags->specifier == 'u')
		return (ft_utoa((unsigned int)va_arg(args, int), 10));
	if (flags->specifier == 'x')
		return (ft_utoa((unsigned int)va_arg(args, int), 16));
	if (flags->specifier == 'X')
		return (ft_capitalize(ft_utoa((unsigned int)va_arg(args, int), 16)));
	return (NULL);
}
