/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:40:53 by rfibigr           #+#    #+#             */
/*   Updated: 2018/08/21 15:08:11 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_strwchar(va_list ap, t_buff *buff, t_param param)
{
	wchar_t *str;
	int		len;

	str = (wchar_t *)va_arg(ap, wchar_t*);
	if (str == NULL)
		len = 6;
	else
		len = ft_strlen_wchar(str);
	padding_before_str(&param, len, buff);
	if (str == NULL)
	{
		ft_print_str(buff, "(null)\0", param.precision);
		if (param.flag[e_flag_less])
		//retourn -1
			ft_print_charact(param.width, buff, ' ');
		return (1);
	}
	while (*str &&  param.precision > 0)
	{
		//calcul de la precisio pour affichage de wchat
		if(!(ft_print_wchar(*str, buff, &param)))
			return(0);
		str = str + 1;
	}
	if (param.flag[e_flag_less])
		ft_print_charact(param.width, buff, ' ');
	return (1);
}

int		print_wchar(va_list ap, t_buff *buff, t_param param)
{
	wchar_t wc;

	wc = (wchar_t)va_arg(ap, wchar_t);
	// onpuet integrer direcement la variable dans ft_print ( voir char)
	if (param.flag[e_flag_less] == FALSE)
	{
		if (param.flag[e_flag_zero])
			ft_print_charact(param.width - 1, buff, '0');
		else
			ft_print_charact(param.width - 1, buff, ' ');
	}
	if (!(ft_print_wchar(wc, buff, &param)))
		return(0);
	if (param.flag[e_flag_less])
		ft_print_charact(param.width - 1, buff, ' ');
	return(1);
}

int		ft_print_wchar(wchar_t wc, t_buff *buff, t_param *param)
{
	if (wc < 0)
		return (0);
	else if (wc < 0x80)
	{
		add_buffer(buff, wc);
		param->precision--;
	}
	else if (wc < 0x800 && MB_CUR_MAX > 1)
	{
		write_2_bits(wc, buff);
		param->precision-=2;
	}
	else if (wc < 0x10000 && MB_CUR_MAX > 2)
	{
		write_3_bits(wc, buff);
		param->precision-=3;
	}
	else if (wc < 0x200000 && MB_CUR_MAX > 3)
	{
		write_4_bits(wc, buff);
		param->precision-=4;
	}
	else
		return (0);
	return (1);
}
