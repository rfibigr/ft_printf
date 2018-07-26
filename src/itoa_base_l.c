/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 09:32:36 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/26 12:14:48 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		size_l_nbr(long long int arg, t_param param)
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

void		itoa_base_l_print(long long int arg, t_param *param, t_buff *buff)

{
	int i_case;

	i_case = 0;
	param->conver == 'x' ? i_case = 32 : 1 ;
	if (arg < 0)
		arg = arg * -1;
	if (arg / param->base != 0)
		itoa_base_l_print(arg / param->base, param, buff);
	arg % param->base <= 9 ? print_caract(1, buff, arg % param->base + '0') :
	print_caract(1, buff, (arg % param->base) + 'A' -10 + i_case);
}

int		size_lu_nbr(unsigned long long int arg, t_param param)
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

void		itoa_base_lu_print(unsigned long long int arg, t_param *param, t_buff *buff)

{
	int i_case;

	i_case = 0;
	param->conver == 'x' ? i_case = 32 : 1 ;
	if (arg / param->base != 0)
		itoa_base_lu_print(arg / param->base, param, buff);
	arg % param->base <= 9 ? print_caract(1, buff, arg % param->base + '0') :
	print_caract(1, buff, (arg % param->base) + 'A' -10 + i_case);
}
