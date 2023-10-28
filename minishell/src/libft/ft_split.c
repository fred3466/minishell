/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:16:50 by fbourgue          #+#    #+#             */
/*   Updated: 2023/09/11 17:57:31 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**malloc_tab(char const *s, char c)
{
	size_t	i;
	int		r;
	char	**ret;

	if (s == NULL || !c)
		return (NULL);
	i = 0;
	r = 0;
	while (s[i])
	{
		if (i == 0)
			r++;
		else
			if (i != 0 && s[i] != c && s[i - 1] == c)
				r++;
		i++;
	}
	ret = (char **)malloc(sizeof(char *) * (r + 1));
	return (ret);
}

int	forward(const char *s, char c, int i)
{
	while ((s[i] != 0) && (s[i] == c))
		i++;
	return (i);
}

void	inits_for_norminette(size_t *i, size_t *j, size_t *l)
{
	*i = 0;
	*l = 0;
	*j = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**r;
	size_t	i;
	size_t	j;
	size_t	l;

	r = malloc_tab(s, c);
	if (s == NULL || (! r))
		return (NULL);
	inits_for_norminette(&i, &j, &l);
	while (s[i])
	{
		if ((s[i] == c) || (s[i] == 0))
		{
			if (l != i)
				r[j++] = ft_substr(s, l, i - l);
			i = forward(s, c, i);
			l = i;
		}
		else
			i++;
	}
	if (l != i)
		r[j++] = ft_substr(s, l, i - l);
	r[j] = NULL;
	return (r);
}

void	free_split(char	**r)
{
	int	i;

	i = -1;
	while (r[++i])
	{
		free(r[i]);
	}
	free(r);
}

//=====================================
//=====================================
//=====================================
//=====================================
//=====================================
//=====================================
//=====================================
//=====================================
//=====================================
//=====================================
//char		*ft_strncpy(char *dst, const char *src, size_t len)
//{
//	size_t	i;
//
//	i = 0;
//	while (i < len)
//	{
//		dst[i] = '\0';
//		i++;
//	}
//	i = 0;
//	while (src[i] != '\0' && i < len)
//	{
//		dst[i] = src[i];
//		i++;
//	}
//	while (i < len)
//	{
//		dst[i] = '\0';
//		i++;
//	}
//	return (dst);
//}
//static size_t	count_word(char const *s, char c)
//{
//	size_t		i;
//	size_t		rtn;
//
//	i = 1;
//	rtn = 0;
//	if (s[0] == '\0')
//		return (0);
//	if (s[0] != c)
//		rtn++;
//	while (s[i] != '\0')
//	{
//		if (s[i - 1] == c && s[i] != c)
//			rtn++;
//		i++;
//	}
//	return (rtn);
//}
//
//static char		*get_word(char const *s, size_t *pos, char c)
//{
//	char		*rtn;
//	size_t		beg;
//	size_t		end;
//
//	beg = *pos;
//	while (s[beg] == c)
//		beg++;
//	end = beg;
//	while (s[end] != c && s[end] != '\0')
//		end++;
//	if (beg == end)
//		return (NULL);
//	rtn = ft_strcreate(end - beg);
//	if (rtn != (char *)NULL)
//	{
//		ft_strncpy(rtn, &s[beg], end - beg);
//		*pos = end;
//	}
//	return (rtn);
//}
//
//char			**ft_split(char const *s, char c)
//{
//	char		**rtn;
//	size_t		nb_word;
//	size_t		cur_word;
//	size_t		j;
//
//	if (s == (char *)NULL)
//		return ((char **)NULL);
//	nb_word = count_word(s, c);
//	rtn = (char **)malloc(sizeof(char *) * (nb_word + 1));
//	if (rtn == (char **)NULL)
//		return ((char **)NULL);
//	rtn[nb_word] = (char *)NULL;
//	cur_word = 0;
//	j = 0;
//	while (cur_word < nb_word)
//	{
//		rtn[cur_word] = get_word(s, &j, c);
//		cur_word++;
//	}
//	return (rtn);
//}
//
