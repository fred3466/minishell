


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
	TOK_CMD
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
	char					*str_valeur;
	struct s_noeud	*noeud_gauche;
	struct s_noeud	*noeud_droit;
}	t_noeud;


#endif
