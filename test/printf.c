/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:50:15 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/19 11:46:38 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/include/libft.h"
#include <stdio.h>

int main() {
	int a;

	ft_putendl("_________________TEST FLAG___________________");

	ft_putendl("[ # ]");

	a = printf("%%#o | 8 =%#o \n", 8);
	ft_putnbr(a);
	ft_putchar ('\n');
	a = printf("%%o | 8 =%o \n", 8);
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

	a = printf("%%020d | 123456789 =%-+20dddd test \n", 123456789);
	ft_putnbr(a);
	ft_putchar ('\n');


	ft_putendl("_________________PRECISION___________________");


	a = printf("%%.0d | 10 =%.0d \n", 10);
	ft_putnbr(a);
	ft_putchar ('\n');

	a = printf("%%.0s | hello =%.0s \n","hello");
	ft_putnbr(a);
	ft_putchar ('\n');

	a = printf("%%.3d | 10 =%.3d \n", 10);
	ft_putnbr(a);
	ft_putchar ('\n');

	a = printf("%%.3s | hello =%.3s \n","hello");
	ft_putnbr(a);
	ft_putchar ('\n');

	a = printf("%%.10s | hello =%.10s \n","hello");
	ft_putnbr(a);
	ft_putchar ('\n');

	a = printf("%%.10d | 10 =%.10d \n", 10);
	ft_putnbr(a);
	ft_putchar ('\n');

	a = printf("%%.10s | hello =%.10s \n","hello");
	ft_putnbr(a);
	ft_putchar ('\n');

	a = printf("%%.10d | 10 =%.10d \n", 10);
	ft_putnbr(a);
	ft_putchar ('\n');

	ft_putendl("_________________LENGTH MODIFIER___________________");

	a = printf("%%hhd 32767| c = %hhd \n", 32767);
	ft_putnbr(a);
	ft_putchar ('\n');

	a = printf("%%hhd 32768| c = %hhd \n", 3276888882380947109234878);
	ft_putnbr(a);
	ft_putchar ('\n');

	a = printf("%%hd 32767| c = %hd \n", 32767);
	ft_putnbr(a);
	ft_putchar ('\n');

	a = printf("%%hd 39234870192874382768| c = %d \n", 323498701924701982768);
	ft_putnbr(a);
	ft_putchar ('\n');

	a = printf("%%ld 19000000000000000000| c = %ld \n", 190000000000000000000);
	ft_putnbr(a);
	ft_putchar ('\n');


	return 0;
}
