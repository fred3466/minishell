/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:26:22 by slecoq            #+#    #+#             */
/*   Updated: 2023/06/06 14:32:10 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	print_lower(unsigned int nb)
{
	int	index;

	index = 0;
	if (nb >= 16)
	{
		index += print_lower(nb / 16);
		index += print_lower(nb % 16);
	}
	else if (nb >= 10 && nb <= 15)
		index += ft_printchar(nb + 87);
	else if (nb <= 9)
		index += ft_printchar(nb + '0');
	return (index);
}

int	print_upper(unsigned int nb)
{
	int	index;

	index = 0;
	if (nb >= 16)
	{
		index += print_upper(nb / 16);
		index += print_upper(nb % 16);
	}
	else if (nb >= 10 && nb <= 15)
		index += ft_printchar(nb + 55);
	else if (nb <= 9)
		index += ft_printchar(nb + '0');
	return (index);
}

int	ft_printhex(unsigned int nb, char format)
{
	int	index;

	index = 0;
	if (format == 'x')
		index += print_lower(nb);
	else
		index += print_upper(nb);
	return (index);
}
