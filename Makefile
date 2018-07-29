# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 16:20:20 by rfibigr           #+#    #+#              #
#    Updated: 2018/07/28 10:05:32 by rfibigr          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all, clean, fclean, re

#/******************* DIRECTORIES *******************/
SRC_PATH =	src
OBJ_PATH =	obj
INC_PATH =	include
LIB_PATH =	lib

#/******************* COMPILATION *******************/
CC =			gcc
CFLAGS =		-Wall -Werror -Wextra

#/********************** BINARY *********************/
NAME =		libftprintf.a

#/********************** SOURCE *********************/
SRC =						\
		ft_printf.c \
		read_str.c	\
		verif_form.c \
		printf_param.c\
		assign_function.c \
		padding_before.c \
		print_int.c \
		print_j.c \
		print_l.c \
		print_z.c \
		modifier_signed_1.c \
		modifier_signed_2.c \
		modifier_unsigned_1.c \
		modifier_unsigned_2.c \
		print_buffer.c \
		ft_bzero.c \
		ft_strlen.c \
		ft_strdup.c


OBJ =		$(SRC:.c=.o)
LIBNAME =	libft/libft.a

#/********************** PATH  *********************/
LIBP = 		$(addprefix $(LIB_PATH)/,$(LIBNAME))
OBJP =		$(addprefix $(OBJ_PATH)/,$(OBJ))
SRCP =		$(addprefix $(SRC_PATH)/,$(SRC))
INCP =		$(foreach dir, $(INC_PATH), -I$(dir))


###################################################
#/********************** RULES *********************/

all : $(NAME)


$(NAME) : $(OBJP)
	make -C $(LIB_PATH)/libft
	ar rc libftprintf.a $(OBJP)
	ranlib $(NAME)
#	$(CC) -o $@ $^ $(LIBP)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -o $@ -c $^ $(INCP) -g
clean :
	rm -rf $(OBJ)
	rm -rf $(OBJ_PATH) 2 /dev/null || true
	make clean -C $(LIB_PATH)/libft

fclean : clean
	rm -rf $(NAME)
	make fclean -C $(LIB_PATH)/libft

re: fclean all

debug : $(OBJP)
	make -C $(LIB_PATH)/libft
	$(CC) -fsanitize=address -g3 $^ $(LIBP) -o $(NAME)
