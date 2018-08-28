/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_byte.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:40:53 by rfibigr           #+#    #+#             */
/*   Updated: 2018/08/28 16:31:24 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_2_bits(wchar_t wc, t_buff *buff)
{
	unsigned char	tmp;
	unsigned char	c;

	tmp = 0b00011111 & (wc >> 6);
	c = tmp | 0b11000000;
	add_buffer(buff, c);
	tmp = 0b00111111 & (wc);
	c = tmp | 0b10000000;
	add_buffer(buff, c);
}

void	write_3_bits(wchar_t wc, t_buff *buff)
{
	unsigned char	tmp;
	unsigned char	c;

	tmp = 0b00001111 & (wc >> 12);
	c = tmp | 0b11100000;
	add_buffer(buff, c);
	tmp = 0b00111111 & (wc >> 6);
	c = tmp | 0b10000000;
	add_buffer(buff, c);
	tmp = 0b00111111 & (wc);
	c = tmp | 0b10000000;
	add_buffer(buff, c);
}

void	write_4_bits(wchar_t wc, t_buff *buff)
{
	unsigned char	tmp;
	unsigned char	c;

	tmp = 0b00000111 & (wc >> 18);
	c = tmp | 0b11110000;
	add_buffer(buff, c);
	tmp = 0b00111111 & (wc >> 12);
	c = tmp | 0b10000000;
	add_buffer(buff, c);
	tmp = 0b00111111 & (wc >> 6);
	c = tmp | 0b10000000;
	add_buffer(buff, c);
	tmp = 0b00111111 & (wc);
	c = tmp | 0b10000000;
	add_buffer(buff, c);
}
