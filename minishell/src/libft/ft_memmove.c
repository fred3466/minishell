/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:40:40 by fbourgue          #+#    #+#             */
/*   Updated: 2023/04/04 14:54:44 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dt;
	size_t		i;

	if ((src == NULL && dest == NULL))
		return (NULL);
	dt = malloc(sizeof(char) * n);
	i = 0;
	while (i < n)
	{
		*(dt + i) = *((char *)src + i);
		i++;
	}
	i = 0;
	while (i < n)
	{
		*((char *)dest + i) = dt[i];
		i++;
	}
	return (dest);
}
