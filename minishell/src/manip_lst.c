/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:48:22 by slecoq            #+#    #+#             */
/*   Updated: 2023/11/20 14:01:02 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_lstlast(t_env *lst)
{
	while (lst)
	{
		if ((*lst).next == NULL)
			return (lst);
		lst = (*lst).next;
	}
	return (lst);
}

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

t_env *lstnew_env(char *name, char *value, int b_global)
{
	t_env *lst;

	lst = (t_env *)malloc(sizeof(t_env));
	if (!lst)
		return (NULL);
	lst->name = ft_strdup(name);
	lst->value = ft_strdup(value);
	lst->b_global = b_global;
	lst->next = NULL;
	free(name);
	free(value);
	return (lst);
}

void print_env_lst(t_env *env_lst)
{
	
	while (env_lst)
	{
		if (env_lst->b_global)
		{
			ft_printf("%s", env_lst->name);
			ft_printf("=");
			ft_printf("%s\n", env_lst->value);
		}
		env_lst = env_lst->next;
	}
}
