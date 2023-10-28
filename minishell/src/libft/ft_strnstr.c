/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:56:20 by fbourgue          #+#    #+#             */
/*   Updated: 2023/08/27 21:44:39 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	ll;

	ll = ft_strlen(little);
	if (ll == 0)
		return ((char *)big);
	i = 0;
	j = 0;
	while ((i < ft_strlen(big)) && (i < len))
	{
		while ((i + j < len) && (i + j < ft_strlen(big)))
		{
			if (big[i + j] != little[j])
				break ;
			j++;
		}
		if (j == ll)
			return ((char *)&(big[i]));
		else
			j = 0;
		i++;
	}
	return (NULL);
}
