/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:29:59 by rfibigr           #+#    #+#             */
/*   Updated: 2018/06/12 17:13:20 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//on lit jusqu'a % ou BUFF full et on copie dans BUFF.
//Interet de  mettre la fonction en int ? a verifier dans la structure de ft_printf
int		read_str(char **str, t_buff *buff)
{
	int		i;

	i = 0;
	while (**str != '\0')
	{
		if (**str == '%')
		{
			*str = *str + 1;
			if (**str != '%')
			{
				write_buffer(buff);
				verif_form(str);
				return(1);
			};
		}
		(buff->str)[i] = **str;
		i++;
		*str = *str + 1;
		if (i == BUFF_SIZE)
		{
			write_buffer(buff);
			i = 0;
		}
	}
	write_buffer(buff);
	return(0);
}

void	write_buffer(t_buff *buff)
{
	buff->size += write(1, &(buff->str), ft_strlen(buff->str));
	ft_bzero(buff->str, BUFF_SIZE);
}

void	initial_param(t_param *param)
{
	int i;

	i = 0;
	while (i < CONVER_NUMBER)
	{
		if (i < FLAG_NUMBER)
			param->flag[i] = 0;
		if (i < MODIF_NUMBER)
			param->lmodifier[i] = 0;
		param->conver[i] = 0;
		i++;
	}
	param->precision = 0;
	param->width = 0;
}

void	verif_form(char **str)
{
	t_param param;

	initial_param(&param);
	if (FLAG(**str))
		verif_flag(str, &param);
	if (WIDTH(**str))
		verif_min_width(str, &param);
	if (PRECISION(**str))
		verif_precision(str, &param);
	if (LMODIFIER(**str))
		verif_lmodifier(str, &param);
	if (CONVERSION(**str))
		verif_conversion(str, &param);
	else
		ft_putendl("ERROR !!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	print_param(param);
}
