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
#include <errno.h>

#include "libft/libft.h"

# ifndef DEBUG_AST
#  define DEBUG_AST 0
# endif

# ifndef DEBUG_PARSE
#  define DEBUG_PARSE 0
# endif

# ifndef DEBUG_EXEC
#  define DEBUG_EXEC 0
# endif

# ifndef DEBUG_CLEAN
#  define DEBUG_CLEAN 0
# endif

typedef enum e_tok_type
{
	INCONNU,
	//TOK_VAR_NAME, TOK_VAR_VAL
	TOK_PIPE, TOK_LIT,
	TOK_GRAND, TOK_PETIT,
	TOK_DOUBLE_GRAND, TOK_DOUBLE_PETIT
} t_tok_type;

typedef struct s_tok
{
	t_tok_type	type;
	char	*val;
	int arg_utilisé;
	struct s_tok	*precedent;
	struct s_tok	*suivant;
}	t_tok;

typedef enum e_node_type
{
	NODE_TYPE_INCONNU,
	PIPE,
	LITTERAL,
	REDIRECTION,
	HEREDOC
} t_node_type;

typedef struct s_pipe
{
	int	fds[2];
	pid_t	pid_gauche;
	pid_t	pid_droit;
	int	res_gauche;
	int	res_droit;
} t_pipe;

typedef struct s_noeud
{
	t_tok				*tok;
	t_node_type		type;
	char					*str_valeur;
	struct s_noeud	*noeud_gauche;
	struct s_noeud	*noeud_droit;
	char					**args;
	struct s_noeud	*precedent;
	struct s_noeud	*suivant;
	int					fd_output;
	int						fd_input;
//	int					fd_heredoc;
	char					*delim_heredoc;
}	t_noeud;

char	*grab(char **s);
char	**quotes(char **s);
t_tok		*create_tok(char **val, t_tok *tok_last);

t_tok		*tok_create(char *val, t_tok_type type);
t_noeud	*noeud_create(t_tok *t, t_noeud *rec);

void	dbg_tab(char **t);

int			interprete(int piped, t_noeud *n, char **env);
char			*find_exe(char *env_path, char *fname);
int	run_exe(int piped, char *path, char *args[], char *const envp[]);
char			**donne_moi_des_arguments(t_tok	*ct, int nb_requis);
void			donne_moi_des_io(t_noeud *n, t_tok	*ct);
void			pipe_show(int piped, t_pipe *pipe_ret, t_noeud	*n, char **env);
void 		my_heredoc(t_noeud	*n);
void	my_error(char *s);

int			bi_cd(t_noeud *n);
int			bi_pwd();

void	dbg_tab(char **t );
void	dbg_tree(t_noeud	*root, char* pre);
void	debug_rebuild_cmdline(t_noeud *root);
void	dbg_tok(t_tok	*tok_root);
void	dbg_flat_AST(t_noeud	*root);

void	kill_tok(t_tok *root);
void	kill_AST(t_noeud *root);
void	sortir_propre(t_noeud	*noeud_root, int exit_code);


#endif
