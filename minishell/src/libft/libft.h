/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:10:48 by fbourgue          #+#    #+#             */
/*   Updated: 2023/09/11 17:58:16 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
#include "get_next_line.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

void			free_split(char	**r);
int				ft_tab_size(char **tab);
char			*ft_strcreate(size_t size);
int				ft_atoi_hex(const char *str);
char			*get_next_line(int fd);
int				ft_printf(const char *fmt, ...);
char			*ft_itoa_base_n(int base, long long n);
char			*ft_itoau_base_n(unsigned int base, unsigned long long n);
int				ft_atoi(const char *str);
void			ft_strcpy(char *dest, char *src);
char			*ft_strdup(char *src);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *str);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(long long n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t			ft_putchar_fd(int fd, char c);
size_t			ft_putstr_fd(int fd, char *s);
size_t			ft_putendl_fd(int fd, char *s);
size_t			ft_putnbr_fd(int fd, long long n);
size_t			ft_putnbru_fd(int fd, unsigned long long n);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
void			ft_bzero(void *s, size_t n);
char			ft_toupper(char c);
void			ft_strtoupper(char *s);
int				ft_tolower(char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *little, size_t len);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);


#endif
