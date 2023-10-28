/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:17:10 by fbourgue          #+#    #+#             */
/*   Updated: 2023/08/27 21:45:00 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

static void	convert2(int base, long long n, char *r, int i)
{
	if (n < 0)
	{
		r[0] = '-';
		n = -n;
	}
	if (n < base)
	{
		if (n < 10)
			r[i] = n + '0';
		else
			r[i] = (n - 10) + 'a';
	}
	else
	{
		convert2(base, n / base, r, i - 1);
		convert2(base, n % base, r, i);
	}
}

static int	get_nb_digits2(int base, long long n)
{
	int		i;

	i = 0;
	while (n)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base_n(int base, long long n)
{
	char	*r;
	int		nb;

	nb = get_nb_digits2(base, n);
	if (n < 0)
		nb++;
	if (n == 0)
		nb = 1;
	r = malloc(sizeof(char) * (nb + 1));
	if (! r)
		return (NULL);
	r[nb] = 0;
	convert2(base, n, r, nb - 1);
	return (r);
}
