CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

HEADERS = libft.h
SRCS = ft_tab_size.c ft_strcreate.c ft_atoi_hex.c get_next_line.c ft_printf.c ft_atoi.c ft_itoa_base_n.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c ft_bzero.c ft_itoa.c ft_putendl_fd.c ft_strlcat.c ft_substr.c ft_calloc.c ft_itoau_base_n.c ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c ft_isalnum.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_toupper.c ft_isalpha.c ft_memcmp.c ft_split.c ft_strmapi.c ft_isascii.c ft_memcpy.c ft_strchr.c ft_strncmp.c ft_isdigit.c ft_memmove.c ft_strdup.c ft_strnstr.c ft_isprint.c ft_memset.c ft_striteri.c ft_strrchr.c
OBJS = $(SRCS:.c=.o)
DEST = 

NAME = libft.a
	
all: $(NAME)

$(NAME):  $(OBJS)
	ar r $(NAME) $(OBJS) $(HEADERS)

%.o: %.c
	$(CC) $(CFLAGS) -c $(HEADERS) $< 

clean:
	rm -f $(OBJS)
	rm -f *.gch

fclean: clean
	rm -f $(NAME)

re: fclean all

gdb: fclean
	${CC}  -g -c ${HEADERS} ${SRCS}
	ar r $(NAME) $(OBJS) $(HEADERS)
	#gdb -tui -args ./${NAME} ex.txt

.PHONY: all clean fclean re bonus debug
