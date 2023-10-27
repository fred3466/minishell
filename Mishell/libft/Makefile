# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 17:38:13 by slecoq            #+#    #+#              #
#    Updated: 2023/06/06 14:34:53 by slecoq           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c \
		libft/ft_isdigit.c libft/ft_isprint.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c \
		libft/ft_memset.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c \
		libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_tolower.c libft/ft_toupper.c libft/ft_substr.c\
		libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c libft/ft_strmapi.c libft/ft_striteri.c \
		libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c printf/ft_printf.c \
		printf/ft_printchar.c printf/ft_printstr.c printf/ft_printnbr.c printf/ft_printunbr.c printf/ft_hexadd.c \
		printf/ft_printhex.c gnl/get_next_line_bonus.c gnl/get_next_line_utils_bonus.c \
		libft/ft_lstnew.c libft/ft_lstadd_front.c libft/ft_lstsize.c libft/ft_lstlast.c libft/ft_lstadd_back.c \
		libft/ft_lstdelone.c libft/ft_lstclear.c libft/ft_lstiter.c libft/ft_lstmap.c libft/ft_strcmp.c \

OBJS = $(patsubst %.c,%.o,$(SRCS))
CC = gcc
CFLAGS = -Wall -Wextra -Werror -s
RM = rm -f

GREEN='\033[32m'
YELLOW='\033[33m'
NONE='\033[0m'
BLUE ='\033[0;94m'

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)
