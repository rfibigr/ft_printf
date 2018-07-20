/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:34:06 by rfibigr           #+#    #+#             */
/*   Updated: 2018/07/20 11:07:58 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

/******** INCLUDE ********/

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

/******** DEFINE ********/

# define BUFF_SIZE 10
/* Number of argument for differents parameter */
# define FLAG_NUMBER 5
# define TRUE 1
# define FALSE 0
/*** test caracteres after % ***/
# define FLAG(a) ((a =='#' || a == '0' || a == '-' || a == '+' || a == ' ') ? 1 : 0)
# define WIDTH(a) ((a >= '0' && a <= '9') ? 1 : 0)
# define PRECISION(a) ((a == '.') ? 1 : 0)
# define LMODIFIER(a) ((a =='h' || a == 'l' || a == 'j' || a == 'z') ? 1 : 0)
# define CONVERSION(a) ((a == 's' || a == 'S' || a == 'p' || a == 'd'\
					|| a == 'D' || a == 'o' || a == 'O' || a == 'u'\
					|| a == 'U' || a == 'x' || a == 'X' || a == 'c'\
					|| a == 'C') ? 1 : 0)

/******** DATA STRUCT ********/

typedef struct		s_buff
{
	char		str[BUFF_SIZE];
	size_t		size;
}					t_buff;

typedef struct		s_param
{
		int		flag[FLAG_NUMBER];
		int		lmodifier;
		char	conver;
		int		base;
		int		precision;
		int		width;
}					t_param;

enum	e_flag
{
	e_flag_hashtag,
	e_flag_zero,
	e_flag_less,
	e_flag_more,
	e_flag_space,
};

enum	e_modifier
{
	e_modif_hh,
	e_modif_h,
	e_modif_ll,
	e_modif_l,
	e_modif_j,
	e_modif_z,
};

/******** DECLARATION OF FONCTIONS ********/

int		ft_printf(const char *str, ...);
int		read_str(char **str, t_buff *buff, t_param *param);
void	write_buffer(t_buff *buff);
void	initial_param(t_param *param);
int		verif_form(char **str, t_param *param);
void	verif_flag(char **str, t_param *param);
void	verif_min_width(char **str, t_param *param);
void	verif_precision(char **str, t_param *param);
void	verif_lmodifier(char **str, t_param *param);
void	verif_conversion(char **str, t_param *param);
void	print_param(t_param param);
void	assign_function(va_list ap, t_param param, t_buff *buff);
void	modifier_hh(va_list ap, t_param param, t_buff *buff);
void	print_hastag(t_param param);
void	padding_before(t_param param, int size, t_buff *buff);
int		size_nbr(int arg, t_param param);
void	print_caract(int i, t_buff *buff, char c);


#endif
