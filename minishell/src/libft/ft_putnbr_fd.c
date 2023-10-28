/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:48:38 by fbourgue          #+#    #+#             */
/*   Updated: 2023/03/31 18:07:05 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include <limits.h>

size_t	ft_putnbr_fd(int fd, long long n)
{
	char	*r;
	int		re;

	r = ft_itoa(n);
	if (r)
	{
		re = ft_strlen(r);
		write (fd, r, re);
		free (r);
		return (re);
	}
	return (0);
}

size_t	ft_putnbru_fd(int fd, unsigned long long n)
{
	int				ret;
	unsigned int	t;

	ret = 0;
	t = n;
	if (n < 10)
	{
		ft_putchar_fd(fd, t + '0');
		ret++;
	}
	else
	{
		ret += ft_putnbru_fd(fd, t / 10);
		if (((long int) n) != LONG_MIN)
			ret += ft_putnbru_fd(fd, t % 10);
	}
	return (ret);
}
