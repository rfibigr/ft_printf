/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier_signed_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 14:03:36 by rfibigr           #+#    #+#             */
/*   Updated: 2018/08/13 11:59:36 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	modifier_s_j(va_list ap, t_param param, t_buff *buff)
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
	if (!(arg == 0 && param.precision == 0))
		print_signed_j((intmax_t)arg, &param, buff);
	if (param.flag[e_flag_less])
		ft_print_charact(padding.width, buff, ' ');
}

void	modifier_s_z(va_list ap, t_param param, t_buff *buff)
{
	ssize_t arg;
	t_padding padding;

	padding.sign = 0;
	arg = (ssize_t)va_arg(ap, ssize_t);
	if (arg < 0)
		padding.sign = -1;
	padding.size = size_ssizet_nbr((size_t)arg, param);
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	if (!(arg == 0 && param.precision == 0))
		print_signed_z((size_t)arg, &param, buff);
	if (param.flag[e_flag_less])
		ft_print_charact(padding.width, buff, ' ');
}
