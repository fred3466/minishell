/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:18:57 by fbourgue          #+#    #+#             */
/*   Updated: 2023/03/22 18:02:28 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				delta;
	unsigned char	*ss1;
	unsigned char	*ss2;

	delta = 0;
	if (n == 0)
		return (0);
	ss1 = ((unsigned char *) s1);
	ss2 = ((unsigned char *) s2);
	i = 0;
	while (i < n)
	{
		delta = ss1[i] - ss2[i];
		if (delta != 0)
			return (delta);
		i++;
	}
	return (delta);
}
