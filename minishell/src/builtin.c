#include "minishell.h"

int bi_env(t_noeud *n, t_data *data)
{
	print_env_lst(data->env_lst);
	return (0);
}

int	bi_equal(t_noeud	*n)
{
	int	ret;

	ret = chdir(n->args[0]);
	return ret;
}

int	bi_cd(t_noeud	*n)
{
	int	ret;

	ret = chdir(n->args[0]);
	return ret;
}

int bi_pwd()
{
	char	*sout;
	sout = getcwd(NULL, 0);
	if (! sout)
		return (-1);
	printf("%s\n",sout);
	free(sout);
	return 0;
}

int bi_export(t_noeud *n, t_data *data)
{
	
}
