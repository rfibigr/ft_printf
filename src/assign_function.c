/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:03:37 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/31 16:06:00 by rfibigr          ###   ########.fr       */
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
	else if (param.conver == 'c')
		print_caract(1, buff, (char)va_arg(ap, int));
	else if (param.conver == 's')
		print_str(ap, buff);

}

void	assign_signed_modifier(va_list ap, t_param param, t_buff *buff)
{
	modifier_signed[e_modif_no] = modifier_s_no;
	modifier_signed[e_modif_hh] = modifier_s_hh;
	modifier_signed[e_modif_h] = modifier_s_h;
	modifier_signed[e_modif_ll] = modifier_s_ll;
	modifier_signed[e_modif_l] = modifier_s_l;
	modifier_signed[e_modif_j] = modifier_s_j;
	modifier_signed[e_modif_z] = modifier_u_z;
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
	print_unsigned_l(arg, &param, buff);
}

void	print_str(va_list ap, t_buff *buff)
{
	char *str;

	str = (char *)va_arg(ap, char*);
	while (*str)
	{
	//	print_caract(1, buff, *str);
		add_buffer(buff, *str);
		str = str + 1;
	}
}
