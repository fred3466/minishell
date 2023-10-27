# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 12:28:27 by slecoq            #+#    #+#              #
#    Updated: 2023/08/29 13:32:09 by slecoq           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = main.c

CC = gcc
CFLAG = -Wall -Wextra -Werror -g

RM = rm -rf

GREEN='\033[32m'
YELLOW='\033[33m'
NONE='\033[0m'
BLUE ='\033[0;94m'

all : $(NAME)

$(NAME): 
	@echo $(GREEN)"Compilation Minishell [...]"$(NONE)
	@make -s -C libft/
	@$(CC) $(CFLAG) $(SRCS) libft/libftprintf.a -lreadline -o $(NAME)
	@echo $(GREEN)"Compilation Minishell [OK]"$(NONE)

clean :
	@make clean -s -C libft/
	@echo $(YELLOW)"Fichier .o supprimer"$(NONE)

fclean : clean
	@$(RM) $(NAME) libft/libftprintf.a
	@echo $(BLUE)"	Remise a zero du programme"$(NONE)

re : fclean $(NAME)