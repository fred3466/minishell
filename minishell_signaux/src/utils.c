/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:56:58 by slecoq            #+#    #+#             */
/*   Updated: 2023/10/26 13:57:22 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_array_len(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return(i);
}

char *swap_value(char *old, char *new)
{
	char *new_str;

	new_str = ft_strdup(new);
	free(old);
	return (new_str);
}