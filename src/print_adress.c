/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:36:21 by rfibigr           #+#    #+#             */
/*   Updated: 2018/08/13 11:36:54 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_adress(va_list ap, t_param param, t_buff *buff)
{
	unsigned long long int arg;

	arg = (unsigned long long int)va_arg(ap, unsigned long long int);
	if (arg == 0)
		param.width -= 3;
	else
		param.width -= size_adress(arg);
	if (param.flag[e_flag_less] == FALSE && param.width > 0
		&& param.flag[e_flag_zero] == FALSE)
		ft_print_charact(param.width, buff, ' ');
	param.conver = 'x';
	print_hastag(buff, param, 0);
	if (param.flag[e_flag_less] == FALSE && param.width > 0
		&& param.flag[e_flag_zero] == TRUE)
		ft_print_charact(param.width, buff, '0');
	if (!(param.precision == 0 && arg == 0))
		print_unsigned_l(arg, &param, buff);
/* cas particulier pour adress = 0 et Width */
	if (param.flag[e_flag_less] == TRUE && param.width > 0)
		ft_print_charact(param.width, buff, ' ');
}

int		size_adress(unsigned long adress)
{
	int i;

	i = 2;
	while (adress != 0)
	{
		i++;
		adress /= 16;
	}
	return (i);
}
