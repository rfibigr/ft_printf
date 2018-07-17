/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 18:12:57 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/17 15:41:33 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
	int i;
	int j;
	(void)argc;
	ft_putstr("FT_PRINTF] ");
	i = ft_printf(argv[1], 14);
	ft_putchar('|');
	ft_putnbr(i);
	ft_putchar('\n');
	ft_putendl("---------------------------------------");
	ft_putstr("PRINTF] ");
	j = printf(argv[1]);
	ft_putchar('|');
	ft_putnbr(j);
	ft_putchar('\n');

	return 0;
}
