# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/23 12:59:48 by elebouch          #+#    #+#              #
#    Updated: 2018/02/04 14:41:17 by elebouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INCLUDE = -I libft/includes/ -I includes/

CC = gcc
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
	tfile_utils.c\
	putpad.c \
	reverse.c \
	sortarr.c \
	error.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all:  $(NAME)

$(NAME): lib $(OBJ)
	@echo  "\033[94mCompiling ft_ls\033[0m"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L libft/ -lftprintf
	@echo  "\033[34mDone\033[0m"

lib:
	@echo "\033[94mCompiling libft and printf\033[0m"
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
	@make all
