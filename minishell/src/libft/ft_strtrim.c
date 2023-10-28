/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:54:09 by fbourgue          #+#    #+#             */
/*   Updated: 2023/03/31 15:47:43 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		sz1;
	char	*r;

	i = 0;
	j = 0;
	sz1 = ft_strlen(s1);
	if (ft_strchr(set, s1[0]))
		while (ft_strchr(set, s1[i]))
			i++;
	j = sz1 - 1;
	if (ft_strchr(set, s1[j]))
		while (ft_strchr(set, s1[j]))
			j--;
	j++;
	r = ft_substr(s1, i, (j - i));
	if (! r)
		return (NULL);
	r[j - i + 1] = '\0';
	return (r);
}
