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

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
# include <pthread.h>

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
	int brulé;
	struct s_tok	*precedent;
	struct s_tok	*suivant;
}	t_tok;

//deprecated
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

int	interprete(t_tok	*ct, char **env);
char	*find_exe(char *env_path, char *fname);
int	run_exe(char *path, char *args[], char *const envp[]);
char	**donne_moi_des_arguments(t_tok	*ct, int nb_requis);

int	bi_ls(t_tok	*ct, char **sout, char **serr);
int	bi_cd(t_tok *ct, char **sout, char **serr);
int	bi_pwd(t_tok *ct, char **sout, char **serr);


#endif
