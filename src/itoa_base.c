/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 11:14:43 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/20 11:02:14 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		size_nbr(int arg, t_param param)
{
	int i;

	i = 1;
	if (arg < 0 || param.flag[e_flag_more] == 1)
		i++;
	while (arg / param.base)
	{
		i++;
		arg = arg / param.base;
	}
	return (i);
	// rajouter + 2 si tag # et x ou X
}

int		itoa_base(int arg, t_param param, t_buff *buff)
{

}
