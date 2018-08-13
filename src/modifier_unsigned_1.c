/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier_unsigned_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:58:16 by rfibigr           #+#    #+#             */
/*   Updated: 2018/08/13 15:27:42 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	modifier_u_no(va_list ap, t_param param, t_buff *buff)
{
	unsigned int arg;
	t_padding padding;

	padding.sign = 0;
	arg = (unsigned int)va_arg(ap, unsigned int);
	if (arg == 0 && param.conver != 'o')
		param.flag[e_flag_hastag] = 0;
	if (arg == 0 && param.conver == 'o' && param.precision == -1)
		param.flag[e_flag_hastag] = 0;
	padding.size = size_u_nbr((unsigned int)arg, param);
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	if (!(arg == 0 && param.precision == 0))
		print_unsigned_int((unsigned int)arg, &param, buff);
	if (param.flag[e_flag_less])
		ft_print_charact(padding.width, buff, ' ');
}

void	modifier_u_hh(va_list ap, t_param param, t_buff *buff)
{
	unsigned char arg;
	t_padding padding;

	padding.sign = 0;
	arg = (unsigned char)va_arg(ap, unsigned int);
	if (arg == 0 && param.conver != 'o')
		param.flag[e_flag_hastag] = 0;
	if (arg == 0 && param.conver == 'o' && param.precision == -1)
		param.flag[e_flag_hastag] = 0;
	padding.size = size_u_nbr((unsigned char)arg, param);
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	if (!(arg == 0 && param.precision == 0))
		print_unsigned_int((unsigned char)arg, &param, buff);
	if (param.flag[e_flag_less])
		ft_print_charact(padding.width, buff, ' ');
}

void	modifier_u_h(va_list ap, t_param param, t_buff *buff)
{
	unsigned short int arg;
	t_padding padding;

	padding.sign = 0;
	arg = (unsigned short int)va_arg(ap, unsigned int);
	if (arg == 0 && param.conver != 'o')
		param.flag[e_flag_hastag] = 0;
	if (arg == 0 && param.conver == 'o' && param.precision == -1)
		param.flag[e_flag_hastag] = 0;
	padding.size = size_u_nbr((unsigned short int)arg, param);
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	if (!(arg == 0 && param.precision == 0))
		print_unsigned_int((unsigned short int)arg, &param, buff);
	if (param.flag[e_flag_less])
		ft_print_charact(padding.width, buff, ' ');
}

void	modifier_u_ll(va_list ap, t_param param, t_buff *buff)
{
	unsigned long long int arg;
	t_padding padding;

	padding.sign = 0;
	arg = (unsigned long long int)va_arg(ap, unsigned long long int);
	if (arg == 0 && param.conver != 'o')
		param.flag[e_flag_hastag] = 0;
	if (arg == 0 && param.conver == 'o' && param.precision == -1)
		param.flag[e_flag_hastag] = 0;
	padding.size = size_lu_nbr((long long int)arg, param);
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	if (!(arg == 0 && param.precision == 0))
		print_unsigned_l((unsigned long long int)arg, &param, buff);
	if (param.flag[e_flag_less])
		ft_print_charact(padding.width, buff, ' ');
}

void	modifier_u_l(va_list ap, t_param param, t_buff *buff)
{
	unsigned long int arg;
	t_padding padding;

	padding.sign = 0;
	arg = (unsigned long int)va_arg(ap, unsigned long int);
	if (arg == 0 && param.conver != 'o')
		param.flag[e_flag_hastag] = 0;
	if (arg == 0 && param.conver == 'o' && param.precision == -1)
		param.flag[e_flag_hastag] = 0;
	padding.size = size_lu_nbr((unsigned long int)arg, param);
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	if (!(arg == 0 && param.precision == 0))
		print_unsigned_l((unsigned long int)arg, &param, buff);
	if (param.flag[e_flag_less])
		ft_print_charact(padding.width, buff, ' ');
}
