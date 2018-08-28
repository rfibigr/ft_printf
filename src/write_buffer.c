/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 14:26:24 by rfibigr           #+#    #+#             */
/*   Updated: 2018/08/28 15:43:38 by rfibigr          ###   ########.fr       */
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

void	print_percent(t_buff *buff, t_param *param)
{
	if (param->flag[e_flag_less] == 0)
	{
		if (param->flag[e_flag_zero] == 1)
			ft_print_charact(param->width - 1, buff, '0');
		else
			ft_print_charact(param->width - 1, buff, ' ');
	}
	ft_print_charact(1, buff, '%');
	if (param->flag[e_flag_less])
		ft_print_charact(param->width - 1, buff, ' ');
}
