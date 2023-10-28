/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:25:26 by fbourgue          #+#    #+#             */
/*   Updated: 2023/03/08 17:29:43 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	n;
	unsigned int	ds;
	unsigned int	ss;

	ds = ft_strlen(dest);
	ss = ft_strlen(src);
	n = 0;
	if (size == 0 || ds >= size)
		return (size + ss);
	if (!*src)
		return (ds);
	while ((src[n]) && size && (n < size - ds - 1))
	{
		dest[ds + n] = src[n];
		n++;
	}
	dest[ds + n] = 0;
	return (ss + ds);
}
