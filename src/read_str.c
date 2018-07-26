/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:29:59 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/26 14:21:05 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//on lit jusqu'a % ou BUFF full et on copie dans BUFF.
//Interet de  mettre la fonction en int ? a verifier dans la structure de ft_printf
int		read_str(char **str, t_buff *buff, t_param *param)
{
	int		i_buff;

	i_buff = 0;
	initial_param(param);
	while (**str != '\0')
	{
		if (**str == '%')
		{
			*str = *str + 1;
			if (**str != '%')
			{
				write_buffer(buff, i_buff);
				if(!(verif_form(str, param)))
					return (0);
				return (1);
			};
		}
		(buff->str)[i_buff] = **str;
		i_buff++;
		*str = *str + 1;
		if (i_buff == BUFF_SIZE)
		{
			write_buffer(buff, i_buff);
			i_buff = 0;;
		}
	}
	write_buffer(buff, i_buff);
	return (1);
}

void	add_buffer(t_buff *buff, char c)
{
	(buff->str)[buff->i] = c;
	buff->i++;
	if (buff->i == BUFF_SIZE)
	{
		write_buffer(buff, BUFF_SIZE);
		buff->i = 0;
	}
}

void	write_buffer(t_buff *buff, int i_buff)
{
	buff->size += write(1, &(buff->str), i_buff);
	ft_bzero(buff->str, BUFF_SIZE);
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
//print_param(*param);
	return (1);
}
