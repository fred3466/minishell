/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:12:43 by slecoq            #+#    #+#             */
/*   Updated: 2023/06/06 14:32:10 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	printadd(uintptr_t nb)
{
	int	index;

	index = 0;
	if (nb >= 16)
	{
		index += printadd(nb / 16);
		index += printadd(nb % 16);
	}
	else if (nb >= 10 && nb <= 15)
		index += ft_printchar(nb + 87);
	else if (nb <= 9)
		index += ft_printchar(nb + '0');
	return (index);
}

int	ft_hexadd(unsigned long long nb)
{
	int	index;

	index = 0;
	if (nb == 0)
		index += ft_printstr("(nil)");
	else
	{
		index += ft_printstr("0x");
		index += printadd(nb);
	}
	return (index);
}
