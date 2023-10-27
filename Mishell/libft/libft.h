/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:52:16 by slecoq            #+#    #+#             */
/*   Updated: 2023/06/03 13:57:37 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_atoi(const char *str);
void	ft_bzero(void *str, size_t taille);
void	*ft_calloc(size_t cmp, size_t t);

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

void	*ft_memchr(const void *str, int c, size_t t);
int		ft_memcmp(const void *str1, const void *str2, size_t t);
void	*ft_memcpy(void *dest, const void *src, size_t taille);
void	*ft_memmove(void *dest, const void *src, size_t t);
void	*ft_memset(void *str, int valeur, size_t taille);

char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(const char *str1, const char *str2);
size_t	ft_strlcat(char *dest, const char *src, size_t t);
size_t	ft_strlcpy(char *dest, const char *src, size_t t);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t t);
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strnstr(const char *dest, const char *src, size_t t);
char	*ft_strrchr(const char *str, int c);
char	*ft_substr(const char *src, unsigned int start, size_t t);
char	*ft_strtrim(const char *str, const char *set);
char	**ft_split(const char *src, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(const char *src, char (*f)(unsigned int, char));
void	ft_striteri(char *str, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int nb, int fd);

int		ft_tolower(int c);
int		ft_toupper(int c);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*			FT_PRINTF				*/

int		ft_printf(const char *str, ...);
int		ft_flag(va_list args, const char str);
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printnbr(int nb);
int		ft_printunbr(unsigned int nb);
int		ft_hexadd(unsigned long long nb);
int		printadd(uintptr_t nb);
int		ft_printhex(unsigned int nb, char format);
int		print_lower(unsigned int nb);
int		print_upper(unsigned int nb);

/*			GET NEXT LINE			*/

size_t	ft_strlen_gnl(char *rstr);
char	*ft_strchr_gnl(char *rstr, int c);
char	*ft_strjoin_gnl(char *rstr, char *buff);
char	*ft_get_line(char *rstr);
char	*ft_new_rstr(char	*rstr);
char	*ft_rd_to_new_line(char *rstr, int fd);
char	*get_next_line(int fd);

#endif