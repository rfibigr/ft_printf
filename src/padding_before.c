/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_before.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:08:11 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/31 17:55:56 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	padding_struct(t_padding *padding, t_param param)
{
	padding->width = param.width - padding->size;
	padding->precision = param.precision - padding->size;
	if (padding->precision > 0)
		padding->width -= padding->precision;
	if (NUMBER_SIGNED(param.conver))
	{
		if (padding->sign == -1 || param.flag[e_flag_more] == 1 || param.flag[e_flag_space] == 1)
			padding->width -= 1;
	}
	if (param.flag[e_flag_hashtag] == 1)
	{
		if (param.conver == 'o')
			padding->width -= 1;
		else
			padding->width -= 2;
	}
}

void	padding_before(t_param param, t_padding padding, t_buff *buff)
{
	if (padding.width > 0 && param.flag[e_flag_less] == 0)
	{
		if (param.flag[e_flag_zero] == 1 && NUMBER_SIGNED(param.conver) == 1)
			print_sign(buff, param, padding);
		if (param.flag[e_flag_hashtag] == 1 && param.flag[e_flag_zero] == 1)
			print_hastag(buff, param, padding.precision);
		param.flag[e_flag_zero] == TRUE ? print_caract(padding.width, buff, '0') :
		print_caract(padding.width, buff, ' ');
	}
	if (param.flag[e_flag_zero] == 0)
	{
		if (NUMBER_SIGNED(param.conver) == 1)
			print_sign(buff, param, padding);
		if(param.flag[e_flag_hashtag] == 1)
			print_hastag(buff, param, padding.precision);
	}
	if (padding.width <= 0 && param.flag[e_flag_zero] == 1)
			print_sign(buff, param, padding);
	if (padding.precision > 0)
		print_caract(padding.precision, buff, '0');
}
