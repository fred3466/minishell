/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:09:47 by fbourgue          #+#    #+#             */
/*   Updated: 2023/10/26 23:34:40 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	on_spaces(char **s)
{
	char	*c;

	while (*s && (
			**s == ' ' || **s == '\t'
		)
	)
		(*s)++;
}

char	*grab(char **s)
{
	char	*tok_val;
	char	*r;
	char	*sep;
	char	*sep_min;
	char	*seps=" |><\n";
	char	**p_sep;

	r = NULL;
	p_sep = &seps;
	sep_min = ft_strchr(*s, '\0');
	while (**p_sep)
	{
		sep = ft_strchr(*s, **p_sep);
		if (sep && sep < sep_min)
			sep_min = sep;
		(*p_sep)++;
	}


	if (*sep_min == **s &&
			(*sep_min == '|' || *sep_min == '>'||*sep_min == '<'))
	{
//		(*s) += sep_min - *s;
//		(*s) += ft_strlen(r) ;
//	}
//	else
//	{
//		if (**(s + 1) != *sep_min)
			r = ft_substr(*s, sep_min - *s , 1);
//		else
//			r = ft_substr(*s, sep_min - *s , 2);
		(*s) ++; //= ft_strlen(r) + 0;
	}
	else
	{
		r = ft_substr(*s, 0, sep_min - *s);
		(*s) += ft_strlen(r) + 0;
	}
	return (r);
}

t_tok	*parse(char **s)
{
	char	*tok_val;
	t_tok	*tok;
	t_tok	*tok_root;
	t_tok	*tok_last;

	tok_root = NULL;
	tok_last = tok_root;
	while (**s && *s)
	{
		on_spaces(s);
		tok_val = grab(s);
		printf("tok_val:\t%s\n",tok_val);
		tok = create_tok(&tok_val, tok_last);
		if (!tok_root)
			tok_root = tok;
		else
		{
		}
		tok_last = tok;
	}
	return (tok_root);
}

void	dbg_tok(t_tok	*tok_root)
{
	t_tok	*t = tok_root;
	while(t)
	{
		printf("\tDBG\t%d\t%s\n", t->type, t->val);
		t = t->suivant;
	}

}



t_noeud	*create_AST(t_tok *tok_root)
{
	t_noeud	*n;
	t_noeud	*root;
	t_noeud	*prec;
	t_tok		*t;
	t_noeud	*pipe;

	t = tok_root;
	root = NULL;
	prec = NULL;
	while(t != NULL)
	{
		n = noeud_create(t);
		n->precedent = prec;
		if (root == NULL)
			root = n;
		if (prec &&
				(prec->cmd == PIPE || prec->cmd == REDIR_OUT)
				)
		{
			pipe = prec;
			pipe->noeud_gauche = pipe->precedent;
			pipe->noeud_droit = n;

			//pipe->precedent =  pipe->precedent->precedent;
			if (pipe->precedent && pipe->precedent->precedent)
				pipe->precedent->precedent->suivant = n;
			//pipe->suivant =  n->suivant;

//			if (!(root->cmd == PIPE))
//				root = pipe;
		}
		if (prec)
			prec->suivant = n;
		prec = n;
		t = t->suivant;
		while (t && t->arg_utilisé == 1)
			t = t->suivant;
	}
	return (root);
}


void	dbg_tree(t_noeud	*root, char* pre)
{
	t_noeud	*t = root;
//	while(t)
//	{
		if (t)
			printf("%sDBG TREE\t%d\t%s\n",pre, t->cmd, t->str_valeur);
		else
		{
			printf("%sNULL\n",pre);
			return;
		}
//		if (t->noeud_gauche)
//			printf("\t                 G:\t%s\n", t->noeud_gauche->str_valeur);
//		if (t->noeud_droit)
//			printf("\t                 D:\t%s\n", t->noeud_droit->str_valeur);
//		if (t->noeud_gauche)
			dbg_tree(t->noeud_gauche, "\tG: ");
//		if (t->noeud_droit)
			dbg_tree(t->noeud_droit, "\tD: ");
//		if (t->suivant)
			dbg_tree(t->suivant,"");
//		else return;


//		t = t->suivant;
//	}

}



int	main(int ac, char **av, char **env)
{
	t_tok		*tok_root;
	t_noeud	*noeud_root;

//	char	*s = "cat  run.sh > t";
//	char	*s = "ls";

//	char	*tab_cmdline[] = {"ls", "pwd", "cd ..", "pwd", "cd ..", "pwd", "ls",  "\0" };
//	char	*tab_cmdline[] = {"cp toto_to_born toto",  "ls", "cat toto", "rm toto", "\0" };
//	char	*tab_cmdline[] = {"cat /etc/passwd|grep root>>t.txt", "\0" };
//	char	*tab_cmdline[] = {"ls|grep root>>t.txt", "\0" };
//	char	*tab_cmdline[] = {"ls|grep run|fgrep toto|egrep fred>t.txt", "\0" };
//	char	*tab_cmdline[] = {"ls>t.txt", "\0" };
	char	*tab_cmdline[] = {"cat /etc/passwd|grep root", "\0" };


	int	i=-1;

	while(tab_cmdline[++i])
	{
		char	*s = tab_cmdline[i];
		tok_root = parse(&s);
		dbg_tok(tok_root);
		noeud_root = create_AST(tok_root);
//		dbg_tree(noeud_root,"");
		interprete(tok_root, env);
	}
}
