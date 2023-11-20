
#include "minishell.h"


void	__run_source(t_pipe *pipe_ret, t_noeud	*n, char **env)
{
	pipe_ret->pid_gauche = fork();
	if (pipe_ret->pid_gauche  < 0)
		my_error("Fork child 1 ");
	else if (pipe_ret->pid_gauche  == 0)
	{
		if (DEBUG_EXEC)
			dprintf(2,"\tEXEC noeud gauche\n");
		close(pipe_ret->fds[0]);
		dup2(pipe_ret->fds[1], 1);
		pipe_ret->res_gauche = interprete(1 ,n->noeud_gauche, env);
		my_error("__run_source ");
	}
}

void	__run_dest(t_pipe *pipe_ret, t_noeud	*n, char **env)
{
	pipe_ret->pid_droit = fork();
	if (pipe_ret->pid_droit < 0)
		my_error("Fork child 2 ");
	else if (pipe_ret->pid_droit == 0)
	{
		if (DEBUG_EXEC)
			dprintf(2,"\tEXEC noeud droit\n");
		close(pipe_ret->fds[1]);
		dup2(pipe_ret->fds[0], 0);
		pipe_ret->res_droit = interprete(1, n->noeud_droit, env);
		my_error("__run_dest ");
	}
}

void pipe_show(int piped,t_pipe	*pipe_ret, t_noeud	*n, char **env)
{
	int pid;
	int	status;
//	t_pipe	*pipe_ret;

//	pipe_ret = malloc(sizeof(t_pipe));
	if (pipe(pipe_ret->fds) == -1)
		my_error("Pipe ");

	__run_source(pipe_ret, n, env);
	__run_dest(pipe_ret, n, env);
	close(pipe_ret->fds[0]); close(pipe_ret->fds[1]);

	my_error("pipe_show 1 ");
//	while ((pid = wait(&status)) != -1)
//		fprintf(stderr, "====> %s : pid = %i\n",n->str_valeur, pid);
//		if (DEBUG_EXEC)
//			fprintf(stderr, "process %d exits with %d\n", pid, WEXITSTATUS(status));

	waitpid(pipe_ret->pid_gauche, NULL, 0);
	waitpid(pipe_ret->pid_droit, NULL, 0);
	my_error("pipe_show 2 ");
	if (DEBUG_EXEC)
		dprintf(2,"Retour de pipe : %d et %d\n", pipe_ret->res_gauche,pipe_ret->res_droit);
	if (piped)
	{
//		exit(0);
		sortir_propre(n, 0);
	}

//	close(pipe_ret->fds[1]);
//	waitpid(pipe_ret->pid_gauche, NULL, 0);
//	waitpid(pipe_ret->pid_droit, NULL, 0);
//	exit(0);
}


int is_heredoc_delim(char *s, char 	*p_fin)
{
	int	found;
	int	sz;

	sz = ft_strlen(p_fin);
	found = ft_strncmp(s, p_fin, sz);
	return (found == 0);
}

void my_heredoc(t_noeud	*n)
{
	int		fd_pipe[2];
	int		pid;
	char		*line;
	int		status;

	pipe(fd_pipe);
	pid = fork();
	if (pid == 0)
	{
		char *acc =ft_strdup("");
		char	*tmp;

		close(fd_pipe[0]);
		while (1)
		{
			line = readline("> ");
			tmp =acc;
//			char * sub;
//			char *n = ft_strchr(acc, '\n');
//			sub=ft_substr(acc, n-acc, ft_strchr('\0')-acc);
//			acc = ft_strjoin(acc,line);
//			ft_printf(line);
 			if (is_heredoc_delim(line, n->delim_heredoc))
 			{
//				ft_putstr_fd(fd_pipe[1], acc);
//				ft_putstr_fd(fd_pipe[1], "\n");
// 				n->fd_heredoc=fd_pipe[0];

// 				n->fd_input=fd_pipe[0];
				break ;
 			}
			else
			{
				ft_putstr_fd(fd_pipe[1], line);
				ft_putstr_fd(fd_pipe[1], "\n");
			}
		}
//		exit(0);
		sortir_propre(n, 0);
	}
	else
	{
//		(pid = wait(&status)) != -1;
		waitpid(pid, &pid, 0);
		n->fd_input = fd_pipe[0];

		//		signal(SIGQUIT, ft_sigquit_handler);
//		g_minishell.signint_child = false;
		close(fd_pipe[1]);
	}
}

