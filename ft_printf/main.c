/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 17:32:32 by pdeguing          #+#    #+#             */
/*   Updated: 2018/09/12 12:03:41 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#define TEST1 "test1: %d, %i, %s, %010d, % 10d, %-5d, %0d, %-d, % -5d, %5.3d, %-5.3d, %-5.10d.\n", 42, 42, "world", 42, 42, 42, 42, 42, 42, 42, 42, 42 
#define TEST2 "test2: %o, %u, %x, %X, %+5d, %+d, %+5.3d, %c, %%.\n", 42, 42, -42, -42, 42, 42, 42, 'X'
#define TEST3 "test3: %p, %15p.\n", ptr, ptr
#define TEST4 "test4: %hi, %ls, %lc, %S, %C.\n", 42, str, c, str, c 
/*
REMEMBER TO CHECK CASE WHERE PRINTF DOES NOT COMPILE CAUSE WARNING OR OTHER STRANGE BEHAVIOUR:
	-> %0-5d
	-> % -5d (printf print a space before the number even tho it justifies left)
	-> % d
*/
int		main(void)
{
/*
	int	*ptr;
	wchar_t	*str = L"hello";
	wchar_t	c = L'X';

	ptr = malloc(sizeof(int) * 1);
	*ptr = 5;
	ft_printf(TEST1);
	printf(TEST1);
	ft_printf(TEST2);
	printf(TEST2);
	ft_printf(TEST3);
	printf(TEST3);
	ft_printf(TEST4);
	printf(TEST4);
	ft_printf("\n");
	ft_printf("%%\n");
	ft_printf("%d\n", 42);
	ft_printf("%d%d\n", 42, 41);
	ft_printf("%d%d%d\n", 42, 43, 44);
	ft_printf("%ld\n", 2147483647);
	ft_printf("%lld\n", 9223372036854775807);
	ft_printf("%x\n", 505);
	ft_printf("%X\n", 505);
	ft_printf("%p\n", &ft_printf);
	ft_printf("%20.15d\n", 54321);
	ft_printf("%-10d\n", 3);
	ft_printf("% d\n", 3);
	ft_printf("%+d\n", 3);
	ft_printf("%010d\n", 1);
	ft_printf("%hhd\n", 0);
	ft_printf("%jd\n", 9223372036854775807);
	ft_printf("%zd\n", 4294967295);
	ft_printf("%\n");
	ft_printf("%U\n", 4294967295);
	ft_printf("%u\n", 4294967295);
	ft_printf("%o\n", 40);
	ft_printf("%%#08x\n", 42);
	ft_printf("%x\n", 1000);
	ft_printf("%#X\n", 1000);
	ft_printf("%s\n", NULL);
	ft_printf("%S\n", L"ݗݜशব");
	ft_printf("%s%s\n", "test", "test");
	ft_printf("%s%s%s\n", "test", "test", "test");
	ft_printf("%C\n", 15000);
	*/
	return (0);
}
