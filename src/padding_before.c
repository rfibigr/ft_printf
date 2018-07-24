/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_before.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:08:11 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/24 15:59:39 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	padding_struct(t_padding *padding, t_param param)
{
	padding->width = param.width - padding->size;
	padding->precision = param.precision - padding->size;
	if (padding->precision > 0)
		padding->width -= padding->precision;
	if (padding->sign == -1 || param.flag[e_flag_more] == 1 || param.flag[e_flag_space] == 1)
		padding->width -= 1;
	if (param.flag[e_flag_hashtag] == 1)
		padding->width -=2;
}

void	padding_before(t_param param, t_padding padding, t_buff *buff)
{
	if (padding.width > 0 && param.flag[e_flag_less] == 0)
	{
		if (param.flag[e_flag_zero] == 1)
			print_sign(buff, param, padding);
		if (param.flag[e_flag_hashtag] == 1 && param.flag[e_flag_zero] == 1)
			print_hastag(buff, param);
		param.flag[e_flag_zero] == TRUE ? print_caract(padding.width, buff, '0') :
		print_caract(padding.width, buff, ' ');
	}
	if (param.flag[e_flag_zero] == 0)
	{
		print_sign(buff, param, padding);
		if(param.flag[e_flag_hashtag] == 1)
			print_hastag(buff, param);
	}
	if (padding.precision > 0)
		print_caract(padding.precision, buff, '0');
}

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
			write_buffer(buff, i_buffer);
			i_buffer = 0;;
		}
	}
	write_buffer(buff, i_buffer);
}

void	print_sign(t_buff *buff, t_param param, t_padding padding)
{
	if (padding.sign == -1)
		print_caract(1, buff, '-');
	if (param.flag[e_flag_more] && padding.sign == 0)
		print_caract(1, buff, '+');
	if (param.flag[e_flag_space] && padding.sign == 0)
		print_caract(1, buff, ' ');
}

void	print_hastag(t_buff *buff, t_param param)
{
	print_caract(1, buff, '0');
	print_caract(1, buff, param.conver);
}
