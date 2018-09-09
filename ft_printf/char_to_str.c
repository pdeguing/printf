#include "ft_printf.h"

char	*char_to_str(char c)
{
	char	*str;

	if (!(str = ft_strnew(1)))
		return (NULL);
	ft_memset(str, c, 1);
	return (str);
}
