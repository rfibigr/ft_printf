/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 09:34:28 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/26 10:15:06 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		size_intmax_nbr(intmax_t arg, t_param param)
{
	int i;

	i = 1;
	while (arg / param.base)
	{
		i++;
		arg = arg / param.base;
	}
	return (i);
}

void		itoa_base_intmax_print(intmax_t arg, t_param *param, t_buff *buff)
{
	int i_case;

	i_case = 0;
	param->conver == 'x' ? i_case = 32 : 1;
	if (arg < 0)
		arg = arg * -1;
	if (arg / param->base != 0)
		itoa_base_intmax_print(arg / param->base, param, buff);
	arg % param->base <= 9 ? print_caract(1, buff, arg % param->base + '0') :
	print_caract(1, buff, (arg % param->base) + 'A' -10 + i_case);
}

int		size_u_intmax_nbr(uintmax_t arg, t_param param)
{
	int i;

	i = 1;
	while (arg / param.base)
	{
		i++;
		arg = arg / param.base;
	}
	return (i);
}

void		itoa_base_u_intmax_print(uintmax_t arg, t_param *param, t_buff *buff)
{
	int i_case;

	i_case = 0;
	param->conver == 'x' ? i_case = 32 : 1;
	if (arg / param->base != 0)
		itoa_base_u_intmax_print(arg / param->base, param, buff);
	arg % param->base <= 9 ? print_caract(1, buff, arg % param->base + '0') :
	print_caract(1, buff, (arg % param->base) + 'A' -10 + i_case);
}
