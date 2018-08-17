/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_before.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:08:11 by rfibigr           #+#    #+#             */
/*   Updated: 2018/08/14 15:46:39 by rfibigr          ###   ########.fr       */
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
		if (padding->sign == -1 || param.flag[e_flag_more] == 1
			|| param.flag[e_flag_space] == 1)
			padding->width -= 1;
	}
	if (param.flag[e_flag_hastag] == 1)
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
		if (param.flag[e_flag_zero] == 1
			&& NUMBER_SIGNED(param.conver) == 1)
			print_sign(buff, param, padding);
		if (param.flag[e_flag_hastag] == 1
			&& param.flag[e_flag_zero] == 1)
			print_hastag(buff, param);
		param.flag[e_flag_zero] == TRUE ?
		ft_print_charact(padding.width, buff, '0') :
		ft_print_charact(padding.width, buff, ' ');
	}
	if (param.flag[e_flag_zero] == 0)
	{
		if (NUMBER_SIGNED(param.conver) == 1)
			print_sign(buff, param, padding);
		if (param.flag[e_flag_hastag] == 1)
			print_hastag(buff, param);
	}
	if (padding.width <= 0 && param.flag[e_flag_zero] == 1)
			print_sign(buff, param, padding);
	if (padding.width <= 0 && param.flag[e_flag_zero] == 1 && param.flag[e_flag_hastag] == TRUE)
			print_hastag(buff, param);
	if (padding.precision > 0)
		ft_print_charact(padding.precision, buff, '0');
}

void	padding_before_str(t_param *param, int len, t_buff *buff)
{
	if (param->precision == -1)
	{
		param->width = param->width - len;
		param->precision = len;
	}
	else
	{
		if (param->precision > len)
			param->width = param->width - len;
		else
			param->width = param->width - param->precision;
	}
	if (param->width > 0 && param->flag[e_flag_less] == 0)
	{
		if (param->flag[e_flag_zero])
			ft_print_charact(param->width, buff, '0');
		else
			ft_print_charact(param->width, buff, ' ');
	}
}
