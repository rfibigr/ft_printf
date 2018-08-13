/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:36:21 by rfibigr           #+#    #+#             */
/*   Updated: 2018/08/13 18:05:05 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_adress(va_list ap, t_param param, t_buff *buff)
{
	unsigned long long int arg;
	t_padding padding;

	padding.sign = 0;
	param.conver = 'x';
	param.flag[e_flag_hastag] = TRUE;
	arg = (unsigned long long int)va_arg(ap, unsigned long long int);
	padding.size = size_adress(arg);
	if (padding.precision == -1)
		padding.width--;
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	if (!(arg == 0 && param.precision != -1))
		print_unsigned_l((unsigned long long int)arg, &param, buff);
	if (param.flag[e_flag_less])
		ft_print_charact(padding.width, buff, ' ');
}

int		size_adress(unsigned long adress)
{
	int i;

	i = 0;
	while (adress != 0)
	{
		i++;
		adress /= 16;
	}
	return (i);
}
