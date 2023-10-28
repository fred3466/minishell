/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:56:25 by fbourgue          #+#    #+#             */
/*   Updated: 2023/07/03 16:16:59 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	skip_prefix(const char *str, int *i)
{
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		*i = 2;
}

int	parse_hex(const char *str, int i)
{
	int		ret;
	int		fac;

	ret = 0;
	skip_prefix(str, &i);
	while (str[i])
	{
		if ((str[i] >= '0') && (str[i] <= '9'))
		{
			ret = (16 * ret) + (str[i] - '0');
		}
		else if ((str[i] >= 'A') && (str[i] <= 'F'))
		{
			fac = 10 + str[i] - 'A';
			ret = (ret * 16) + fac;
		}
		else
			break ;
		i++;
	}
	return (ret);
}

int	skip_space_hex(const char *str)
{
	int	b_sp;
	int	i;

	b_sp = 1;
	i = 0;
	while (b_sp)
	{
		b_sp = (str[i] == '\t' || str[i] == '\n' || str[i] == '\r');
		b_sp = (b_sp || str[i] == '\v' || str[i] == '\f' || str[i] == ' ');
		if (b_sp)
			i++;
	}
	return (i);
}

int	ft_atoi_hex(const char *str)
{
	int	i;
	int	ret;

	ret = 0;
	i = skip_space_hex(str);
	ret = parse_hex (str, i);
	return (ret);
}
