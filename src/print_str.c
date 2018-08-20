/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:39:03 by rfibigr           #+#    #+#             */
/*   Updated: 2018/08/17 18:15:35 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_str(va_list ap, t_buff *buff, t_param param)
{
	char 	*str;
	int		len;

	str = (char *)va_arg(ap, char*);
	if (str == NULL)
		len = 6;
	else
		len = ft_strlen(str);
	padding_before_str(&param, len, buff);
	if (str == NULL)
	{
		ft_print_str(buff, "(null)\0", param.precision);
		if (param.flag[e_flag_less])
			ft_print_charact(param.width, buff, ' ');
		return (0);
	}
	while (*str && param.precision > 0)
	{
		add_buffer(buff, *str);
		str = str + 1;
		param.precision--;
	}
	if (param.flag[e_flag_less])
		ft_print_charact(param.width, buff, ' ');
	return (1);
}

void	print_char(va_list ap, t_buff *buff, t_param param)
{
	if (param.flag[e_flag_less] == 0)
	{
		if (param.flag[e_flag_zero])
			ft_print_charact(param.width - 1, buff, '0');
		else
			ft_print_charact(param.width - 1, buff, ' ');
	}
	ft_print_charact(1, buff, (char)va_arg(ap, int));
	if (param.flag[e_flag_less])
		ft_print_charact(param.width - 1, buff, ' ');
}

void	ft_print_charact(int i, t_buff *buff, char c)
{
	while (i > 0)
	{
		add_buffer(buff, c);
		i--;
	}
}

void	ft_print_str(t_buff *buff, char *str, int precision)
{
	if (precision < 0)
		precision = 6;
	while (*str && precision > 0)
	{
		add_buffer(buff, *str);
		str++;
		precision--;
	}
}
