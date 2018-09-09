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
		return (ft_itoa((long)va_arg(args, int), 10));
	if (flags->specifier == 'o')
		return (ft_utoa((long)va_arg(args, int), 8));
	if (flags->specifier == 'u')
		return (ft_utoa((long)va_arg(args, int), 10));
	if (flags->specifier == 'x')
		return (ft_utoa((long)va_arg(args, int), 16));
	if (flags->specifier == 'X')
		return (ft_capitalize(ft_utoa((long)va_arg(args, int), 16)));
	return (NULL);
}

char	*format_longlong(t_flags *flags, va_list args)
{
	if (flags->specifier == 'd' || flags->specifier == 'i')
		return (ft_itoa((long long)va_arg(args, int), 10));
	if (flags->specifier == 'o')
		return (ft_utoa((long long)va_arg(args, int), 8));
	if (flags->specifier == 'u')
		return (ft_utoa((long long)va_arg(args, int), 10));
	if (flags->specifier == 'x')
		return (ft_utoa((long long)va_arg(args, int), 16));
	if (flags->specifier == 'X')
		return (ft_capitalize(ft_utoa((long long)va_arg(args, int), 16)));
	return (NULL);
}

char	*format_z(t_flags *flags, va_list args)
{
	if (flags->specifier == 'd' || flags->specifier == 'i')
		return (ft_itoa((size_t)va_arg(args, int), 10));
	if (flags->specifier == 'o')
		return (ft_utoa((size_t)va_arg(args, int), 8));
	if (flags->specifier == 'u')
		return (ft_utoa((size_t)va_arg(args, int), 10));
	if (flags->specifier == 'x')
		return (ft_utoa((size_t)va_arg(args, int), 16));
	if (flags->specifier == 'X')
		return (ft_capitalize(ft_utoa((size_t)va_arg(args, int), 16)));
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
