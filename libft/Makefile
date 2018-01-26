# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 12:50:22 by elebouch          #+#    #+#              #
#    Updated: 2018/01/11 10:28:06 by elebouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = clang
CFLAGS =  -Wall -Werror -Wextra -I includes/

SRC_DIR = ./src/
OBJ_DIR = ./obj/
LIB_DIR = libft/

SRCS =\
	 ft_printf.c \
	 ft_args.c \
	 ft_format.c \
	 ft_printstr.c \
     ft_getflags.c \
	 ft_printunicode.c \
	 ft_printpointer.c

LIBFT_SRCS= \
   		ft_atoi.c			\
		ft_isalpha.c		\
		ft_isprint.c		\
		ft_memcmp.c			\
		ft_memset.c			\
		ft_strcmp.c			\
		ft_strlcat.c		\
		ft_strncmp.c		\
		ft_strrchr.c		\
		ft_toupper.c		\
		ft_bzero.c			\
		ft_isascii.c		\
		ft_memccpy.c		\
		ft_memcpy.c			\
		ft_strcat.c			\
		ft_strcpy.c			\
		ft_strlen.c			\
		ft_strncpy.c		\
		ft_strstr.c			\
		ft_isalnum.c		\
		ft_isdigit.c		\
		ft_memchr.c			\
		ft_memmove.c		\
		ft_strchr.c			\
		ft_strdup.c			\
		ft_strncat.c		\
		ft_strnstr.c		\
		ft_tolower.c		\
		ft_itoa.c			\
		ft_putchar.c		\
		ft_putendl_fd.c		\
		ft_putstr.c			\
		ft_strdel.c			\
		ft_striteri.c		\
		ft_strmapi.c		\
		ft_strsplit.c		\
		ft_memalloc.c		\
		ft_putchar_fd.c		\
		ft_putnbr.c			\
		ft_putstr_fd.c		\
		ft_strequ.c			\
		ft_strjoin.c		\
		ft_strnequ.c		\
		ft_strsub.c			\
		ft_memdel.c			\
		ft_putendl.c		\
		ft_putnbr_fd.c		\
		ft_strclr.c			\
		ft_striter.c		\
		ft_strmap.c			\
		ft_strnew.c			\
		ft_strtrim.c		\
		ft_lstnew.c			\
		ft_lstdelone.c		\
		ft_lstdel.c			\
		ft_lstadd.c			\
		ft_lstiter.c		\
		ft_lstmap.c			\
		ft_arrsize.c		\
		ft_bubblesortchar.c \
		ft_bubblesortint.c	\
		ft_quicksortchar.c	\
		ft_quicksortint.c	\
		ft_swapchar.c		\
		ft_swapint.c		\
		ft_isspace.c		\
		ft_strindexchr.c	\
		ft_lstsize.c		\
		ft_lstrm.c			\
		ft_sqrt.c			\
		ft_putbits.c		\
 		ft_power.c			\
		ft_abs.c			\
		ft_itoa_base.c		\
		ft_strtolower.c		\
		ft_lltoa_base.c		\
		ft_ctos.c 			\
		ft_putnstr.c		\
		ft_max.c			\
		ft_min.c			\
		ft_strset.c

UNICODE = \
		  ft_wclen.c \
		  ft_wcslen.c \
		  ft_putwc.c  \
		  ft_wctostr.c

LIBFT_SRC = $(addprefix $(SRC_DIR)$(LIB_DIR), $(LIBFT_SRC))
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o)) $(addprefix $(OBJ_DIR)$(LIB_DIR), $(LIBFT_SRCS:.c=.o)) $(addprefix $(OBJ_DIR)unicode/, $(UNICODE:.c=.o))

all:  $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: 
	@make fclean 
	@make

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/libft
	@mkdir -p $(OBJ_DIR)/unicode
	@$(CC) $(CFLAGS) -o $@ -c $< 

.PHONY: all re clean fclean build
