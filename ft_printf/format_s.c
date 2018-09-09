#include "ft_printf.h"

char	*format_s(t_flags *flags, va_list args)
{
	if (flags->modifier == 'l')
		return (get_utf_str(va_arg(args, wchar_t *))); // CREATE GET_UTF_STR
	return (ft_strdup(va_arg(args, char *)));
}
