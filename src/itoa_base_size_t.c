/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_size_t.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 09:53:48 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/26 09:54:01 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		size_sizet_nbr(size_t arg, t_param param)
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

void		itoa_base_sizet_print(size_t arg, t_param *param, t_buff *buff)
{
	int i_case;

	i_case = 0;
	param->conver == 'x' ? i_case = 32 : 1 ;
	if (arg / param->base != 0)
		itoa_base_sizet_print(arg / param->base, param, buff);
	arg % param->base <= 9 ? print_caract(1, buff, arg % param->base + '0') :
	print_caract(1, buff, (arg % param->base) + 'A' -10 + i_case);
}
