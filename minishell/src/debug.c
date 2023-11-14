#include "minishell.h"

void	dbg_tab(char **t )
{
	while (*t)
	{
		dprintf(2, "%s ", *t);
		(t)++;
	}
	dprintf(2, "\n");
}

void	dbg_tree(t_noeud	*root, char* pre)
{
	t_noeud	*t = root;
//	while(t)
//	{
		if (t)
		{
			char *g="";
			char *d="";
			if (t->noeud_gauche)
				g=t->noeud_gauche->str_valeur;
			if (t->noeud_droit)
				d=t->noeud_droit->str_valeur;
//			printf("\n%sDBG TREE\t[%d]\t[%s] ",pre, t->cmd, t->str_valeur);
			dprintf(2, "\n%sDBG \t[%d]\t(%s) -- [%s] --(%s) ",pre, t->type, g, t->str_valeur, d);
		}
		else
			return;
		if (t->noeud_gauche)
			dbg_tree(t->noeud_gauche, "\tG-> ");
		if (t->noeud_droit)
			dbg_tree(t->noeud_droit, "\tD-> ");
}

void	dbg_flat_AST(t_noeud	*root)
{
	t_noeud	*t = root;

	dprintf(2, "\nflat AST\n---------------\n");
	while(t && t->precedent)
		t = t->precedent;
	while(t)
	{
//		dprintf(2, "\tDBG\t%d\t%s\n", t->type, t->val);
		dprintf(2, " %s", t->str_valeur);
		t = t->suivant;
	}
	dprintf(2, "\n");
}

void	dbg_tok(t_tok	*tok_root)
{
	t_tok	*t = tok_root;

	while(t)
	{
		dprintf(2, "\tDBG\t%d\t%s\n", t->type, t->val);
		t = t->suivant;
	}
	dprintf(2, "\n");
}

void	debug_rebuild_cmdline(t_noeud *root)
{
	t_noeud *n;

	n = root;
	while(n->precedent)
		n = n->precedent;
	while (n)
	{
		if (DEBUG_EXEC)
			dprintf(2, "%s ", n->str_valeur);
//		dbg_tab(n->args);
		n = n->suivant;
	}
	if (DEBUG_EXEC)
		dprintf(2, "\n");

}
