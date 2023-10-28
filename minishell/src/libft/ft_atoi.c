/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:11:25 by fbourgue          #+#    #+#             */
/*   Updated: 2023/03/31 13:09:23 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	parse(const char *str, int i, int flag, int sig)
{
	int	ret;

	ret = 0;
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-') && (flag == 1))
			break ;
		if (str[i] == '+')
			flag = 1;
		else if (str[i] == '-')
		{
			sig = 0 - sig;
			flag = 1;
		}
		else if ((str[i] >= '0') && (str[i] <= '9'))
		{
			ret = (10 * ret) + (str[i] - '0');
			flag = 1;
		}
		else
			break ;
		i++;
	}
	ret = sig * ret;
	return (ret);
}

int	skip_space(const char *str)
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

int	ft_atoi(const char *str)
{
	int	i;
	int	ret;
	int	sig;
	int	flag;

	ret = 0;
	flag = 0;
	sig = 1;
	i = skip_space(str);
	ret = parse (str, i, flag, sig);
	return (ret);
}
