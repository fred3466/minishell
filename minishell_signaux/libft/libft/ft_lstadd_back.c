/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:46:37 by slecoq            #+#    #+#             */
/*   Updated: 2023/10/25 14:30:41 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*new_s;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			new_s = ft_lstlast(*(lst));
			(*new_s).next = new;
		}
	}
}
