#include "ft_printf.h"

/*
** Creating the structure to hold flags informations
*/

t_flags		*flags_new()
{
	t_flags	*new;

	new = (t_flags *)malloc(sizeof(t_flags));
	if (!new)
		return (NULL);
	new->hash = 0;
	new->zero = 0;
	new->dash = 0;
	new->plus = 0;
	new->space = 0;
	new->minimal_width = 0;
	new->precision = 0;
	new->modifier = 0;
	new->specifier = 0;
	new->error = 0;
	return (new);
}

/*
** Setting bolean for each present flag
*/

void		flags_set(t_flags *flags, int *i, const char *format)
{

	while (ft_strchr("#0-+ ", format[*i]))
	{
		if (format[*i] == '#')
			flags->hash = 1;
		if (format[*i] == '0')
			flags->zero = 1;
		if (format[*i] == '-')
			flags->dash = 1;
		if (format[*i] == '+')
			flags->plus = 1;
		if (format[*i] == ' ')
			flags->space = 1;
		*i = *i + 1;
	}
}

/*
** Setting modifier as the sum of specified options
*/

void		flags_modifier(t_flags *flags, int *i, const char *format)
{
	if (ft_strchr("hljz", format[*i]))
	{
		flags->modifier = format[*i];
		*i = *i + 1;
		if (ft_strchr("hljz", format[*i]))
		{
			flags->modifier += format[*i];
			*i = *i + 1;
		}
	}

}

/*
** Storing specifier and adjusting modifier if necessary
*/

void		flags_specifier(t_flags *flags, int *i, const char *format)
{
	if (ft_strchr("SDOUC", format[*i]))
		flags->modifier = 'l';
	if (!ft_strchr("sSpdDioOuUxXcC%", format[*i]))
		flags->error = 1;
	flags->specifier = format[*i];
	if (ft_strchr("SDOUC", format[*i]))
		flags->specifier = ft_tolower(format[*i]);
	if (flags->modifier == 'h' + 'h')
		flags->specifier = 'c';
	*i = *i + 1;
}

/*
** Filling the structure with flags informations
*/

void		flags_init(t_flags *flags, int *i, const char *format)
{
	flags_set(flags, i, format);
	if (ft_isdigit(format[*i]))
	{
		flags->minimal_width = ft_atoi(&format[*i]);
		while (ft_isdigit(format[*i]))
			*i = *i + 1;
	}
	if (format[*i] == '.')
	{
		*i = *i + 1;
		flags->precision = ft_atoi(&format[*i]);
		while (ft_isdigit(format[*i]))
			*i = *i + 1;
	}
	flags_modifier(flags, i, format);
	flags_specifier(flags, i, format);
}
