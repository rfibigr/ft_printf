/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:29:59 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/17 15:53:50 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//on lit jusqu'a % ou BUFF full et on copie dans BUFF.
//Interet de  mettre la fonction en int ? a verifier dans la structure de ft_printf
int		read_str(char **str, t_buff *buff, t_param *param)
{
	int		i;

	i = 0;
	initial_param(param);
	while (**str != '\0')
	{
		if (**str == '%')
		{
			*str = *str + 1;
			if (**str != '%')
			{
				write_buffer(buff);
				if(!(verif_form(str, param)))
					return (0);
				return (1);
			};
		}
		(buff->str)[i] = **str;
		i++;
		*str = *str + 1;
		if (i == BUFF_SIZE)
		{
			write_buffer(buff);
			i = 0;;
		}
	}
	write_buffer(buff);
	return (1);
}

void	write_buffer(t_buff *buff)
{
	buff->size += write(1, &(buff->str), ft_strlen(buff->str));
	ft_bzero(buff->str, BUFF_SIZE);
	//i dans la fonction pour norme
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
	param->lmodifier = 0;
	param->precision = 0;
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
	{
		param->conver = **str;
		*str = *str + 1;
	}
	else
		return (0);
	//print_param(*param);
	return (1);
}
