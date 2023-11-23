/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:44:08 by slecoq            #+#    #+#             */
/*   Updated: 2023/06/06 14:32:10 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_l;
	t_list	*new_e;

	if (lst == NULL)
		return (NULL);
	new_l = 0;
	while (lst != NULL)
	{
		new_e = ft_lstnew(f(lst->content));
		if (new_e == NULL)
		{
			ft_lstclear(&new_e, del);
			return (NULL);
		}
		ft_lstadd_back(&new_l, new_e);
		lst = (*lst).next;
	}
	return (new_l);
}
