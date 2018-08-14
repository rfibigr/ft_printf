/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_before2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:08:11 by rfibigr           #+#    #+#             */
/*   Updated: 2018/08/14 18:01:18 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	padding_struct_o(t_padding *padding, t_param *param)
{
	if (padding->arg_zero == TRUE)
	{
		if (padding->precision < 1)
			padding->precision = 1;
		padding->width -= padding->precision;
		param->flag[e_flag_hastag] = 0;
	}
	else
	{
		padding->precision -= padding->size;
		if (padding->precision > 0)
			padding->width -= (padding->precision + padding->size);
		else
			padding->width -= padding->size;
		if (padding->precision < 0)
			padding->width -= param->flag[e_flag_hastag];
	}
}

void	padding_before_o(t_param param, t_padding padding, t_buff *buff)
{
	if (padding.width > 0 && param.flag[e_flag_less] == 0)
	{
		param.flag[e_flag_zero] == TRUE ?
		ft_print_charact(padding.width, buff, '0') :
		ft_print_charact(padding.width, buff, ' ');
	}
	if (param.flag[e_flag_hastag] == 1 && padding.precision <= 0)
		print_hastag(buff, param);
	if (padding.precision > 0)
		ft_print_charact(padding.precision, buff, '0');
}
