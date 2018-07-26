/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:50:15 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/26 11:27:39 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/include/libft.h"
#include <stdio.h>

int main() {
	int a;
	char c;

	a = printf("%%p | 8 =%p \n", &c);
	ft_putnbr(a);
	ft_putchar ('\n');



	return 0;
}
