/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 01:18:18 by fbourgue          #+#    #+#             */
/*   Updated: 2023/03/23 01:20:58 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdlib.h>

size_t	ft_putendl_fd(int fd, char *s)
{
	if (s != NULL)
	{
		write (fd, s, ft_strlen(s));
		write (fd, "\n", 1);
		return (1);
	}
	return (0);
}
