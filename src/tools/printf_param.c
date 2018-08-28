/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_param->c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 15:58:39 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/24 11:40:08 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_param(t_param param)
{
	int i;

	i = 0;
		ft_putchar('\n');
		ft_putchar('\n');
	while (i < FLAG_NUMBER)
	{
		ft_putstr("flag[");
		ft_putnbr(i);
		ft_putstr("] = ");
		ft_putnbr(param->flag[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
	i = 0;

	ft_putstr("width[");
	ft_putnbr(i);
	ft_putstr("] = ");
	ft_putnbr(param->width);
	ft_putchar('\n');
	ft_putchar('\n');

	ft_putstr("precision[");
	ft_putnbr(i);
	ft_putstr("] = ");
	ft_putnbr(param->precision);
	ft_putchar('\n');
	ft_putchar('\n');

		ft_putstr("modif[");
		ft_putnbr(i);
		ft_putstr("] = ");
		ft_putnbr(param->lmodifier);
		ft_putchar('\n');

	ft_putchar('\n');
		ft_putstr("conver[");
		ft_putnbr(i);
		ft_putstr("] = ");
		ft_putchar(param->conver);
		ft_putchar('\n');
}

#include "ft_printf.h"

void	print_padding(t_padding *padding)
{

		ft_putchar('\n');
		ft_putchar('\n');
	ft_putstr("width [");
	ft_putnbr(padding->width);
	ft_putstr("]");
	ft_putchar('\n');
	ft_putchar('\n');

	ft_putstr("precision[");
	ft_putnbr(padding->precision);
	ft_putstr("]");
	ft_putchar('\n');
	ft_putchar('\n');

		ft_putstr("sign[");
		ft_putnbr(padding->sign);
		ft_putstr("]");
		ft_putchar('\n');
		ft_putchar('\n');

		ft_putstr("size[");
		ft_putnbr(padding->size);
		ft_putstr("]");
		ft_putchar('\n');
		ft_putchar('\n');
}
