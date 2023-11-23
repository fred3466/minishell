/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:02:31 by slecoq            #+#    #+#             */
/*   Updated: 2023/06/06 14:32:10 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_flag(va_list args, char c)
{
	int	index;

	index = 0;
	if (c == 'c')
		index += ft_printchar(va_arg(args, int));
	else if (c == 's')
		index += ft_printstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		index += ft_printnbr(va_arg(args, int));
	else if (c == 'u')
		index += ft_printunbr(va_arg(args, unsigned int));
	else if (c == 'p')
		index += ft_hexadd(va_arg(args, unsigned long long));
	else if (c == 'x' || c == 'X')
		index += ft_printhex(va_arg(args, unsigned int), c);
	else if (c == '%')
		index += ft_printchar('%');
	return (index);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		index;

	i = 0;
	index = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			index += ft_flag(args, str[i + 1]);
			i++;
		}
		else
			index += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (index);
}
