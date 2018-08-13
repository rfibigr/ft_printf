/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:40:53 by rfibigr           #+#    #+#             */
/*   Updated: 2018/08/13 12:52:05 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_strwchar(va_list ap, t_buff *buff, t_param param)
{
	wchar_t *str;

	str = (wchar_t *)va_arg(ap, wchar_t*);
	if (str == NULL)
	{
		ft_print_str(buff, "(null)\0");
		return (0);
	}
	padding_before_str(&param, ft_strlen_wchar(str), buff);
	while (*str)
	{
		ft_print_wchar(*str, buff);
		str = str + 1;
		param.precision--;
	}
	if (param.flag[e_flag_less])
		ft_print_charact(param.width, buff, ' ');
	return (1);
}

void	print_wchar(va_list ap, t_buff *buff, t_param param)
{
	wchar_t wc;

	wc = (wchar_t)va_arg(ap, wchar_t);
	if (param.flag[e_flag_less] == FALSE)
		ft_print_charact(param.width - 1, buff, ' ');
	ft_print_wchar(wc, buff);
	if (param.flag[e_flag_less])
		ft_print_charact(param.width - 1, buff, ' ');
}

int		ft_print_wchar(wchar_t wc, t_buff *buff)
{
	if (wc < 0)
		return (0);
	else if (wc < 0x80)
		add_buffer(buff, wc);
	else if (wc < 0x800)
		write_2_bits(wc, buff);
	else if (wc < 0x10000)
		write_3_bits(wc, buff);
	else if (wc < 0x200000)
		write_4_bits(wc, buff);
	else
		return (0);
	return (1);
}
