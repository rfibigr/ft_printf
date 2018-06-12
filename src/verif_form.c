/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:35:49 by rfibigr           #+#    #+#             */
/*   Updated: 2018/06/12 17:03:29 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	verif_flag(char **str, t_param *param)
{
	while (FLAG(**str))
	{
		if (**str == '#')
			param->flag[e_flag_hashtag] = TRUE;
		else if (**str == '0')
			param->flag[e_flag_zero] = TRUE;
		else if (**str == '-')
			param->flag[e_flag_less] = TRUE;
		else if (**str == '+')
			param->flag[e_flag_more] = TRUE;
		else if (**str == ' ')
			param->flag[e_flag_space] = TRUE;
		*str = *str + 1;
	}
}

void	verif_min_width(char **str, t_param *param)
{
	while (WIDTH(**str))
	{
		param->width = param->width * 10 + ((**str - 48)%10);
		*str = *str + 1;
	}
}

void	verif_precision(char **str, t_param *param)
{
	// On avance apres le point
	*str = *str + 1;
	// On lit tant que str et tant que chiffre
	while (WIDTH(**str))
	{
		param->precision = param->precision * 10 + ((**str - 48)%10);
		*str = *str + 1;
	}
}

void	verif_lmodifier(char **str, t_param *param)
{
	while (LMODIFIER(**str))
	{
		if (**str == 'h' && **str + 1 != 'h')
			param->lmodifier[e_modif_h] = TRUE;
		else if (**str == 'h' && **str + 1 == 'h')
		{
			param->lmodifier[e_modif_hh] = TRUE;
			ft_putstr("WTF");
		}
		else if (**str == 'l' && **str + 1 != 'l')
			param->lmodifier[e_modif_l] = TRUE;
		else if (**str == 'l' && **str + 1 == 'l')
			param->lmodifier[e_modif_ll] = TRUE;
		else if (**str == 'j' && **str + 1 != 'j')
			param->lmodifier[e_modif_j] = TRUE;
		else if (**str == 'z' && **str + 1 != 'z')
			param->lmodifier[e_modif_z] = TRUE;
		*str = *str + 1;
	}
}

void	verif_conversion(char **str, t_param *param)
{
	if (**str == 's')
		param->conver[e_conver_s] = TRUE;
	else if (**str == 'S')
		param->conver[e_conver_S] = TRUE;
	else if (**str == 'p')
		param->conver[e_conver_p] = TRUE;
	else if (**str == 'd')
		param->conver[e_conver_d] = TRUE;
	else if (**str == 'D')
		param->conver[e_conver_d] = TRUE;
	else if (**str == 'o')
		param->conver[e_conver_o] = TRUE;
	else if (**str == 'O')
		param->conver[e_conver_O] = TRUE;
	else if (**str == 'u')
		param->conver[e_conver_u] = TRUE;
	else if (**str == 'U')
		param->conver[e_conver_U] = TRUE;
	else if (**str == 'x')
		param->conver[e_conver_x] = TRUE;
	else if (**str == 'x')
		param->conver[e_conver_S] = TRUE;
	else if (**str == 'c')
		param->conver[e_conver_c] = TRUE;
	else if (**str == 'C')
		param->conver[e_conver_C] = TRUE;
}
