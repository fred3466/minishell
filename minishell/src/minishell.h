/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:35:44 by fbourgue          #+#    #+#             */
/*   Updated: 2023/10/26 23:36:09 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_C
#define MINISHELL_C

# include <unistd.h>
#include "libft/libft.h"

typedef enum e_tok_typetok
{
	//TOK_VAR_NAME, TOK_VAR_VAL
	TOK_PIPE,
	TOK_GRAND, TOK_PETIT,
	TOK_DOUBLE_GRAND, TOK_DOUBLE_PETIT,
	TOK_LIT
} t_tok_type;

typedef struct s_tok
{
	t_tok_type	type;
	char	*val;
	struct s_tok	*precedent;
	struct s_tok	*suivant;
}	t_tok;

typedef enum e_cmd_type
{
	BUILTIN, PIPE, OPERATEUR_BINAIRE, AND, OR
} t_cmd_type;

typedef struct s_noeud
{
	t_cmd_type		cmd;
	char			*str_valeur;
	struct s_noeud	*noeud_gauche;
	struct s_noeud	*noeud_droit;
}	t_noeud;

t_tok	*create_tok(char **val, t_tok *tok_last);

t_tok	*tok_create(char *val, t_tok_type type);

void	on_spaces(char **s);

#endif
