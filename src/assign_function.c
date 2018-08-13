/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:03:37 by rfibigr           #+#    #+#             */
/*   Updated: 2018/08/13 11:50:25 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	assign_function(va_list ap, t_param param, t_buff *buff)
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
