/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:21:02 by fbourgue          #+#    #+#             */
/*   Updated: 2023/04/28 14:08:32 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	ret;

	ret = 0;
	while (*s++)
		++ret;
	return (ret);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		return ((char *)s + i);
	}
	return (0);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (ft_strlen_gnl(s) < start)
	{
		res = malloc(sizeof(char) * (len + 1));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	i = 0;
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin_gnl(const char *s1, const char *s2)
{
	char	*res;
	size_t	i;

	res = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 2);
	if (!res)
		return (NULL);
	i = 0;
	while (*s1)
	{
		res[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		res[i] = *s2++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strdup_gnl(char *src)
{
	char	*res;
	int		i;
	int		len;

	len = ft_strlen_gnl(src);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
