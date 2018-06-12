/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:50:15 by rfibigr           #+#    #+#             */
/*   Updated: 2018/06/12 17:17:54 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/include/libft.h"
#include <stdio.h>

int main() {
	int a;
	a = printf("%%-10d = %lllx\n", 123);
	ft_putchar('\n');
	ft_putnbr(a);
	return 0;
}
