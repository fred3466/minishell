/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:02:00 by fbourgue          #+#    #+#             */
/*   Updated: 2023/03/31 17:10:25 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*doit(char const *s, unsigned int start, size_t len)
{
	char			*r;
	size_t			i;
	unsigned int	sz;
	unsigned int	sz_tmp;

	sz_tmp = ft_strlen(s) + 1;
	if ((start + len) >= sz_tmp)
		sz = sz_tmp - start;
	else
		sz = len + 1;
	r = (char *)malloc((sz) * sizeof(char));
	if (! r)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		r[i] = (s[i + start]);
		i++;
	}
	r[i] = 0;
	return (r);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;

	if (s == NULL || start >= ft_strlen(s) || len <= 0)
	{
		r = malloc(sizeof(char));
		if (! r)
			return (NULL);
		r[0] = 0;
		return (r);
	}
	r = doit(s, start, len);
	return (r);
}
