/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:53:54 by slecoq            #+#    #+#             */
/*   Updated: 2023/11/23 13:45:32 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *get_var_env(t_env *env_lst,char *name)
{
	t_env *head;

	head = env_lst;
	t_env *head;
	

	head = env_lst;
	while (head)
	{
		if (!ft_strncmp(env_lst->name, name, ft_strlen(name)))
		{
			return (env_lst->value);
		}
		head = head->next;
	}
	return (name);
}
t_env *add_var_env(t_env *env_lst, t_env *var)
{
	t_env	*head;
	t_env	*new;
	head = env_lst;
	while (env_lst)
	{
		if (!ft_strncmp(env_lst->name, var->name, ft_strlen(env_lst->name)))
		{
			env_lst->value = swap_value(env_lst->value, var->value);
			return (head);
		}
		env_lst = env_lst->next;
	}
	new = lstnew_env(ft_strdup(var->name), ft_strdup(var->value), \
	var->b_global);
	ft_lstadd_back(&head, new);
	env_lst = head;
	return (env_lst);
}
t_env	*remove_from_env(t_env *env_lst, char **var_name_list)
{
	t_env	*crt;
	t_env	*new_list;
	t_env	*new;
	int		i;
	int		b_found;
	new_list = NULL;
	crt = env_lst;
	while (crt)
	{
		b_found = 0;
		i = -1;
		while (var_name_list[++i] && !b_found)
			b_found =! ft_strncmp(crt->name, var_name_list[i], \
			ft_strlen(crt->name));
		if (!b_found)
			ft_lstadd_back(&new_list, lstnew_env(ft_strdup(crt->name), \
			ft_strdup(crt->value), crt->b_global));
		crt = crt->next;
	}
	return (new_list);
}
char	*apply_string_env(const char *str_name, const char *str_val)
{
	size_t	i;
	char	*dest;
	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(str_name) \
	+ ft_strlen(str_val) + 2));
	if (!dest)
		return (NULL);
	while (*str_name)
		dest[i++] = *str_name++;
	dest[i++] = '=';
	if (! str_val)
	{
		dest[i] = '\0';
		return (dest);
	}
	while (*str_val)
		dest[i++] = *str_val++;
	dest[i] = '\0';
	return (dest);
}
char	**new_env(t_env *env_lst)
{
	char	**new_env;
	int		i;
	i = 0;
	new_env = (char **)malloc(sizeof(char *) * (lst_size(env_lst) + 1));
	while (env_lst)
	{
		if (env_lst->b_global == 1)
			new_env[i++] = apply_string_env(env_lst->name, env_lst->value);
		env_lst = env_lst->next;
	}
	new_env[i] = 0;
	return (new_env);
}
