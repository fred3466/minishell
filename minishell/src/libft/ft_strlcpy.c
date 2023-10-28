/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:12:12 by fbourgue          #+#    #+#             */
/*   Updated: 2023/03/09 16:46:58 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	n;
	unsigned int	ss;

	ss = ft_strlen(src);
	n = 0;
	if (size == 0)
		return (ss);
	while ((src[n] != 0) && (n < size - 1))
	{
		dest[n] = src[n];
		n++;
	}
	dest[n] = 0;
	return (ss);
}
