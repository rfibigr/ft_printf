/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier_signed_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:58:16 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/25 14:31:09 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		modifier_s_no(va_list ap, t_param param, t_buff *buff)
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
	itoa_base_print((int)arg, &param, buff);
	if (param.flag[e_flag_less])
	print_caract(padding.width, buff, ' ');
}

void		modifier_s_hh(va_list ap, t_param param, t_buff *buff)
{
	char arg;
	t_padding padding;

	padding.sign = 0;
	arg = (char)va_arg(ap, int);
	if (arg < 0)
		padding.sign = -1;
	padding.size = size_nbr((char)arg, param);
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	itoa_base_print((char)arg, &param, buff);
	if (param.flag[e_flag_less])
	print_caract(padding.width, buff, ' ');
}

void		modifier_s_h(va_list ap, t_param param, t_buff *buff)
{
	short int arg;
	t_padding padding;

	padding.sign = 0;
	arg = (short int)va_arg(ap, int);
	if (arg < 0)
		padding.sign = -1;
	padding.size = size_nbr((short int)arg, param);
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	itoa_base_print((short int)arg, &param, buff);
	if (param.flag[e_flag_less])
	print_caract(padding.width, buff, ' ');
}

void		modifier_s_ll(va_list ap, t_param param, t_buff *buff)
{
	long long int arg;
	t_padding padding;

	padding.sign = 0;
	arg = (long long int)va_arg(ap,long long int);
	if (arg < 0)
		padding.sign = -1;
	padding.size = size_l_nbr((long long int)arg, param);
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	itoa_base_l_print((long long int)arg, &param, buff);
	if (param.flag[e_flag_less])
	print_caract(padding.width, buff, ' ');
}

void		modifier_s_l(va_list ap, t_param param, t_buff *buff)
{
	long int arg;
	t_padding padding;

	padding.sign = 0;
	arg = (long int)va_arg(ap, long int);
	if (arg < 0)
		padding.sign = -1;
	padding.size = size_l_nbr((long int)arg, param);
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	itoa_base_l_print((long int)arg, &param, buff);
	if (param.flag[e_flag_less])
	print_caract(padding.width, buff, ' ');
}
