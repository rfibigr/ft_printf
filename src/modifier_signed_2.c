/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier_signed_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 14:03:36 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/26 10:03:40 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		modifier_s_j(va_list ap, t_param param, t_buff *buff)
{
	intmax_t arg;
	t_padding padding;

	padding.sign = 0;
	arg = (intmax_t)va_arg(ap, intmax_t);
	if (arg < 0)
		padding.sign = -1;
	padding.size = size_intmax_nbr((intmax_t)arg, param);
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	itoa_base_intmax_print((intmax_t)arg, &param, buff);
	if (param.flag[e_flag_less])
	print_caract(padding.width, buff, ' ');
}
