/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:32:04 by rfibigr           #+#    #+#             */
/*   Updated: 2018/06/06 19:51:33 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_buff		buff;
	char 		*str_cp;
	va_list		ap;

	str_cp = ft_strdup(str);
	buff.size = 0;
	read_str(str_cp, &buff);
	ft_putendl("str start at :");
	ft_putchar('|');
	ft_putchar(*(str_cp + 1));
	ft_putchar('|');

	va_start(ap, str);

	//type = va_arg(ap, char *);
	va_end(ap);
	free (str_cp);
	return (buff.size);
}


/** Fonction lecture str
* On recupere le type du premier %
	On lit str jusqu'a % ou jusqu'a la fin de
	On imprimme par taille de BUFF_SIZE
	on note le nombre de caracteres imprimme

* on test si formatage est ok
* si argument est ok
* on envoie dans les differentes fonctions pour preparer l'argument
* on imprimme l'argument
*/
