/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 11:14:43 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/24 16:00:11 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		size_nbr(int arg, t_param param)
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

void		itoa_base_print(int arg, t_param *param, t_buff *buff)
{
	int i_case;

	i_case = 0;
	param->conver == 'x' ? i_case = 32 : 1 ;
	if (arg < 0)
		arg = arg * -1;
	if (arg / param->base != 0)
		itoa_base_print(arg / param->base, param, buff);
	arg % param->base <= 9 ? print_caract(1, buff, arg % param->base + '0') :
	print_caract(1, buff, (arg % param->base) + 'A' -10 + i_case);
}

void		str_upper(char **str)
{
	int i;

	while (i < 16)
	{
		*str[i] = ft_toupper(*str[i]);
		i++;
	}
}
