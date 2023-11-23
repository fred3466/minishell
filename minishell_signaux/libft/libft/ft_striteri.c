/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:51:13 by slecoq            #+#    #+#             */
/*   Updated: 2023/06/06 14:32:10 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	if (str != NULL && f != NULL)
	{
		t = ft_strlen(str);
		while (i < t)
		{
			(*f)(i, str);
			str++;
			i++;
		}
	}
}
