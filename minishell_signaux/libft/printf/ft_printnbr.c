/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:39:22 by slecoq            #+#    #+#             */
/*   Updated: 2023/06/06 14:32:10 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printnbr(int nb)
{
	int	index;

	index = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		index = 11;
	}
	if (nb < 0 && nb > -2147483648)
	{
		index += ft_printchar('-');
		nb = -nb;
	}
	if (nb >= 0 && nb <= 9)
		index += ft_printchar((nb + '0'));
	else if (nb > 9)
	{
		index += ft_printnbr((nb / 10));
		index += ft_printchar((nb % 10 + '0'));
	}
	return (index);
}
