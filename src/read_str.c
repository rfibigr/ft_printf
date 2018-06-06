/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:29:59 by rfibigr           #+#    #+#             */
/*   Updated: 2018/06/06 19:48:44 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//on lit jusqu'a % ou BUFF full et on copie dans BUFF.
void		read_str(char *str, t_buff *buff)
{
	int		i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			if (*(str + 1) == '%')
				str++;
			else
		 		break;
		}
		(buff->str)[i] = *str;
		i++;
		str++;
		if (i == BUFF_SIZE)
		{
			write_buffer(buff);
			i = 0;
		}
	}
	write_buffer(buff);
}

void	write_buffer(t_buff *buff)
{
	buff->size += write(1, &(buff->str), ft_strlen(buff->str));
	ft_bzero(buff->str, BUFF_SIZE);
}
