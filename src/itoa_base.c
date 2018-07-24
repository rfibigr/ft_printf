/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 11:14:43 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/24 15:03:40 by rfibigr          ###   ########.fr       */
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
	// rajouter + 2 si tag # et x ou X
}

void		itoa_base_print(int arg, t_param *param, t_buff *buff)
{
	// no sign
	char charact[16] = "0123456789abcdef";
	int i;

	i = 0;
	if (param->conver == 'X')
		{
			while (i < 15)
				{
					charact[i] =ft_toupper(charact[i]);
					i++;
				}
		}
	if (param->flag[e_flag_hashtag] == 1)
	{
		print_caract(1, buff, '0');
		print_caract(1, buff, param->conver);
		param->flag[e_flag_hashtag] = 0;
	}
	if (arg < 0)
		arg = arg * -1;
	if (arg / param->base != 0)
		itoa_base_print(arg / param->base, param, buff);
	print_caract(1, buff, charact[arg % param->base]);
}
