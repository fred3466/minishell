/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:00:40 by fbourgue          #+#    #+#             */
/*   Updated: 2023/03/07 18:09:31 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void	ft_strtoupper(char *s)
{
	size_t		i;
	size_t		m;

	i = 0;
	m = ft_strlen(s);
	while (i < m)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			(s[i]) = (s[i]) - 32;
		}
		i++;
	}
}
