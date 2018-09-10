#include "ft_printf.h"

char	*format_c(t_flags *flags, va_list args)
{
	if (flags->modifier == 'l')
		return(get_utf_char(va_arg(args, wchar_t)));
	else
		return (char_to_str(va_arg(args, int)));
}
