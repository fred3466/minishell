/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoau_base_n.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:31:32 by fbourgue          #+#    #+#             */
/*   Updated: 2023/08/27 21:45:12 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

static void	convert2(unsigned int base, unsigned long long n, char *r, int i)
{
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

static int	get_nb_digits2(unsigned int base, unsigned long long n)
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

char	*ft_itoau_base_n(unsigned int base, unsigned long long n)
{
	char	*r;
	int		nb;

	nb = get_nb_digits2(base, n);
	if (n == 0)
		nb = 1;
	r = malloc(sizeof(char) * (nb + 1));
	if (! r)
		return (NULL);
	r[nb] = 0;
	convert2(base, n, r, nb - 1);
	return (r);
}
