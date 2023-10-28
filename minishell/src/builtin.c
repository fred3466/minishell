#include "minishell.h"

int	bi_cd(t_tok	*ct, char **sout, char **serr)
{
	char	** args;

	args = donne_moi_des_arguments(ct, 1);
	chdir(args[0]);
	return 0;
}

int bi_pwd(t_tok	*ct, char **sout, char **serr)
{
	*sout = getcwd(NULL, 0);
	return 0;
}

int bi_ls(t_tok	*ct, char **sout, char **serr)
{
	char	*path;
	return 0;
}
