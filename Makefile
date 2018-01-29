# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/23 12:59:48 by elebouch          #+#    #+#              #
#    Updated: 2018/01/29 17:42:25 by elebouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INCLUDE = -I libft/includes/ -I includes/


CC = clang
CFLAGS = -Wall -Werror -Wextra $(INCLUDE) -g 

SRC= \
	main.c \
	display.c \
	display_long.c\
	display_miscs.c \
	processing.c \
	sort.c \
	free.c \
	utils.c \
	putpad.c \
	reverse.c \
	error.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all : lib $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $(NAME) libft/libftprintf.a

lib:
	@make -C libft/

obj/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< 

clean:
	@make clean -C libft/
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME)

re: 
	@make fclean 
	@make
