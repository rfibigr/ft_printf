/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:03:37 by rfibigr           #+#    #+#             */
/*   Updated: 2018/08/10 15:59:51 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		assign_function(va_list ap, t_param param, t_buff *buff)
{
	if (NUMBER_SIGNED(param.conver))
		assign_signed_modifier(ap, param, buff);
	else if (NUMBER_UNSIGNED(param.conver))
		assign_unsigned_modifier(ap, param, buff);
	else if (param.conver == 'p')
		print_adress(ap, param, buff);
	else if (param.conver == 'c' && param.lmodifier != e_modif_l)
		print_char(ap, buff, param);
	else if (param.conver == 's' && param.lmodifier != e_modif_l)
		print_str(ap, buff, param);
	else if (param.conver == '%')
		print_percent(buff, param);
	else if (param.conver == 'c' && param.lmodifier == e_modif_l)
		print_wchar(ap, buff, param);
	else if (param.conver == 's' && param.lmodifier == e_modif_l)
		print_strwchar(ap, buff, param);
}

void	assign_signed_modifier(va_list ap, t_param param, t_buff *buff)
{
	modifier_signed[e_modif_no] = modifier_s_no;
	modifier_signed[e_modif_hh] = modifier_s_hh;
	modifier_signed[e_modif_h] = modifier_s_h;
	modifier_signed[e_modif_ll] = modifier_s_ll;
	modifier_signed[e_modif_l] = modifier_s_l;
	modifier_signed[e_modif_j] = modifier_s_j;
	modifier_signed[e_modif_z] = modifier_s_z;
	modifier_signed[param.lmodifier](ap, param, buff);
}

void	assign_unsigned_modifier(va_list ap, t_param param, t_buff *buff)
{
	modifier_unsigned[e_modif_no] = modifier_u_no;
	modifier_unsigned[e_modif_hh] = modifier_u_hh;
	modifier_unsigned[e_modif_h] = modifier_u_h;
	modifier_unsigned[e_modif_ll] = modifier_u_ll;
	modifier_unsigned[e_modif_l] = modifier_u_l;
	modifier_unsigned[e_modif_j] = modifier_u_j;
	modifier_unsigned[e_modif_z] = modifier_u_z;
	modifier_unsigned[param.lmodifier](ap, param, buff);
}

void	print_adress(va_list ap, t_param param, t_buff *buff)
{
	unsigned long long int arg;

	arg = (unsigned long long int)va_arg(ap, unsigned long long int);
	param.conver = 'x';
	print_hastag(buff, param, 0);
	if (!(param.precision == 0 && arg == 0))
		print_unsigned_l(arg, &param, buff);

}

int		print_str(va_list ap, t_buff *buff, t_param param)
{
	char *str;

	str = (char *)va_arg(ap, char*);
	if (str == NULL)
	{
		ft_print_str(buff, "(null)\0");
		return (0);
	}
	padding_before_str(&param, ft_strlen(str), buff);

	while (*str && param.precision > 0)
	{
		add_buffer(buff, *str);
		str = str + 1;
		param.precision--;
	}
	if (param.flag[e_flag_less])
		ft_print_charact(param.width, buff, ' ');
	return (1);
}

void	print_char(va_list ap, t_buff *buff, t_param param)
{
	if (param.flag[e_flag_less] == 0)
		ft_print_charact(param.width - 1, buff, ' ');
	ft_print_charact(1, buff, (char)va_arg(ap, int));
	if (param.flag[e_flag_less])
		ft_print_charact(param.width - 1, buff, ' ');
}

void	print_percent(t_buff *buff, t_param param)
{
	if (param.flag[e_flag_less] == 0)
		ft_print_charact(param.width - 1, buff, ' ');
	ft_print_charact(1, buff, '%');
	if (param.flag[e_flag_less])
		ft_print_charact(param.width - 1, buff, ' ');
}

int		print_strwchar(va_list ap, t_buff *buff, t_param param)
{
	wchar_t *str;

	str = (wchar_t *)va_arg(ap, wchar_t*);
	if (str == NULL)
	{
		ft_print_str(buff, "(null)\0");
		return (0);
	}
//	padding_before_str(&param, ft_strlen_wchar(str), buff);

	while (*str/* && param.precision > 0*/)
	{
		ft_print_wchar(*str, buff);
		str = str + 1;
		param.precision--;
	}
//	if (param.flag[e_flag_less])
//		ft_print_charact(param.width, buff, ' ');
	return (1);
}

void	print_wchar(va_list ap, t_buff *buff, t_param param)
{
	wchar_t wc;

	wc = (wchar_t)va_arg(ap, wchar_t);
	if (param.flag[e_flag_less] == 0)
		ft_print_charact(param.width - 1, buff, ' ');
	ft_print_wchar(wc, buff);
	if (param.flag[e_flag_less])
		ft_print_charact(param.width - 1, buff, ' ');
}
