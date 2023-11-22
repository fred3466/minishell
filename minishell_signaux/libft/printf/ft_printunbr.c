/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:51:28 by slecoq            #+#    #+#             */
/*   Updated: 2023/06/06 14:32:10 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printunbr(unsigned int nb)
{
	int	index;

	index = 0;
	if (nb == 0)
		return (ft_printchar('0'));
	if (nb > 0 && nb <= 9)
		index += ft_printchar((nb + '0'));
	else if (nb > 9)
	{
		index += ft_printnbr((nb / 10));
		index += ft_printchar((nb % 10 + '0'));
	}
	return (index);
}
