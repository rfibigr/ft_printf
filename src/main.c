/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 18:12:57 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/26 15:07:09 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
	int i;
	(void)argc;
	ft_putstr("FT_PRINTF] ");
	ft_putchar('\n');
	i = ft_printf(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
	ft_putchar('|');
	ft_putnbr(i);
	ft_putchar('\n');
	ft_putstr("   PRINTF] ");
	i = printf(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
	ft_putchar('|');
	ft_putnbr(i);
	ft_putchar('\n');
	return 0;
}
