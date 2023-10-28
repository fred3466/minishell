/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:17:10 by fbourgue          #+#    #+#             */
/*   Updated: 2023/08/27 21:44:06 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

void	convert(long long n, char *r, int i)
{
	if (n < 0)
	{
		r[0] = '-';
		n = -n;
	}
	if (n < 10)
		r[i] = n + '0';
	else
	{
		convert(n / 10, r, i - 1);
		convert(n % 10, r, i);
	}
}

int	get_nb_digits(long long n)
{
	int		i;

	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(long long n)
{
	char	*r;
	int		nb;

	nb = get_nb_digits(n);
	if (n < 0)
		nb++;
	if (n == 0)
		nb = 1;
	r = malloc(sizeof(char) * (nb + 1));
	if (! r)
		return (NULL);
	r[nb] = 0;
	convert(n, r, nb - 1);
	return (r);
}
