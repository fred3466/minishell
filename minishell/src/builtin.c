#include "minishell.h"

int	bi_cd(t_noeud	*n)
{
	chdir(n->args[0]);
	return 0;
}

int bi_pwd()
{
	char	*sout;
	sout = getcwd(NULL, 0);
	printf("%s\n",sout);
	free(sout);
	return 0;
}
