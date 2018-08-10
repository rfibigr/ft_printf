/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 14:21:18 by rfibigr           #+#    #+#             */
/*   Updated: 2018/08/10 15:57:33 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_wchar(wchar_t wc, t_buff *buff)
{
	unsigned char	tmp;
	unsigned char	c;

	tmp = 0;
	if (wc < 0)
		return(0);
	else if (wc < 0x80)
	{
		add_buffer(buff, wc);
	}
	else if (wc < 0x800)
	{
		// on extrait les bit 6 a 10;
		tmp = 0x1f & (wc >> 6);
		c = tmp | 0xc0;
		add_buffer(buff, c);
		// on applique le mask 110xxxxx des bit 6 a 10 et on imprimme
		tmp = 0x3f & (wc);
		c = tmp | 0x80;
		add_buffer(buff, c);
		// on applique le mask 10xxxxxx des bits 5 a -0 et on write.
	}
	else if (wc < 0x10000)
	{
		// on extrait les bit;
		tmp = 0xf & (wc >> 12);
		// on applique le mask 1110xxxx des bit 6 a 10 et on imprimme
		c = tmp | 0xe0;
		add_buffer(buff, c);
		// on extrai les bits 11 - 6
		tmp = 0x3f & (wc >> 6);
		c = tmp | 0x80;
		add_buffer(buff, c);
		// on applique le mask 10xxxxxx des bits 5 a -0 et on write.
		tmp = 0x3f & (wc);
		c = tmp | 0x80;
		add_buffer(buff, c);
		// on applique le mask 10xxxxxx des bits 5 a -0 et on write.
	}
	else if (wc < 0x200000)
	{
		// on extrait les bit;
		tmp = 0x7 & (wc >> 18);
		// on applique le mask 1110xxxx des bit 6 a 10 et on imprimme
		c = tmp | 0xf0;
		add_buffer(buff, c);
		// on extrai les bits 17 - 11
		tmp = 0x3f & (wc >> 12);
		c = tmp | 0x80;
		add_buffer(buff, c);
		// on extrai les bits 11 - 6
		tmp = 0x3f & (wc >> 6);
		c = tmp | 0x80;
		add_buffer(buff, c);
		// on applique le mask 10xxxxxx des bits 5 a -0 et on write.
		tmp = 0x3f & (wc);
		c = tmp | 0x80;
		add_buffer(buff, c);
		// on applique le mask 10xxxxxx des bits 5 a -0 et on write.
	}
	else
		return(0);
	return (1);
}
