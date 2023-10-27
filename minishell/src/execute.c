#include "minishell.h"

void	_run_exe(char *path, char *args[], char *const envp[])
{
	pid_t	pid;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		//ENV au lieu de null
		execve(path, args, envp);
		perror("execve");
	}
	else
		waitpid(pid, &status, 0);
}

char	*_find_exe(char *env_path, char *fname)
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

int	_interpret_ext(t_tok	*ct, char **sout, char **serr)
{
	int	res;
	char	*exe_path;
	char *path_env;

	res = -1;
	path_env = getenv("PATH");
	exe_path = _find_exe(path_env, ct->val);
	if (exe_path != NULL)
		_run_exe(exe_path, NULL, NULL);

	return (res);
}

int	_interpret_bi(t_tok	*ct, char **sout, char **serr)
{
	int	res;

	res = -1;
	if (ft_strncmp(ct->val, "toto", 2) ==0)
		res = bi_ls(ct, sout, serr);
	if (ft_strncmp(ct->val, "cd", 2) ==0)
		res = bi_cd(ct, sout, serr);
	if (ft_strncmp(ct->val, "pwd", 2) ==0)
		res = bi_pwd(ct, sout, serr);

	return (res);
}

int	interprete(t_tok	*ct)
{
	char	*sout;
	char	*serr;
	int	res;

	if (!ct || !ct->val)
		return (-1);
	sout = NULL;
	serr = NULL;
	res = -1;
	if (ct->type == TOK_LIT)
	{
		res = _interpret_bi(ct, &sout, &serr);
		if (res == -1)
		{
			res = _interpret_ext(ct, &sout, &serr);
		}
	}
//	add_history(ct->val);
	if (sout)
		printf("%s\n", sout);
	return (res);
}
