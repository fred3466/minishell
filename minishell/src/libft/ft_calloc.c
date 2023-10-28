/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:56:43 by fbourgue          #+#    #+#             */
/*   Updated: 2023/03/31 17:04:24 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*r;
	size_t			sz;
	size_t			i;

	sz = (nmemb * size * sizeof(unsigned char));
	r = (unsigned char *)malloc(sz);
	if (! r)
		return (NULL);
	i = 0;
	while (i < sz)
	{
		r[i++] = 0;
	}
	return (r);
}
