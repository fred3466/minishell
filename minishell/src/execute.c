#include "minishell.h"


int	_interpret_ext(t_tok	*ct, char **sout, char **serr, char **env)
{
	int	res;
	char	*exe_path;
	char *path_env;
	char	**args;

	res = -1;
	path_env = getenv("PATH");
	exe_path = find_exe(path_env, ct->val);
	args = donne_moi_des_arguments(ct, -1);
//	if(res != -1)
	if (exe_path != NULL)
		res = run_exe(exe_path, args, env);
	ct->brulé = 1;
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
	if(res != -1)
		ct->brulé = 1;
	return (res);
}

int	interprete(t_tok	*ct, char **env)
{
	char	*sout;
	char	*serr;
	int	res;

	if (!ct || !ct->val)
		return (-1);
	sout = NULL;
	serr = NULL;
	res = -1;
	if (ct->type == TOK_LIT && ct->brulé == 0)
	{
		res = _interpret_bi(ct, &sout, &serr);
		if (res == -1)
		{
			res = _interpret_ext(ct, &sout, &serr, env);
		}
	}
//	add_history(ct->val);
	if (sout)
		printf("%s\n", sout);
	return (res);
}
