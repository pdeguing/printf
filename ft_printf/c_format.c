#include "ft_printf.h"

char	*format_c(t_flags *flags, va_list args)
{
	int	c;
	
	c = va_arg(args, int);
	if (!c || c == 0)
	{
		flags->null = 1;
		return (ft_strnew(1));
	}
	if (flags->modifier == 'l')
		return(get_utf_char((wchar_t)c));
	else
		return (char_to_str(c));
}
