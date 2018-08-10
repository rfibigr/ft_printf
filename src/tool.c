/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:01:27 by rfibigr           #+#    #+#             */
/*   Updated: 2018/08/10 14:59:46 by rfibigr          ###   ########.fr       */
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

void	ft_strcp(char *copy, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
}

char		*ft_strdup(const char *s)
{
	int		len;
	char	*strdup;

	len = ft_strlen(s);
	if (!(strdup = (char *)malloc(sizeof(char) * (len + 0))))
		return (NULL);
	ft_strcp(strdup, s);
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
	while (s[i])
		i++;
	return (i);
}

int abs_value(int i)
{
	if (i < 0)
		return(-i);
	return(i);
}
