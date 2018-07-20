/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:03:37 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/20 16:55:29 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		assign_function(va_list ap, t_param param, t_buff *buff)
{
	if (param.conver == 'd')
		modifier_hh(ap, param, buff);
}

void		modifier_hh(va_list ap, t_param param, t_buff *buff)
{
	int arg;
	t_padding padding;

	padding.sign = 0;
	arg = va_arg(ap, int);
	if (arg < 0 || param.flag[e_flag_more] == 1 || param.flag[e_flag_space] == 1)
		padding.sign = 1;
// Calcul the number of caracter to prinf to define the padding of diffrent flag
	padding.size = size_nbr((short int)arg, param);
	padding_struct(&padding, param);
	// size +1 si signe negatif(conver d) ou si flag positif
	padding_before(param, padding, buff);
	ft_putnbr(arg);
	//itoa_base_print(va_arg(ap, short int), param, buff);
	if (param.flag[e_flag_less])
		print_caract(padding.width, buff, ' ');
}


//si #
// si X ou x print 0x ou 0X et return 1
// sinon return (-1)
