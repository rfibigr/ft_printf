/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 09:34:28 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/26 15:34:22 by rfibigr          ###   ########.fr       */
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

void		print_signed_j(intmax_t arg, t_param *param, t_buff *buff)
{
	int i_case;

	i_case = 0;
	param->conver == 'x' ? i_case = 32 : 1;
	if (arg < 0)
		arg = arg * -1;
	if (arg / param->base != 0)
		print_signed_j(arg / param->base, param, buff);
	arg % param->base <= 9 ? add_buffer(buff, arg % param->base + '0') :
	add_buffer(buff, (arg % param->base) + 'A' -10 + i_case);
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

void		print_unsigned_j(uintmax_t arg, t_param *param, t_buff *buff)
{
	int i_case;

	i_case = 0;
	param->conver == 'x' ? i_case = 32 : 1;
	if (arg / param->base != 0)
		print_unsigned_j(arg / param->base, param, buff);
	arg % param->base <= 9 ? add_buffer(buff, arg % param->base + '0') :
	add_buffer(buff, (arg % param->base) + 'A' -10 + i_case);
}
