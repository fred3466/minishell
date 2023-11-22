/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:48:22 by slecoq            #+#    #+#             */
/*   Updated: 2023/11/22 11:20:16 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

t_env *lstnew_env(char *name, char *value)
{
	t_env *lst;

	lst = (t_env *)malloc(sizeof(t_env));
	if (!lst)
		return (NULL);
	lst->name = ft_strdup(name);
	lst->value = ft_strdup(value);
	lst->next = NULL;
	free(name);
	free(value);
	return (lst);
}

t_env_var *lstnew_var(char *name, char *value)
{
	t_env_var *lst;

	lst = (t_env_var *)malloc(sizeof(t_env_var));
	if (!lst)
		return (NULL);
	lst->name = ft_strdup(name);
	lst->value = ft_strdup(value);
	lst->next = NULL;
	free(name);
	free(value);
	return (lst);
}

void print_env_lst(t_env *env_lst)
{
	
	while (env_lst)
	{
		ft_printf("%s", env_lst->name);
		ft_printf("=");
		ft_printf("%s\n", env_lst->value);
		env_lst = env_lst->next;
	}
}