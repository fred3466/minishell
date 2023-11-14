#include "minishell.h"

int	run_exe(int piped, char *path, char *args[], char *const envp[])
{
	pid_t	pid;
	int	status;
	char	***p_args;
	int		res;

	res = -1;
	if (! piped)
	{
		pid = fork();
		if (pid == 0)
		{
			res = execve(path, args, envp);
			my_error("execve");
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
	else
	{
		res = execve(path, args, envp);
		my_error("execve");
	}
	free(path);
	p_args = &args;
//	while (*p_args)
//		free(*p_args);
	// free(args);
	return (res);
}

char	*find_exe(char *env_path, char *fname)
{
	char	*path;
	char	*path_tmp;
	char	**env_path_expl;
	int	i;
	struct	stat	st;
	pid_t	pid;
	int	status;
	char	*cur_env_path;

	env_path_expl = ft_split(env_path, ':');
	i = -1;
	path = NULL;
	while (env_path_expl[++i])
	{
		cur_env_path = env_path_expl[i];
		if (ft_strrchr(cur_env_path, '/') != &(cur_env_path[ft_strlen(cur_env_path) - 1]))
		{
			path_tmp = ft_strjoin(env_path_expl[i], "/");
		}
		else
		{
			path_tmp = env_path_expl[i];
		}
		free(env_path_expl[i]);
		//free(path);
		path = ft_strjoin(path_tmp, fname);
		free(path_tmp);
		if (access(path, F_OK) == 0)
		{
				while (env_path_expl[++i])
					free(env_path_expl[i]);
				free(env_path_expl[i]);
				free(env_path_expl);
				return (path);
		}
		free (path);
		path = NULL;
	}
	free(env_path_expl);
	return (NULL);
}

void	donne_moi_des_io(t_noeud *n_redir, t_tok	*tok_redir)
{
	t_tok	*tok_path;
	char*	fpath;

	tok_path = tok_redir->suivant;
	if(tok_path && tok_path->type == TOK_LIT)
	{
		fpath = tok_path->val;
		if (tok_redir->type == TOK_GRAND)
		{
			n_redir->fd_output = open(fpath, O_CREAT | O_WRONLY | O_TRUNC, 0644);
			if (n_redir->fd_output == -1)
			{
			}
		}
		else if (tok_redir->type == TOK_PETIT)
		{
			n_redir->fd_input= open(fpath, O_RDONLY);
			if (n_redir->fd_input == -1)
			{
			}
		}
		else if (tok_redir->type == TOK_DOUBLE_GRAND)
		{
			n_redir->fd_output = open(fpath, O_CREAT | O_WRONLY | O_APPEND, 0644);
			if (n_redir->fd_output == -1)
			{
			}
		}
		else if (tok_redir->type == TOK_DOUBLE_PETIT)
		{
			n_redir->delim_heredoc = tok_redir->suivant->val;
			tok_redir->suivant->arg_utilisé = 1;
			if (n_redir->fd_output == -1)
			{
			}
		}
		tok_path->arg_utilisé = 1;
		tok_redir->arg_utilisé = 1;
	}
}
char	**donne_moi_des_arguments(t_tok	*ct, int nb_requis)
{
	t_tok	*t = ct;
	char		**args;
	int		nb_args;
	int		i;

	nb_args = 0;
	t = ct->suivant;
	while(t && t->type == TOK_LIT)
	{
		nb_args++;
		t = t->suivant;
	}
//	if (nb_requis !=-1 && nb_args > nb_requis)
		//erreur trop d'arguments'
//	args = ft_calloc(nb_args + 2, sizeof(char **));
	args = ft_calloc(nb_args + 1 + 1, sizeof(char *));
//	args[nb_args] = NULL;
	args[0] = ft_strdup(ct->val);
	if (nb_args > 0)
	{
//		args[0] = ct->suivant->val;
		i = 0;
		t = ct->suivant;
		while(t && t->type == TOK_LIT)
		{
			args[++i] = ft_strdup(t->val);
			t->arg_utilisé = 1;
			t = t->suivant;
		}
	}
	return (args);
}

void	my_error(char *s)
{
	if (errno != 0)
	{
		if (! s)
			perror("");
		else
			perror(s);
	}
	errno = 0;
}
