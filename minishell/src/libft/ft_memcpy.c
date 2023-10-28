/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:32:35 by fbourgue          #+#    #+#             */
/*   Updated: 2023/04/04 15:11:52 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dd;
	char	*ss;

	if ((src == NULL && dest == NULL))
		return (NULL);
	dd = (char *)dest;
	ss = (char *)src;
	while (n--)
	{
		*dd++ = *ss++;
	}
	return (dest);
}
