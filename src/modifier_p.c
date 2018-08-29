/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:36:21 by rfibigr           #+#    #+#             */
/*   Updated: 2018/08/29 11:38:45 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_adress(va_list ap, t_param *param, t_buff *buff)
{
	int size;
	unsigned long long int arg;

	arg = (unsigned long long int)va_arg(ap, unsigned long long int);
	size = size_u_nbr(arg, param);
	param->precision -= size;
	if (param->precision > 0)
		param->width = param->width - param->precision - size - 2;
	else
		param->width = param->width - size - 2;
	if (param->width > 0 && param->flag[e_flag_less] == 0 && param->flag[e_flag_zero] == 0)
		ft_print_charact(param->width, buff, ' ');
	ft_print_str(buff, "0x", 2);
	if (param->width > 0 && param->flag[e_flag_less] == 0 && param->flag[e_flag_zero] == 1)
		ft_print_charact(param->width, buff, '0');
	if (param->precision > 0)
		ft_print_charact(param->precision, buff, '0');
	if (size != 0)
	{
		param->conver = 'x';
		print_unsigned(arg, param, buff);
	}
	if (param->width > 0 && param->flag[e_flag_less] == 1)
		ft_print_charact(param->width, buff, ' ');
	return(1);
}
