#include "minishell.h"

int	bi_cd(t_tok	*ct, char **sout, char **serr)
{
	chdir(ct->suivant->val);
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
