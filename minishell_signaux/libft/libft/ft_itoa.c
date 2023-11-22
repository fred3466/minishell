/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:41:36 by slecoq            #+#    #+#             */
/*   Updated: 2023/06/06 14:32:10 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	taille_n(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	cpy_n(char *dest, long int nb, int *i)
{
	if (nb >= 10)
	{
		cpy_n(dest, (nb / 10), i);
		cpy_n(dest, (nb % 10), i);
	}
	else if (nb >= 0 && nb <= 9)
	{
		dest[*i] = nb + '0';
		(*i)++;
	}
}

char	*ft_itoa(int n)
{
	int			i;
	char		*dest;
	long int	nb;

	nb = n;
	dest = (char *)malloc(sizeof(char) * (taille_n(nb) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	if (nb < 0 && nb >= -2147483648)
	{
		dest[i] = '-';
		nb *= -1;
		i++;
	}
	cpy_n(dest, nb, &i);
	dest[i] = '\0';
	return (dest);
}
