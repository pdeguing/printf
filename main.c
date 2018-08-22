/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 17:32:32 by pdeguing          #+#    #+#             */
/*   Updated: 2018/08/21 17:11:18 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	ft_printf("hello: %d\n", 42);
	ft_printf("hello: %i\n", 42);
	ft_printf("hello: %s\n", "world!");
	ft_printf("hello: %i and the %s\n", 42, "world!");
	ft_printf("hello: %% %c %i and the %s\n", '@', 42, "world!");
	ft_printf("hello: %o %s\n", 42, "yes, that is an octal");
	ft_printf("hello: %o %s\n", 1356, "yes, that is an octal");
	ft_printf("hello: %x %s\n", 42, "yes, that is an hex");
	ft_printf("hello: %x %s\n", 1356, "yes, that is an hex");
	ft_printf("hello: %x %s\n", 512, "yes, that is an hex");
	return (0);
}
