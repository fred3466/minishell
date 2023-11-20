/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:35:44 by fbourgue          #+#    #+#             */
/*   Updated: 2023/11/20 14:28:22 by slecoq           ###   ########.fr       */
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
#  define DEBUG_AST 1
# endif

# ifndef DEBUG_PARSE
#  define DEBUG_PARSE 1
# endif

# ifndef DEBUG_EXEC
#  define DEBUG_EXEC 1
# endif

# ifndef DEBUG_CLEAN
#  define DEBUG_CLEAN 1
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

typedef struct s_env_var
{
	char 		*name;
	char 		*value;
	struct s_env_var *next;
}			t_env_var;

typedef struct s_env
{
	char *name;
	char *value;
	struct s_env *next;
}			t_env;

typedef struct s_data
{
	char 		**env;
	char **cmd;
	struct s_arg *arg;
	struct s_env *env_lst;
	struct s_env_var *var;
	int pid;
}				t_data;

char	*grab(char **s);
char	**quotes(char **s);
t_tok		*create_tok(char **val, t_tok *tok_last);

t_tok		*tok_create(char *val, t_tok_type type);
t_noeud	*noeud_create(t_tok *t, t_noeud *rec);

void	dbg_tab(char **t);

int	interprete(int piped, t_noeud *n, t_data *data);
int	_interpret_bi(t_noeud	*n, t_data *data);
char			*find_exe(char *env_path, char *fname);
int	run_exe(int piped, char *path, char *args[], char *const envp[]);
char			**donne_moi_des_arguments(t_tok	*ct, int nb_requis);
void			donne_moi_des_io(t_noeud *n, t_tok	*ct);
void pipe_show(int piped,t_pipe	*pipe_ret, t_noeud	*n, t_data *data);
void 		my_heredoc(t_noeud	*n);
void	my_error(char *s);

int			bi_cd(t_noeud *n);
int			bi_pwd();
int bi_export(t_noeud *n, t_data *data);

void	dbg_tab(char **t );
void	dbg_tree(t_noeud	*root, char* pre);
void	debug_rebuild_cmdline(t_noeud *root);
void	dbg_tok(t_tok	*tok_root);
void	dbg_flat_AST(t_noeud	*root);

void	kill_tok(t_tok *root);
void	kill_AST(t_noeud *root);
void	sortir_propre(t_noeud	*noeud_root, int exit_code);

void	ft_free(char **str);
void ft_free_lstvar(t_env_var *lst);
void ft_free_lstenv(t_env *lst);
void ft_free_cell(t_env *lst);

t_env *add_var_env(t_env *env_lst, t_env_var *var);
t_env *remove_var_env(t_env *env_lst, t_env_var *var);
t_env	*ft_lstlast(t_env *lst);
void	ft_lstadd_back(t_env **lst, t_env *new);
t_env *lstnew_env(char *name, char *value);
t_env_var *lstnew_var(char *name, char *value);
void print_env_lst(t_env *env_lst);

char *get_value(char *str);
char *get_name(char *str);

int	ft_array_len(char **array);
char *swap_value(char *old, char *new);

t_env *init_env(char **env);
char **new_env(t_env *env_lst);
char	*apply_string_env(const char *str1, const char *str2);
int lst_size(t_env *env_lst);

#endif
