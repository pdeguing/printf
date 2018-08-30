#include "ft_printf.h"

t_flags		*flags_new()
{
	t_flags	*new;

	new = (t_flags *)malloc(sizeof(t_flags));
	if (!new)
		return (NULL);
	new->flag = 0;
	new->minimal_width = 0;
	new->precision = 0;
	new->modifier = 0;
	new->specifier = 0;
	return (new);
}

void		flags_init(t_flags *flags, int *i, const char *format)
{
	if (ft_strchr("#0-+", format[*i]))
	{
		flags->flag = format[*i];
		*i = *i + 1;
	}
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
	/*
	if (!ft_strchr("sSpdDioOuUxXcC%", format[*i])
		return (NULL);
	*/
	flags->specifier = format[*i];
	*i = *i + 1;
}
