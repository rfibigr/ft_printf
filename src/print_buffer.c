/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 14:26:24 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/31 16:20:48 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_buffer(t_buff *buff, char c)
{

	(buff->str)[buff->i] = c;
	buff->i++;
	if (buff->i == BUFF_SIZE)
	{
		write_buffer(buff, BUFF_SIZE);
		buff->i = 0;
	}
}

void	write_buffer(t_buff *buff, int i_buff)
{
	int tmp;

	tmp = write(1, &(buff->str), i_buff);
	if (tmp == -1)
		exit (1);
	buff->size += tmp;
//	buff->size += write(0, &(buff->str), i_buff);
	ft_bzero(buff->str, BUFF_SIZE);
}

void	print_caract(int i, t_buff *buff, char c)
{
	while (i > 0)
	{
		add_buffer(buff, c);
		i--;
	}
}

void	print_sign(t_buff *buff, t_param param, t_padding padding)
{
	if (padding.sign == -1)
		add_buffer(buff, '-');
	if (param.flag[e_flag_more] && padding.sign == 0)
		add_buffer(buff, '+');
	if (param.flag[e_flag_space] && padding.sign == 0)
		add_buffer(buff, ' ');
}

void	print_hastag(t_buff *buff, t_param param, int precision)
{
	if (!(param.conver == 'o' && precision >= 0))
		add_buffer(buff, '0');
	if (param.conver == 'x' || param.conver == 'X')
		add_buffer(buff, param.conver);
}
