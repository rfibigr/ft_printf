/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_before.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:08:11 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/20 11:07:23 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hastag(t_param param)
{
	if (param.conver == 'x')
		write(1, "0x",2);
	if (param.conver == 'X')
		write(1, "0X",2);
}

void	padding_before(t_param param, int size, t_buff *buff)
{
	int precision;
	int width;

	precision = param.precision - size;
	width = param.width - size;

	if (precision > 0)
	{
		if (precision > width)
			print_caract(precision, buff, '0');
		else
		{
			print_caract(width - precision, buff, ' ');
			print_caract(precision, buff, '0');
		}
	}
	else if (precision < 0 && width > 0)
	{
		param.flag[e_flag_zero] == TRUE ? print_caract(width, buff, '0') :
		print_caract(width, buff, ' ');
	}
}
// width to display
void	print_caract(int i, t_buff *buff, char c)
{
	int i_buffer;

	i_buffer = 0;
	while (i > 0)
	{
		buff->str[i_buffer] = c;
		i_buffer++;
		i--;
		if (i_buffer == BUFF_SIZE)
		{
			write_buffer(buff);
			i_buffer = 0;;
		}
	}
	write_buffer(buff);
}
