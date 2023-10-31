# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 14:04:17 by slecoq            #+#    #+#              #
#    Updated: 2023/06/07 17:33:01 by slecoq           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = src/pipex.c src/utils.c src/close.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
LIB = libft/libftprintf.a

GREEN='\033[32m'
YELLOW='\033[33m'
NONE='\033[0m'
BLUE ='\033[0;94m'

all: $(NAME)

$(NAME):
		@make -s -C libft/
		@echo $(GREEN)"Compilation libft [OK]" $(NONE)
		@$(CC) $(CFLAGS) $(SRCS) $(LIB) -o $(NAME)
		@echo $(GREEN)"Compilation pipex [OK]"$(NONE)

clean:
	@make clean -s -C libft/
	@echo $(GREEN)"Suppression fichier .o [OK]"$(NONE)

fclean: clean
	@$(RM) $(NAME) $(LIB)
	@echo $(BLUE)"	Remise a zero du programme"$(NONE)

re: fclean $(NAME)
