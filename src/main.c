/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 18:12:57 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/20 17:16:44 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
	int i;
	(void)argc;
	ft_putstr("FT_PRINTF] ");
	i = ft_printf(argv[1], atoi(argv[2]), atoi(argv[3]));
	ft_putchar('|');
	ft_putnbr(i);
	ft_putchar('\n');
	ft_putendl("---------------------------------------");

	return 0;
}
