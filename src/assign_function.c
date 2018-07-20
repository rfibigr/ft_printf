/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:03:37 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/19 16:06:04 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		assign_function(va_list ap, t_param param, t_buff *buff)
{
	modifier_hh(ap, param, buff);
}

void		modifier_hh(va_list ap, t_param param, t_buff *buff)
{
	int size;
// Calcul the number of caracter to prinf to define the padding of diffrent flag
	size = size_nbr(va_arg(ap, (short int)), t_param param);
	// size +1 si signe negatif(conver d) ou si flag positif
	if (param.flag[e_flag_hashtag])
		print_hastag(param);
	// padding
	print_flag_before(param, size);
	// verif des flags et si besoin
	verif() and print(flag)
	itoa_base_print();
	verif () and printf(flag)
}


//si #
// si X ou x print 0x ou 0X et return 1
// sinon return (-1)
