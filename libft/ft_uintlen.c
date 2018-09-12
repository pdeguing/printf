#include "libft.h"

int	ft_uintlen(unsigned long long n, int base)
{
	int	i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}
