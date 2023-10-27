/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:36:36 by slecoq            #+#    #+#             */
/*   Updated: 2023/10/27 12:59:13 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(char **str)
{
	int i = -1;

	while (str[++i])
		free(str[i]);
	free(str);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;

	int i = -1;
	int j = 0;
	int	status;
	char	*path;
	char *buff;
	char **cmd = NULL;
	pid_t	pid = 0;
	t_data data;

	data.enviro = env;


	while (1)
	{
		buff = readline("$> ");
		if (!buff)
			break;
		add_history(buff);
		cmd = ft_split(buff, ' ');
		if (ft_strcmp("echo", cmd[0])==0)
		{
			while (cmd[++j])
			{
				ft_putstr_fd(cmd[j], 1);
				ft_putstr_fd(" ", 1);
			}
			j = 0;
			ft_putstr_fd("\n", 1);
			ft_free(cmd);
			free(buff);
		}
		else if (ft_strcmp("exit", cmd[0])==0)
		{
			rl_clear_history();
			ft_free(cmd);
			free(buff);
			exit(0);
		}
		else if (ft_strcmp("env", cmd[0])==0)
		{
			i = -1;
			while (data.enviro[++i])
			{
				ft_putstr_fd(data.enviro[i], 1);
				ft_putchar_fd('\n', 1);
			}
			ft_free(cmd);
			free(buff);
			continue;
		}
		else if (ft_strcmp("ls", cmd[0])==0)
		{
			pid = fork();
			if (pid == 0)
			{
				path = ft_strjoin("/usr/bin/", cmd[0]);
				if (execve(path, cmd, NULL) == -1)
				{
					perror("shell");
					exit(0);
				}
			}
			else
				waitpid(pid, &status, 0);
			ft_free(cmd);
			free(buff);
			continue;
		}
		else if (ft_strcmp("cd", cmd[0])==0)
		{
			if (chdir(cmd[1]) == -1)
				perror("shell");
			ft_free(cmd);
			free(buff);
			continue;
		}
		else if (ft_strcmp("pwd", cmd[0])==0)
		{
			pid = fork();
			if (pid == 0)
			{
				path = ft_strjoin("/usr/bin/", cmd[0]);
				if (execve(path, cmd, NULL) == -1)
				{
					perror("shell");
					exit(0);
				}
			}
			else
				waitpid(pid, &status, 0);
			ft_free(cmd);
			free(buff);
			continue;
		}
		else
		{
			pid = fork();
			if (pid == 0)
			{
				path = ft_strjoin("/usr/bin/", cmd[0]);
				if (access(path, F_OK) == -1)
					execve(path, cmd, NULL);
				else
				{
					perror("shell");
					exit(0);
				}
			}
			else
				waitpid(pid, &status, 0);
			ft_free(cmd);
			free(buff);
		}
	}
	ft_free(cmd);
	// free(path);
	free(buff);
	return (0);
}