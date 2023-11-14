#include "minishell.h"

int	_interpret_ext(int piped, t_noeud	*n, char **env)
{
	int	res;
	char	*exe_path;
	char *path_env;
	char	**args;

	res = -1;
	path_env = getenv("PATH");
	exe_path = find_exe(path_env, n->str_valeur);
	args = n->args;
//	if(res != -1)
	if (exe_path != NULL)
	{
		if (DEBUG_EXEC)
		{
			dprintf(2, "\t\t\tRUN\t%s ", exe_path);
			dbg_tab(args);
			dprintf(2, "\n");
		}
		if (n->fd_output)
		{
			dup2(n->fd_output, STDOUT_FILENO);
			close(n->fd_output);
		}
		if (n->fd_input)
		{
			dup2(n->fd_input, STDIN_FILENO);
			close(n->fd_input);
		}
		if (n->delim_heredoc)
		{
			my_heredoc(n);
			dup2(n->fd_input, STDIN_FILENO);
			close(n->fd_input);
			piped = 1;
		}

		res = run_exe(piped, exe_path, args, env);
		my_error("_interpret_ext");
		// free (exe_path);
	}
	else
		my_error("Commande introuvable ");
//	ct->arg_utilisé = 1;
	return (res);
}

int	_interpret_bi(t_noeud	*n)
{
	int	res;

	res = -1;
//	if (ft_strncmp(n->str_valeur, "toto", 2) ==0)
//		res = bi_ls(n, sout, serr);
	if (ft_strncmp(n->str_valeur, "cd", ft_strlen(n->str_valeur)) ==0)
		res = bi_cd(n);
	if (ft_strncmp(n->str_valeur, "pwd", ft_strlen(n->str_valeur)) ==0)
		res = bi_pwd();
//	if(res != -1)
//		ct->arg_utilisé = 1;
	return (res);
}

int	interprete(int piped, t_noeud *n, char **env)
{
	int		res;
	t_pipe	*pipe_ret;

	if (!n || !n->str_valeur)
		return (-1);
	res = -1;

	if (n->type == LITTERAL)
	{
//		dprintf(2, "\n***process LITTERAL %s\n", n->str_valeur);
		res = _interpret_bi(n);
		if (res == -1)
		{
			if (DEBUG_EXEC)
				dprintf(2, "\t\tDEB process EXTERNE %s\n", n->str_valeur);
			res = _interpret_ext(piped, n, env);
			if (DEBUG_EXEC)
				dprintf(2, "\t\tFIN process EXTERNE %s\n", n->str_valeur);
			if (res == -1)
			{
				my_error("[interprete]");
			}
		}
		// if (errno != 0)
	}
	else if (n->type == PIPE)
	{
		if (DEBUG_EXEC)
			dprintf(2,"\n***process PIPE %s\n", n->str_valeur);
		pipe_ret = malloc(sizeof(t_pipe));
//		while (n->noeud_gauche && n->noeud_gauche->type == PIPE)
//		{
//			pipe_show(piped, n->noeud_gauche, env, 1);
//		}
		pipe_show(piped, pipe_ret, n, env);
		free(pipe_ret);
		if (DEBUG_EXEC)
		{
			dprintf(2, "***FIN process PIPE %s\n", n->str_valeur);
			dprintf(2,"Retour de pipe : %d et %d\n", pipe_ret->res_gauche,pipe_ret->res_droit);
		}

		if (res == -1)
		{
		}
	}
	else if (n->type == REDIRECTION)
	{
		if (DEBUG_EXEC)
			dprintf(2,"\n***process REDIRECTION %s\n", n->str_valeur);
	}

//	add_history(ct->val);
	my_error("");
	return (res);
}
