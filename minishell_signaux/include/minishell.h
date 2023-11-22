/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:26:40 by slecoq            #+#    #+#             */
/*   Updated: 2023/11/16 17:52:01 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <termios.h>
#include <stdbool.h>

#include <sys/stat.h>

#include <errno.h>

typedef struct s_env_var
{
	char 		*name;
	char 		*value;
	struct s_env_var *next;
}			t_env_var;

typedef struct s_env
{
	char *name;
	char *value;
	struct s_env *next;
}			t_env;

typedef struct s_data
{
	char 		**env;
	char **cmd;
	struct s_arg *arg;
	struct s_env *env_lst;
	struct s_env_var *var;
	int pid;
}				t_data;

void	ft_free(char **str);
void ft_free_lstvar(t_env_var *lst);
void ft_free_lstenv(t_env *lst);
void ft_free_cell(t_env *lst);

char *swap_value(char *old, char *new);
int	ft_array_len(char **array);

char *get_value(char *str);
char *get_name(char *str);

t_env *add_var_env(t_env *env_lst, t_env_var *var);
t_env *remove_var_env(t_env *env_lst, t_env_var *var);

t_env	*ft_lstlast(t_env *lst);
void	ft_lstadd_back(t_env **lst, t_env *new);
t_env *lstnew_env(char *name, char *value);
t_env_var *lstnew_var(char *name, char *value);
void print_env_lst(t_env *env_lst);

#endif