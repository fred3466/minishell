#include "minishell.h"


void	kill_tok(t_tok *root)
{
	t_tok	*t;

	t = root;
	while (t && t->suivant)
		t = t->suivant;;
	while (t && t->precedent)
	{
		if (t && t->suivant)
		{
//			dprintf(2, "killing %s\n", t->suivant->val);
			if (t->suivant->val)
				free(t->suivant->val);
			free(t->suivant);
			t->suivant = NULL;
		}
		t = t->precedent;
	}
//	dprintf(2, "killing %s\n", t->val);
	if (t->val)
		free(t->val);
	free(t);
}

void	kill_args(char	 **args)
{
	char **args_save;

	args_save = args;
	while(args && *args)
	{
		free (*args);
		args++;
	}
	free(args_save);
}

void	kill_AST(t_noeud *root)
{
	t_noeud	*t;

	t = root;
	while (t->suivant)
		t = t->suivant;
	while (t && t->precedent)
	{
		if (t && t->suivant)
		{
//			dprintf(2, "killing %s\n", t->suivant->str_valeur);
			kill_args(t->suivant->args);
			free(t->suivant->str_valeur);
			free(t->suivant);
			t->suivant = NULL;
		}
		t = t->precedent;
	}
//	dprintf(2, "killing %s\n", t->str_valeur);
	kill_args(t->args);
	free(t->str_valeur);
	free(t);
}
