/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:34:06 by rfibigr           #+#    #+#             */
/*   Updated: 2018/06/08 15:05:48 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

# define BUFF_SIZE 5

typedef struct		s_buff
{
	char	str[BUFF_SIZE];
	size_t		size;
}					t_buff;

int		ft_printf(const char *str, ...);
int		read_str(char **str, t_buff *buff);
void	write_buffer(t_buff *buff);

#endif
