/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:01:18 by slecoq            #+#    #+#             */
/*   Updated: 2023/06/06 14:32:10 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_chr_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *str, const char *set)
{
	char	*ptr;
	size_t	i;
	size_t	debut;
	size_t	fin;

	debut = 0;
	while (str[debut] && ft_chr_set(str[debut], set))
		debut++;
	fin = ft_strlen(str);
	while (fin > debut && ft_chr_set(str[fin - 1], set))
		fin--;
	ptr = (char *)malloc(sizeof(char) * (fin - debut + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (debut < fin)
	{
		ptr[i] = str[debut];
		i++;
		debut++;
	}
	ptr[i] = '\0';
	return (ptr);
}
