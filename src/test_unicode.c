/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unicode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:48:52 by rfibigr           #+#    #+#             */
/*   Updated: 2018/08/10 15:58:21 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
#include <wchar.h>


void	print_bit(wchar_t value)
{
//	char str[33];
	int i;
	int j;
//	int i_str;
	i = 31;
	j = 0;
	printf("w = %d\n", value);
	printf("%lu\n",sizeof(value));
	while (i >= 0)
	{
		if (j == 8)
		{
			printf(" ");
			j = 0;
		}
		if(value & (1 << i))
		{
			printf("1");
		}
		else
			printf("0");
		i--;
		j++;
	}

/*
	i_str = 0;
	while (i_str < 31)
	{
		str[i_str] = '0';
		i_str++;
	}
	while (value / 2)
	{
		str[i_str] = value % 2 + '0';
		i_str--;
		value = value / 2;
	}
	str[i_str] = value % 2 + '0';
	str[32] = '\0';
	i_str = 0;
	printf("\n");
	while (str[i_str])
	{
		if (i_str % 8 == 0 && i_str != 0)
			write(1, " ", 1);
		write(1, &str[i_str], 1);
		i_str++;
	}
	printf("\n");
	*/
	printf("\n");
}
