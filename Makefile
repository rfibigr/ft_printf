# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 16:20:20 by rfibigr           #+#    #+#              #
#    Updated: 2018/07/20 11:03:37 by rfibigr          ###   ########.fr        #
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
NAME =		ft_printf

#/********************** SOURCE *********************/
SRC =		main.c					\
		ft_printf.c \
		read_str.c	\
		verif_form.c \
		printf_param.c\
		assign_function.c \
		padding_before.c \
		itoa_base.c \

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
	$(CC) -o $@ $^ $(LIBP)

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
