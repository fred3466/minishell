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
	tok->val = val;
	tok->type = type;
	tok->precedent = NULL;
	tok->suivant = NULL;
	return (tok);
}
