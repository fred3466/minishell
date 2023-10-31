#include "minishell.h"


int	run_exe(char *path, char *args[], char *const envp[])
{
	pid_t	pid;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		execve(path, args, envp);
		perror("execve");
	}
	else
		waitpid(pid, &status, 0);
	return (0);
}

char	*find_exe(char *env_path, char *fname)
{
	char	*path;
	char	**env_path_expl;
	int	i;
	struct	stat	st;
	pid_t	pid;
	int	status;

	env_path_expl = ft_split(env_path, ':');
	i = -1;
	path = NULL;
	while (env_path_expl[++i])
	{
		path = ft_strjoin(env_path_expl[i], "/");
		path = ft_strjoin(path, fname);
		if (access(path, F_OK) == 0)
		{
				return (path);
		}
		free (path);
		path = NULL;
	}
	return (NULL);
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
	args = ft_calloc(nb_args + 1, sizeof(char **));
	if (nb_args > 0)
	{
//		args[0] = ct->suivant->val;
		args[nb_args] = NULL;
		i = -1;
		t = ct->suivant;
		while(t && t->type == TOK_LIT)
		{
			args[++i] = t->val;
			t->arg_utilisé = 1;
			t = t->suivant;
		}
	}
	return (args);
}
