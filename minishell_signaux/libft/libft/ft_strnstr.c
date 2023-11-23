/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:55:08 by slecoq            #+#    #+#             */
/*   Updated: 2023/06/06 14:32:10 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *dest, const char *src, size_t t)
{
	size_t	i;
	int		j;

	if (*src == '\0')
		return ((char *)dest);
	i = 0;
	while (dest[i] != '\0' && i < t)
	{
		if (dest[i] == src[0])
		{
			j = 0;
			while (src[j] && dest[i + j] && i + j < t
				&& dest[i + j] == src[j])
				j++;
			if (src[j] == '\0')
				return ((char *)dest + i);
		}
		i++;
	}
	return (0);
}
