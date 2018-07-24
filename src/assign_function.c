/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:03:37 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/24 17:20:02 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		assign_function(va_list ap, t_param param, t_buff *buff)
{
//	if (param.conver == 'd' )
		modifier_hh(ap, param, buff);
}

void		modifier_no(va_list ap, t_param param, t_buff *buff)
{
	int arg;
	t_padding padding;

	padding.sign = 0;
	arg = va_arg(ap, int);
	if (arg < 0)
		padding.sign = -1;
	padding.size = size_nbr(arg, param);
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	itoa_base_print(arg, &param, buff);
	if (param.flag[e_flag_less])
		print_caract(padding.width, buff, ' ');
}
