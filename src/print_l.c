/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:21:43 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/31 18:01:48 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		size_l_nbr(long long int arg, t_param param)
{
	int i;

	i = 1;
	if (arg == 0 && param.precision == 0 && param.flag[e_flag_hashtag] == 0)
		return (0);
	while (arg / param.base)
	{
		i++;
		arg = arg / param.base;
	}
	return (i);
}

void		print_signed_l(long long int arg, t_param *param, t_buff *buff)

{
	int i_case;

	i_case = 0;
	param->conver == 'x' ? i_case = 32 : 1 ;
	if (arg < 0)
		arg = arg * -1;
	if (arg / param->base != 0)
		print_signed_l(arg / param->base, param, buff);
	arg % param->base <= 9 ? add_buffer(buff, arg % param->base + '0') :
	add_buffer(buff, (arg % param->base) + 'A' -10 + i_case);
}

int		size_lu_nbr(unsigned long long int arg, t_param param)
{
	int i;

	i = 1;
	if (arg == 0 && param.precision == 0 && param.flag[e_flag_hashtag] == 0)
		return (0);
	while (arg / param.base)
	{
		i++;
		arg = arg / param.base;
	}
	return (i);
}

void		print_unsigned_l(unsigned long long int arg, t_param *param, t_buff *buff)

{
	int i_case;

	i_case = 0;
	param->conver == 'x' ? i_case = 32 : 1 ;
	if (arg / param->base != 0)
		print_unsigned_l(arg / param->base, param, buff);
	arg % param->base <= 9 ? add_buffer(buff, arg % param->base + '0') :
	add_buffer(buff, (arg % param->base) + 'A' -10 + i_case);
}
