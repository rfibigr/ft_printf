/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 14:26:24 by rfibigr           #+#    #+#             */
/*   Updated: 2018/08/13 11:52:14 by rfibigr          ###   ########.fr       */
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
	buff->size += tmp;
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

void	print_percent(t_buff *buff, t_param param)
{
	if (param.flag[e_flag_less] == 0)
		ft_print_charact(param.width - 1, buff, ' ');
	ft_print_charact(1, buff, '%');
	if (param.flag[e_flag_less])
		ft_print_charact(param.width - 1, buff, ' ');
}
