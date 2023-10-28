/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:52:48 by fbourgue          #+#    #+#             */
/*   Updated: 2023/03/23 01:16:56 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdlib.h>

size_t	ft_putstr_fd(int fd, char *s)
{
	int		re;

	if (s != NULL)
	{
		re = ft_strlen(s);
		write (fd, s, re);
		return (re);
	}
	write (fd, &"(null)", 6);
	return (6);
}
