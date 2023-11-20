/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:35:02 by fbourgue          #+#    #+#             */
/*   Updated: 2023/10/26 23:36:22 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tok	*tok_create(char *val, t_tok_type type)
{
	t_tok	*tok;

	tok = (t_tok *)ft_calloc(1, sizeof(t_tok));
	if (!tok)
		return (NULL);
	tok->val = ft_strdup(val);
	tok->type = type;
	tok->precedent = NULL;
	tok->suivant = NULL;
	tok->arg_utilisé = 0;
	return (tok);
}

t_node_type	_from_tok_type_to_cmd_type(t_tok_type t_type)
{
	if (t_type == TOK_PIPE)
		return(PIPE);
	else if (t_type == TOK_GRAND)
		return(REDIRECTION);
	else if (t_type == TOK_PETIT)
		return(REDIRECTION);
	else if (t_type == TOK_DOUBLE_GRAND)
		return(REDIRECTION);
	else if (t_type == TOK_DOUBLE_PETIT)
		return(HEREDOC);
	else if (t_type == TOK_LIT)
	{
		return(LITTERAL);
	}
		return(INCONNU);

}

t_noeud	*noeud_create(t_tok *t, t_noeud *prec)
{
	t_noeud	*n;

	n = (t_noeud *)ft_calloc(1, sizeof(t_noeud));
	if (!n)
		return (NULL);
	n->type = _from_tok_type_to_cmd_type(t->type);
	n->precedent = prec;
	n->delim_heredoc = NULL;
//	n->fd_heredoc = 0;
	n->fd_input = 0;
	n->fd_output = 0;
	n->str_valeur = ft_strdup(t->val);
	n->tok = t;
	if (t->type == TOK_LIT)
		n->args = donne_moi_des_arguments(t, -1);
	if (n->type == REDIRECTION || n->type == HEREDOC)
		donne_moi_des_io(n->precedent, t);
	return (n);
}
