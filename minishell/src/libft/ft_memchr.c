/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:43:59 by fbourgue          #+#    #+#             */
/*   Updated: 2023/03/31 17:03:42 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cf;

	i = 0;
	cf = NULL;
	while (i < n)
	{
		cf = &(*((unsigned char *)s + i));
		if (*cf == (unsigned char)c)
			return (cf);
		i++;
	}
	return (NULL);
}
