/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:27:28 by slecoq            #+#    #+#             */
/*   Updated: 2023/06/06 14:32:10 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_cmp_mot(const char *str, char c)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (*str)
	{
		if (*str != c && index == 0)
		{
			index = 1;
			i++;
		}
		else if (*str == c)
		{
			index = 0;
		}
		str++;
	}
	return (i);
}

static char	*ft_dup_mot(const char *str, int debut, int fin)
{
	char	*mot;
	int		i;

	i = 0;
	mot = malloc (sizeof(char) * (fin - debut + 1));
	if (!mot)
		return (NULL);
	while (debut < fin)
	{
		mot[i] = str[debut];
		i++;
		debut++;
	}
	mot[i] = '\0';
	return (mot);
}

char	**ft_split(const char *src, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**dest;

	dest = malloc(sizeof(char *) * (ft_cmp_mot(src, c) + 1));
	if (!src || !dest)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(src))
	{
		if (src[i] != c && index < 0)
			index = i;
		else if ((src[i] == c || i == ft_strlen(src)) && index >= 0)
		{
			dest[j++] = ft_dup_mot(src, index, i);
			index = -1;
		}
		i++;
	}
	dest[j] = 0;
	return (dest);
}
