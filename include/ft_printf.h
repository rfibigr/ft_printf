/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:34:06 by rfibigr           #+#    #+#             */
/*   Updated: 2018/08/10 19:15:47 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

/******** INCLUDE ********/

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <inttypes.h>
#include <stdio.h>
#include <math.h>

/******** DEFINE ********/

# define BUFF_SIZE 100

/* Number of argument for differents parameter */
# define FLAG_NUMBER 5
# define BASE_SIZE 16
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
					|| a == 'C' || a == '%' || a == 'i') ? 1 : 0)
# define NUMBER_SIGNED(a) ((a == 'd' || a == 'i') ? 1 : 0)
# define NUMBER_UNSIGNED(a) ((a == 'o' || a == 'u'\
					|| a == 'x' || a == 'X') ? 1 : 0) \

/******** DATA STRUCT ********/

typedef struct		s_buff
{
	char		str[BUFF_SIZE];
	size_t		size;
	int			i;
}					t_buff;

typedef struct		s_param
{
		int		flag[FLAG_NUMBER];
		int		lmodifier;
		char	conver;
		int		base;
		int		precision;
		int		width;
		int		sign;
}					t_param;

typedef struct		s_padding
{
		int		width;
		int		precision;
		int		sign;
		int		size;
		int		arg_zero;
}					t_padding;

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
	e_modif_no,
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
void	write_buffer(t_buff *buff, int i_buff);
void	initial_param(t_param *param);
void	initial_buff(t_buff *buff);
int		verif_form(char **str, t_param *param);
void	verif_flag(char **str, t_param *param);
void	verif_min_width(char **str, t_param *param);
void	verif_precision(char **str, t_param *param);
void	verif_lmodifier(char **str, t_param *param);
void	verif_conversion(char **str, t_param *param);
void	assign_function(va_list ap, t_param param, t_buff *buff);
void	modifier_hh(va_list ap, t_param param, t_buff *buff);
void	print_hastag(t_buff *buff, t_param param, int precision);
void	ft_print_charact(int i, t_buff *buff, char c);
void	padding_struct(t_padding *padding, t_param param);
void	padding_before(t_param param, t_padding padding, t_buff *buff);
void	print_sign(t_buff *buff, t_param param, t_padding padding);
void	str_upper(char *str[16]);
void	print_adress(va_list ap, t_param param, t_buff *buff);
int		size_adress(unsigned long adress);
int		print_str(va_list ap, t_buff *buff, t_param param);
void	add_buffer(t_buff *buff, char c);
void	ft_print_str(t_buff *buff, char *str);
void	print_percent(t_buff *buff, t_param param);


void	padding_before_str(t_param *param, int len, t_buff *buff);
void	print_char(va_list ap, t_buff *buff, t_param param);

int		size_nbr(int arg, t_param param);
void	print_signed_int(int arg, t_param *param, t_buff *buff);
int		size_l_nbr(long long int arg, t_param param);
void	print_signed_l(long long int arg, t_param *param, t_buff *buff);
int		size_intmax_nbr(intmax_t arg, t_param param);
void	print_signed_j(intmax_t arg, t_param *param, t_buff *buff);
int		size_sizet_nbr(size_t arg, t_param param);
void	print_unsigned_z(size_t arg, t_param *param, t_buff *buff);

int		size_u_nbr(unsigned int arg, t_param param);
void	print_unsigned_int(unsigned int arg, t_param *param, t_buff *buff);
int		size_lu_nbr(unsigned long long int arg, t_param param);
void	print_unsigned_l(unsigned long long int arg, t_param *param, t_buff *buff);
int		size_u_intmax_nbr(uintmax_t arg, t_param param);
void	print_unsigned_j(uintmax_t arg, t_param *param, t_buff *buff);
int		size_ssizet_nbr(size_t arg, t_param param);
void	print_signed_z(ssize_t arg, t_param *param, t_buff *buff);
int		ft_print_wchar(wchar_t wc, t_buff *buff);
void	print_wchar(va_list ap, t_buff *buff, t_param param);
int		print_strwchar(va_list ap, t_buff *buff, t_param param);
size_t		ft_strlen_wchar(wchar_t *s);


void	assign_signed_modifier(va_list ap, t_param param, t_buff *buff);
void	modifier_s_no(va_list ap, t_param param, t_buff *buff);
void	modifier_s_hh(va_list ap, t_param param, t_buff *buff);
void	modifier_s_h(va_list ap, t_param param, t_buff *buff);
void	modifier_s_l(va_list ap, t_param param, t_buff *buff);
void	modifier_s_ll(va_list ap, t_param param, t_buff *buff);
void	modifier_s_j(va_list ap, t_param param, t_buff *buff);
void	modifier_s_z(va_list ap, t_param param, t_buff *buff);
void	(*modifier_signed[8])(va_list, t_param, t_buff *);
void	assign_unsigned_modifier(va_list ap, t_param param, t_buff *buff);
void	modifier_u_no(va_list ap, t_param param, t_buff *buff);
void	modifier_u_hh(va_list ap, t_param param, t_buff *buff);
void	modifier_u_h(va_list ap, t_param param, t_buff *buff);
void	modifier_u_l(va_list ap, t_param param, t_buff *buff);
void	modifier_u_ll(va_list ap, t_param param, t_buff *buff);
void	modifier_u_j(va_list ap, t_param param, t_buff *buff);
void	modifier_u_z(va_list ap, t_param param, t_buff *buff);
void	(*modifier_unsigned[8])(va_list, t_param, t_buff *);


void	print_param(t_param param);
void	print_padding(t_padding *padding);

char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
void	ft_strcp(char *copy, const char *src);
void	ft_bzero(void *s, size_t n);
int abs_value(int i);

//TOOLS PRINT UNICODE
void	print_bit(wchar_t value);


#endif
