/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:53:54 by slecoq            #+#    #+#             */
/*   Updated: 2023/10/26 14:23:43 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env *add_var_env(t_env *env_lst, t_env_var *var)
{
	t_env *head;
	t_env *new;

	head = env_lst;
	while (env_lst)
	{
		if (!ft_strcmp(env_lst->name, var->name))
		{
			env_lst->value = swap_value(env_lst->value, var->value);
			return (head);
		}
		env_lst = env_lst->next;
	}
	new = lstnew_env(ft_strdup(var->name), ft_strdup(var->value));
	ft_lstadd_back(&head, new);
	env_lst = head;
	return (env_lst);
}

t_env *remove_var_env(t_env *env_lst, t_env_var *var)
{
	t_env *head;
	t_env *prev;

	head = env_lst;
	prev = NULL;
	if (!ft_strcmp(env_lst->name, var->name))
	{
		env_lst = env_lst->next;
		return (ft_free_cell(head), env_lst);
	}
	while (env_lst)
	{
		if (!ft_strcmp(env_lst->name, var->name))
		{
			if (prev)
				prev->next = env_lst->next;
			return (ft_free_cell(env_lst), head);
		}
		prev = env_lst;
		env_lst = env_lst->next;
	}
	return (head);
}
