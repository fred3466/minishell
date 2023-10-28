/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:40:40 by fbourgue          #+#    #+#             */
/*   Updated: 2023/03/31 14:53:38 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	size_t	sz1;
	size_t	sz2;
	size_t	i;
	size_t	j;

	sz1 = ft_strlen(s1);
	sz2 = ft_strlen(s2);
	r = (char *)malloc(sizeof(char) * (sz1 + sz2 + 1));
	if (! r)
		return (NULL);
	i = -1;
	while (++i < sz1)
	{
		r[i] = s1[i];
	}
	j = 0;
	while (j < sz2)
		r[i++] = s2[j++];
	r[i] = 0;
	return (r);
}
