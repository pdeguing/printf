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
#define TEST "hello: %d, %i, %s, %010d, % 10d, %-5d, % -5d.\n", 42, 42, "world", 42, 42, 42, 42 
/*
REMEMBER TO CHECK CASE WHERE PRINTF DOES NOT COMPILE CAUSE WARNING OR OTHER STRANGE BEHAVIOUR:
	-> %0-5d
	-> % -5d (printf print a space before the number even tho it justifies left)
*/
int		main(void)
{
	ft_printf(TEST);
	printf(TEST);
	return (0);
}
