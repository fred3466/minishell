/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:52:33 by slecoq            #+#    #+#             */
/*   Updated: 2023/10/31 14:52:17 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_data	initstruct(char **av)
{
	t_data	data;

	data.infile = av[1];
	data.cmd = av[2];
	data.cmd2 = av[3];
	data.outfile = av[4];
	return (data);
}

void	ft_exit_msg(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	find_path(char *cmd)
{
	char	**cmd_split;
	char	*path;

	cmd_split = ft_split(cmd, ' ');
	path = ft_strjoin("/usr/bin/", cmd_split[0]);
	if (access(path, X_OK) == 0) // controle que la commande existe dans /usr/bin
	{
		ft_free(cmd_split);
		free(path);
		return ;
	}
	else
	{
		ft_free(cmd_split);
		free(path);
		ft_exit_msg("Cmd dont't find ");
	}
}
