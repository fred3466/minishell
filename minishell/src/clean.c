#include "minishell.h"


void	kill_tok(t_tok *tok_depart)
{
	t_tok	*t;

	t = tok_depart;
	if (!t)
		return ;
	while (t && t->suivant)
		t = t->suivant;;
	while (t)
	{
		if (t->suivant)
		{
			if (DEBUG_CLEAN)
					dprintf(2, "TOK killing %s\n", t->suivant->val);
			if (t->suivant->val)
				free(t->suivant->val);
			free(t->suivant);
			t->suivant = NULL;
		}
		if (t->precedent)
			t = t->precedent;
		else
			break ;
	}
	if (DEBUG_CLEAN)
		dprintf(2, "-TOK killing %s\n", t->val);
	if (t && t->val)
		free(t->val);
//	if (t)
		free(t);
		t = NULL;
}

void	kill_args(t_arg **args)
{
	t_arg **args_save;

	args_save = args;
	while(args && *args)
	{
		free (*args);
		args++;
	}
	free(args_save);
}

void	kill_AST(t_noeud *noeud_depart)
{
	t_noeud	*t;

	t = noeud_depart;
	if (!t)
		return ;
	while (t->suivant)
		t = t->suivant;
	while (t)
	{
		if (t->suivant)
		{
			if (DEBUG_CLEAN)
					dprintf(2, "killing %s\n", t->suivant->str_valeur);
			kill_args(t->suivant->args);
			if (t->suivant->fd_input)
				close (t->suivant->fd_input);
			if (t->suivant->fd_output)
				close (t->suivant->fd_output);
			free(t->suivant->str_valeur);
			free(t->suivant);
			t->suivant = NULL;
		}
		if (t->precedent)
			t= t->precedent;
		else
			break ;
	}
	if (DEBUG_CLEAN)
			dprintf(2, "-killing %s\n", t->str_valeur);
	kill_args(t->args);
	free(t->str_valeur);
	free(t);
}

void	sortir_propre(t_noeud	*noeud_depart, int exit_code)
{
	if (DEBUG_CLEAN)
				dprintf(2, "sortir_propre : t=%s n=%s\n", noeud_depart->tok->val, noeud_depart->str_valeur);
	kill_tok(noeud_depart->tok);
	kill_AST(noeud_depart);
	exit(exit_code);
}
