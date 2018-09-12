#include "ft_printf.h"

char	*format_s(t_flags *flags, va_list args)
{
	char	*format;
	void	*arg;

	if (!(arg = va_arg(args, void *)))
		format = ft_strdup("(null)");
	else if (flags->modifier == 'l')
		format = get_utf_str((wchar_t *)arg); 
	else
		format = ft_strdup((char *)arg);
	if (flags->precision >= 0 && flags->precision < ft_strlen(format))
		ft_strclr(&format[flags->precision]);
	flags->precision = 0;
	return (format);	
}
