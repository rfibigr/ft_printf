/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:50:15 by rfibigr           #+#    #+#             */
/*   Updated: 2018/06/15 14:31:38 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/include/libft.h"
#include <stdio.h>

int main() {
	int a;

	ft_putendl("_________________TEST FLAG___________________");

	ft_putendl("[ # ]");

	a = printf("%%#o | 12345 =%#o \n", 12345);
	ft_putnbr(a);
	ft_putchar ('\n');
	a = printf("%%o | 12345 =%o \n", 12345);
	ft_putnbr(a);
	ft_putchar ('\n');

	a = printf("%%#x | ef20abc =%#x \n", 0xef20bc);
	ft_putnbr(a);
	ft_putchar ('\n');
	a = printf("%%x | ef20abc =%x \n", 0xef20bc);
	ft_putnbr(a);
	ft_putchar ('\n');


	a = printf("%%#X | EF20ABC =%#X \n", 0XEF20ABC);
	ft_putnbr(a);
	ft_putchar ('\n');
	a = printf("%%X | EF20ABC =%X \n", 0XEF20ABC);
	ft_putnbr(a);
	ft_putchar ('\n');

	ft_putendl("[ 0 ]");

	a = printf("%%04d | 123456789 =%04d \n", 123456789);
	ft_putnbr(a);
	ft_putchar ('\n');

	a = printf("%%011d | 123456789 =%lC \n", 123456789);
	ft_putnbr(a);
	ft_putchar ('\n');

	return 0;
}
