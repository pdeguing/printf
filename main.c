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
//#define TEST "hello: %d, %i, %s, %o, %x, %X, %%, %c.\n", 42, 42, "world", 42, 42, 42, '@' 
#define TEST "hello: %d, %i, %s.\n", 42, 42, "world" 

int		main(void)
{
	ft_printf(TEST);
	printf(TEST);
	return (0);
}
