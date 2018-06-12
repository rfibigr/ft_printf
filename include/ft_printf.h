/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:34:06 by rfibigr           #+#    #+#             */
/*   Updated: 2018/06/12 17:01:34 by rfibigr          ###   ########.fr       */
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
# define CONVER_NUMBER 13
# define FLAG_NUMBER 5
# define MODIF_NUMBER 6
# define TRUE 1
# define FLASE 0
/*** test caracteres after % ***/
# define FLAG(a) ((a =='#' || a == '0' || a == '-' || a == '+' || a == ' ') ? 1 : 0)
# define WIDTH(a) ((a >= '0' && a <= '9') ? 1 : 0)
# define PRECISION(a) ((a == '.') ? 1 : 0)
# define LMODIFIER(a) ((a =='h' || a == 'l' || a == 'j' || a == 'z') ? 1 : 0)
# define CONVERSION(a) ((a == 's' || a == 'S' || a == 'p' || a == 'd'\
					|| a == 'D' || a == 'o' || a == 'O' || a == 'u'\
					|| a == 'U' || a == 'x' || a == 'X' || a == 'c'\
					|| a == 'c') ? 1 : 0)
/******** DATA STRUCT ********/
typedef struct		s_buff
{
	char		str[BUFF_SIZE];
	size_t		size;
}					t_buff;

typedef struct		s_param
{
		int		flag[FLAG_NUMBER];
		int		lmodifier[MODIF_NUMBER];
		int		conver[CONVER_NUMBER];
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

enum	conver
{
	e_conver_s,
	e_conver_S,
	e_conver_p,
	e_conver_d,
	e_conver_D,
	e_conver_o,
	e_conver_O,
	e_conver_u,
	e_conver_U,
	e_conver_x,
	e_conver_X,
	e_conver_c,
	e_conver_C,
};

/******** DECLARATION OF FONCTIONS ********/
int		ft_printf(const char *str, ...);
int		read_str(char **str, t_buff *buff);
void	write_buffer(t_buff *buff);
void	initial_param(t_param *param);
void	verif_form(char **str);
void	verif_flag(char **str, t_param *param);
void	verif_min_width(char **str, t_param *param);
void	verif_precision(char **str, t_param *param);
void	verif_lmodifier(char **str, t_param *param);
void	verif_conversion(char **str, t_param *param);
void	print_param(t_param param);

#endif
