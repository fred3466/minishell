/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:07:31 by slecoq            #+#    #+#             */
/*   Updated: 2023/06/06 14:32:10 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t cmp, size_t t)
{
	char	*ptr;

	if (!cmp || !t)
		return (malloc(0));
	ptr = malloc(cmp * t);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, cmp);
	return (ptr);
}
