/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:38:25 by fbourgue          #+#    #+#             */
/*   Updated: 2023/10/26 23:35:59 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char* _identify_separator(t_tok_type *type, char **val) {
	char	*v;

	v = NULL;
	if (ft_strncmp(*val, ">>", 2) == 0)
	{
		*type = TOK_DOUBLE_GRAND;
		v = ">>";
		(**val)++;
	}
	else if (ft_strncmp(*val, "<<", 2) == 0)
	{
		*type = TOK_DOUBLE_PETIT;
		v = "<<";
		(**val)++;
	}
	else if (**val == '>') {
		*type = TOK_GRAND;
		v = ">";
	}
	else if (**val == '<') {
		*type = TOK_PETIT;
		v = "<";
	}
	else if (**val == '|') {
		*type = TOK_PIPE;
		v = "|";
	}
	return v;
}

t_tok	*create_tok(char **val, t_tok *tok_last)
{
	t_tok		*tok;
	t_tok_type	type;
	char		*v;

	v = NULL;
	v = _identify_separator(&type, val);
	if (v != NULL)
		(*val)++;
	else
	{
		type = TOK_LIT;
		v = *val;
		(*val) += ft_strlen(*val);
	}
	tok = tok_create(v, type);
	if (tok_last)
		tok_last->suivant = tok;
	tok->precedent = tok_last;
	if (**val)
	{
		on_spaces(val);
		tok->suivant = create_tok(val, tok);
	}
	return (tok);
}
