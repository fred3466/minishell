/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:36:36 by slecoq            #+#    #+#             */
/*   Updated: 2023/11/22 14:15:58 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int received_signal = 0;

t_env *init_env(char **env)
{
	t_env *new;
	t_env *env_lst;
	int i;

	i = -1;
	env_lst = NULL;
	while (env[++i])
	{
		new = lstnew_env(get_name(env[i]), get_value(env[i]));
		ft_lstadd_back(&env_lst, new);
	}
	return (env_lst);
}

void ft_signal_handler(int num)
{
	received_signal = num;
	if (received_signal != 0)
		{
			if (received_signal == SIGINT)
			{
				ft_putstr_fd("\n", 1);
				rl_replace_line("", 0);
				rl_on_new_line();
				rl_redisplay();
			}
			received_signal = 0;
		}
}

void ft_sigquit_handler(int num)
{
	(void)num;
    printf("exit\n");
    exit(EXIT_SUCCESS);
}

// void ft_signal_handler_child(int num)
// {
// 	received_signal = num;
// }

void ft_init_signals()
{
	struct termios term;

	ft_memset(&term, 0, sizeof(struct termios));
	tcgetattr(STDIN_FILENO, &term);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	signal(SIGINT, ft_signal_handler);
	signal(SIGQUIT, SIG_IGN);
	// struct sigaction sa;
	// memset(&sa, 0, sizeof(struct sigaction));
	// sa.sa_handler = ft_signal_handler;
	// sigaction(SIGINT, &sa, NULL);
	// sigaction(SIGQUIT, &sa, NULL);
}

int lst_size(t_env *env_lst)
{
	int index;

	index = 0;
	while (env_lst)
	{
		env_lst = env_lst->next;
		index++;
	}
	return (index);
}

char	*apply_string_env(const char *str1, const char *str2)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(str1)
				+ ft_strlen(str2) + 2));
	if (!dest)
		return (NULL);
	while (*str1)
	{
		dest[i] = *str1;
		str1++;
		i++;
	}
	dest[i++] = '=';
	while (*str2)
	{
		dest[i] = *str2;
		str2++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char **new_env(t_env *env_lst)
{
	char **new_env;
	int i;

	i = 0;
	new_env = (char **)malloc(sizeof(char *) * (lst_size(env_lst) + 1));
	while (env_lst)
	{
		new_env[i++] = apply_string_env(env_lst->name, env_lst->value);
		env_lst = env_lst->next;
	}
	new_env[i] = 0;
	return (new_env);
}

void modif_shlvl(t_data *data)
{
	int shlvl;
	t_env *head;

	head = data->env_lst;
	shlvl = 0;
	while (head)
	{
		if (ft_strcmp(head->name, "SHLVL")==0)
		{
			shlvl = ft_atoi(head->value);
			shlvl++;
			free(head->value);
			head->value = ft_itoa(shlvl);
			break ;
		}
		head = head->next;
	}
}

int main(int ac, char *av[], char *env[])
{
	(void)ac;
	(void)av;
	// t_tok *tok_root;
	t_data data;
	char *buff;
	int status;
	char *path;
	// int i = -1;

	ft_memset(&data, 0, sizeof(t_data));
	data.env_lst = init_env(env);
	while (1)
	{
		ft_init_signals();
		buff = readline("$> ");
		if (!buff)
		{
			ft_sigquit_handler(0);
			break;
		}
		data.cmd = ft_split(buff, ' ');
		if (ft_strcmp("exit", data.cmd[0])==0)
		{
			ft_free(data.cmd);
			free(buff);
			break;
		}
		else if (ft_strcmp("env", data.cmd[0])==0)
			print_env_lst(data.env_lst);
		else if (ft_strcmp("cd", data.cmd[0])==0)
		{
			if (chdir(data.cmd[1]) == -1)
				perror("shell");
			ft_free(data.cmd);
			free(buff);
		}
		else if (ft_strncmp("./", data.cmd[0], 2)==0)
		{
			signal(SIGINT, SIG_IGN);
			data.pid = fork();
			if (data.pid == 0)
			{
				ft_init_signals();
				char *str = (char *)malloc(sizeof(char) * 1000);
				getcwd(str, 1000);
				data.cmd[0] = ft_substr(data.cmd[0], 2, ft_strlen(str) - 2);
				data.cmd[0] = ft_strjoin("/", data.cmd[0]);
				path = ft_strjoin(str, data.cmd[0]);
				free(str);
				if (access(path, 0)==0)
				{
					modif_shlvl(&data);
					if (data.env)
						ft_free(data.env);
					data.env = new_env(data.env_lst);
					execve(path, data.cmd, data.env);
				}
				else
				{
					perror("shell");
					exit(0);
				}
			}
			else
				waitpid(data.pid, &status, 0);
			ft_free(data.cmd);
			free(buff);
		}
		else if (ft_strncmp("../", data.cmd[0], 2)==0)
		{
			data.pid = fork();
			if (data.pid == 0)
			{
				char *str = (char *)malloc(sizeof(char) * 1000);
				getcwd(str, 1000);
				data.cmd[0] = ft_substr(data.cmd[0], 3, ft_strlen(str) - 3);
				data.cmd[0] = ft_strjoin("/", data.cmd[0]);
				path = ft_strjoin(str, data.cmd[0]);
				free(str);
				if (execve(path, data.cmd, data.env) == -1)
				{
					perror("shell");
					exit(0);
				}
			}
			else
				waitpid(data.pid, &status, 0);
			ft_free(data.cmd);
			free(buff);
		}
	}
	if (data.env)
		ft_free(data.env);
	ft_free_lstenv(data.env_lst);
	if (data.var)
		ft_free_lstvar(data.var);
	return (0);
}
