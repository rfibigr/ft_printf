/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:32:04 by rfibigr           #+#    #+#             */
/*   Updated: 2018/08/17 18:34:04 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_buff		buff;
	t_param		param;
	char 		*str_cp;
	char 		*str_cp_adress1;
	va_list		ap;

	if (!(str_cp = ft_strdup(str)))
		return (-1);
	str_cp_adress1 = str_cp;
	initial_buff(&buff);
	va_start(ap, str);
	while (*str_cp != '\0')
	{
		if (!(read_str(&str_cp, &buff, &param))
	/* && error_management(param) */)
			return (-1);
		if(!(assign_function(ap, param, &buff)))
			return(-1);
	}
	write_buffer(&buff, buff.i);
	va_end(ap);
	free (str_cp_adress1);
	return (buff.size);
}
