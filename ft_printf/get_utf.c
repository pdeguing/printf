#include "ft_printf.h"

char	*get_utf_char(wchar_t wchar)
{
	char	*str;

	if (wchar <= 0x7F)
		return (str = char_to_str(wchar)); 
	if (wchar <= 0x7FF)
	{
		if (!(str = ft_strnew(2)))
			return (NULL);
		str[0] = (wchar >> 6) | 0xc0;
		str[1] = (wchar & 0x3F) | 0x80;
		return (str);
	}
	if (wchar <= 0xFFFF)
	{
		if (!(str = ft_strnew(3)))
			return (NULL);
		str[0] = (wchar >> 12) | 0xe0;
		str[1] = (wchar >> 6 & 0x3F) | 0x80;
		str[2] = (wchar & 0x3F) | 0x80;
		return (str);
	}
	if (wchar <= 0x10FFFF)
	{
		if (!(str = ft_strnew(4)))
			return (NULL);
		str[0] = (wchar >> 18) | 0xf0;
		str[1] = (wchar >> 12 & 0x3F) | 0x80;
		str[2] = (wchar >> 6 & 0x3F) | 0x80;
		str[3] = (wchar & 0x3F) | 0x80;
		return (str);
	}
	return (NULL);
}

char	*get_utf_str(wchar_t *wstr)
{
	int	i;
	char	*str;

	i = 0;
	if (!(str = ft_strnew(1)))
		return (NULL);
	while (wstr[i])
	{
		str = ft_strfjoin(str, get_utf_char(wstr[i]));
		i++;
	}
	return (str);
}
