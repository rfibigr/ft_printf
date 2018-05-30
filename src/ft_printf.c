/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:32:04 by rfibigr           #+#    #+#             */
/*   Updated: 2018/05/30 19:08:45 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		ap;

	va_start(ap, str);
	type = va_arg(ap, char *);
	va_end(ap);
}


/** Fonction lecture str
* On recupere le type du premier %
* on test si formatage est ok
* si argument est ok
* on envoie dans les differentes fonctions pour preparer l'argument
* on imprimme l'argument
