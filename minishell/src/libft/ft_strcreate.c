/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:36:35 by fbourgue          #+#    #+#             */
/*   Updated: 2023/09/11 12:18:42 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strcreate(size_t size)
{
	char	*rtn;

	rtn = (char *)malloc(size + 1);
	if (rtn != (char *) NULL)
		ft_bzero((void *)rtn, size + 1);
	return (rtn);
}
