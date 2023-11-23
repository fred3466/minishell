/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:09:47 by fbourgue          #+#    #+#             */
/*   Updated: 2023/11/23 13:24:39 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	on_spaces(char **s_init)
{
	char	*c;
	char	**s = s_init;

	while (*s && (
			**s == ' ' || **s == '\t' || **s == '\n'
		)
	)
		(*s)++;
}


t_tok	*parse(char *s_init)
{
	char		*tok_val;
	char	*save_tok_val;
	t_tok	*tok;
	t_tok	*tok_root;
	t_tok	*tok_last;
	char	**s = &s_init;

	// char *toto=ft_strdup(*s_init);
//	s = s_init;
	tok_root = NULL;
	tok_last = tok_root;
	while (**s && *s)
	{
		on_spaces(s);
		if(! **s)
			break ;
		tok_val = grab(s);
//		printf("tok_val:\t%s\n",tok_val);
		save_tok_val = tok_val;
		tok = create_tok(&tok_val, tok_last);
		free (save_tok_val);
		if (!tok_root)
			tok_root = tok;
		else
		{
		}
		tok_last = tok;
	}
	return (tok_root);
}

void	_ast_pipe(t_noeud *n)
{

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
		n = noeud_create(t, prec);
		if (root == NULL)
			root = n;
		if (prec && prec->type == PIPE)
		{
			pipe = prec;
			pipe->noeud_gauche = pipe->precedent;
			pipe->noeud_droit = n;

			if (root->type != PIPE)
				root = pipe;
			else
			{
				pipe->noeud_gauche = root;
				root = pipe;
			}
		}
		else if (prec && prec->type == EQUAL)
		{
			pipe = prec;
			pipe->noeud_gauche = pipe->precedent;
			pipe->noeud_droit = n;

			if (root->type != PIPE)
				root = pipe;
			else
			{
				pipe->noeud_gauche = root;
				root = pipe;
			}
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

int	main(int ac, char **av, char **env)
{
	t_tok		*tok_root;
	t_noeud	*noeud_root;
	t_data data;

	char	*line;
	char	*line_copy;
	int save_in;
	int	save_out;
	int	i;

	line = NULL;
	if (ac >= 2)
		return (ft_printf("Aucun argument n'est necessaire pour lancer minishell\n"), 0);
	save_in = dup(0);
	save_out = dup(1);
	ft_memset(&data, 0, sizeof(t_data));
	data.env_lst = init_env(env);
	data.env = new_env(data.env_lst);
	while(1)
	{
		line = readline("$>");
		if (!line)
			break ;
		tok_root = parse(line);
		free(line);
		noeud_root = create_AST(tok_root);
		if (DEBUG_AST)
		{
			dbg_tree(noeud_root,"");
			dbg_flat_AST(noeud_root);
		}
		dup2(1, save_out);
		dup2(0, save_in);
		interprete(0, noeud_root, &data);
		kill_tok(tok_root);
		kill_AST(noeud_root);
		dup2(save_out, 1);
		dup2(save_in, 0);
	}
	ft_free_lstenv(data.env_lst);
	ft_free(data.env);
}
