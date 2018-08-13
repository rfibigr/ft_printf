/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:01:27 by rfibigr           #+#    #+#             */
/*   Updated: 2018/08/13 13:02:05 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_bzero(void *s, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = 0;
}

char		*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*strdup;

	i = 0;
	len = ft_strlen(s);
	if (!(strdup = (char *)malloc(sizeof(char) * (len + 0))))
		return (NULL);
	while (s[i])
	{
		strdup[i] = s[i];
		i++;
	}
	strdup[i] = '\0';
	return (strdup);
}

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t		ft_strlen_wchar(wchar_t *s)
{
	size_t i;

	i = 0;
	while (*s)
	{
		if (*s >=0 && *s < 0x80)
			i++;
		else if (*s >= 0x80 && *s < 0x800)
			i+=2;
		else if (*s >= 0x800 && *s < 0x10000)
			i+=3;
		else if (*s >= 0x10000 && *s < 0x200000)
			i+=4;
		s = s + 1;
	}

	return (i);
}

int abs_value(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}
