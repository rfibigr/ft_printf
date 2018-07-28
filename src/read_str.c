/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:29:59 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/26 16:50:13 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		read_str(char **str, t_buff *buff, t_param *param)
{
	initial_param(param);
	while (**str != '\0')
	{
		if (**str == '%')
		{
			*str = *str + 1;
			if (**str != '%')
			{
				if(!(verif_form(str, param)))
					return (0);
				return (1);
			};
		}
		add_buffer(buff, **str);
		*str = *str + 1;
	}
	return (1);
}

int		verif_form(char **str, t_param *param)
{
//	initial_param(param);
	if (FLAG(**str))
		verif_flag(str, param);
	if (WIDTH(**str))
	// verifier si Int suffisant
		verif_min_width(str, param);
	if (PRECISION(**str))
	//verifier si Int suffisant
		verif_precision(str, param);
	if (LMODIFIER(**str))
		verif_lmodifier(str, param);
	if (CONVERSION(**str))
		verif_conversion(str, param);
	else
		return (0);
	return (1);
}

void	initial_param(t_param *param)
{
	int i;

	i = 0;
	while (i < FLAG_NUMBER)
	{
		param->flag[i] = 0;
		i++;
	}
	param->conver = 0;
	param->lmodifier = e_modif_no;
	param->precision = -1;
	param->width = 0;
}

void	initial_buff(t_buff *buff)
{
	buff->size = 0;
	buff->i = 0;
	ft_bzero(buff->str, BUFF_SIZE);
}
