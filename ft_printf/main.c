/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 17:32:32 by pdeguing          #+#    #+#             */
/*   Updated: 2018/08/28 10:27:16 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#define TEST1 "test1: %d, %i, %s, %010d, % 10d, %-5d, %0d, %-d, % -5d, %5.3d, %-5.3d, %-5.10d.\n", 42, 42, "world", 42, 42, 42, 42, 42, 42, 42, 42, 42 
#define TEST2 "test2: %o, %u, %x, %X, %+5d, %+d, %+5.3d, %c, %%.\n", 42, 42, 42, 42, 42, 42, 42, 'X'
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
	return (0);
}