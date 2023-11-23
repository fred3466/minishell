/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:50:55 by slecoq            #+#    #+#             */
/*   Updated: 2023/10/26 13:53:15 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_free(char **str)
{
	int i = -1;

	while (str[++i])
		free(str[i]);
	free(str);
}

void ft_free_lstvar(t_env_var *lst)
{
	t_env_var *cur;
	t_env_var *next;

	cur = lst;
	while (cur)
	{
		next = cur->next;
		free(cur->name);
		free(cur->value);
		free(cur);
		cur = next;
	}
}

void ft_free_lstenv(t_env *lst)
{
	t_env *cur;
	t_env *next;

	cur = lst;
	while (cur)
	{
		next = cur->next;
		free(cur->name);
		free(cur->value);
		free(cur);
		cur = next;
	}
}

void ft_free_cell(t_env *lst)
{
	free(lst->name);
	free(lst->value);
	free(lst);
}