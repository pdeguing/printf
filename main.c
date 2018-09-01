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
#define TEST2 "test2: %o, %u, %x, %X.\n", 42, 42, 42, 42
/*
REMEMBER TO CHECK CASE WHERE PRINTF DOES NOT COMPILE CAUSE WARNING OR OTHER STRANGE BEHAVIOUR:
	-> %0-5d
	-> % -5d (printf print a space before the number even tho it justifies left)
	-> % d
*/
int		main(void)
{
	ft_printf(TEST1);
	printf(TEST1);
	ft_printf(TEST2);
	printf(TEST2);
	return (0);
}
