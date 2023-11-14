/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:09:47 by fbourgue          #+#    #+#             */
/*   Updated: 2023/10/27 16:11:09 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	on_spaces(char **s)
{
	char	*c;

	while (*s && (
			**s == ' ' || **s == '\t' || **s == '\n'
		)
	)
		(*s)++;
}

char	*grab(char **s)
{
	char	*tok_val;
	char	*r;
	char	*sep;
	char	*sep_min;
	char	*seps=" |><\n";
	char	**p_sep;

	r = NULL;
	p_sep = &seps;
	sep_min = ft_strchr(*s, '\0');
	while (**p_sep)
	{
		sep = ft_strchr(*s, **p_sep);
		if (sep && sep < sep_min)
			sep_min = sep;
		(*p_sep)++;
	}
	if ((sep_min == *s) && (sep_min == (*s)+1))
		sep_min+=2;
	if (*sep_min == **s &&
			(*sep_min == '|' || *sep_min == '>'||*sep_min == '<'))
	{
			r = ft_substr(*s, sep_min - *s , 1);
		(*s) ++; //= ft_strlen(r) + 0;
	}
	else
	{
		r = ft_substr(*s, 0, sep_min - *s);
		(*s) += ft_strlen(r) + 0;
	}
	return (r);
}

t_tok	*parse(char **s_init)
{
	char		*tok_val;
	t_tok	*tok;
	t_tok	*tok_root;
	t_tok	*tok_last;
	char	**s;

	// char *toto=ft_strdup(*s_init);
	s = s_init;
	tok_root = NULL;
	tok_last = tok_root;
	while (**s && *s)
	{
		on_spaces(s);
		if(! **s)
			break ;
		tok_val = grab(s);
//		printf("tok_val:\t%s\n",tok_val);
		tok = create_tok(&tok_val, tok_last);
		if (!tok_root)
			tok_root = tok;
		else
		{
		}
		tok_last = tok;
	}
	return (tok_root);
}

t_noeud	*create_AST(t_tok *tok_root)
{
	t_noeud	*n;
	t_noeud	*root;
	t_noeud	*prec;
	t_tok		*t;
	t_noeud	*pipe;

	t = tok_root;
	root = NULL;
	prec = NULL;
	while(t != NULL)
	{
		n = noeud_create(t, prec);
		if (root == NULL)
			root = n;
		if (prec &&
				(prec->type == PIPE /*|| prec->cmd == REDIR_OUT*/)
				)
		{
			pipe = prec;
			pipe->noeud_gauche = pipe->precedent;
			pipe->noeud_droit = n;

//			if (pipe->precedent && pipe->precedent->precedent)
//				pipe->precedent->precedent->suivant = n;

			if (root->type != PIPE)
				root = pipe;
			else
			{
				pipe->noeud_gauche = root;
				root = pipe;
			}
		}
		if (prec)
			prec->suivant = n;
		prec = n;
		t = t->suivant;
		while (t && t->arg_utilisé == 1)
			t = t->suivant;
	}
	return (root);
}

int	main(int ac, char **av, char **env)
{
	t_tok		*tok_root;
	t_noeud	*noeud_root;

//	char	*tab_cmdline[] = {"ls", "\0" };
//	char	*tab_cmdline[] = {"ls", "pwd", "cd ..", "pwd", "cd ..", "pwd", "ls",  "\0" };
//	char	*tab_cmdline[] = {"cp toto_to_born toto",  "ls", "cat toto", "rm toto", "\0" };
//	char	*tab_cmdline[] = {"cat /etc/passwd|grep root", "\0" };
//	char	*tab_cmdline[] = {"grep root", "\0" };
//	char	*tab_cmdline[] = {"ls|grep root>>t.txt", "\0" };
//	char	*tab_cmdline[] = {"ls|grep run|fgrep run|egrep run", 0 };
//	char	*tab_cmdline[] = {"ls|rev", "\0" };
//	char	*tab_cmdline[] = {"ls -al -h|rev", "\0" };
//	char	*tab_cmdline[] = {"ls -al -h", "\0" };
//	char	*tab_cmdline[] = {"ls -alh|cat|rev|cat|rev", "\0" };

//		char	*tab_cmdline[] = {"rev </etc/passwd", "\0" };
//	char	*tab_cmdline[] = {"rev<<.", "\0" };

	char	**tab_cmdline;
	char	*line;
	char	*line_copy;
	int	fd;

	fd = -1;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
	}
	// if (fd == -1)
	// {
	// 	// if(ac == 1)
	// 	// {
	// 		// tab_cmdline[0] = av[1];
	// 	// }else{
	// 	tab_cmdline = malloc(sizeof(char*)*(ac+1));
	// 	tab_cmdline = ft_memmoveq(tab_cmdline, av, ac);
	// 	tab_cmdline[ac]=0;
	// 	//}
	// }

	int	i;

	if(fd!=-1)
	{
		line = get_next_line(fd);
	}else{
		// i = 1;
		// line = tab_cmdline[i];
	}

	while(1)
	{
		printf("\n%s-------------------\n",line);
		line_copy = ft_strdup(line);
		tok_root = parse(&line_copy);
		if (DEBUG_PARSE)
			dbg_tok(tok_root);
		noeud_root = create_AST(tok_root);
		if (DEBUG_AST)
			dbg_tree(noeud_root,"");
//		dbg_flat_AST(noeud_root);
		kill_tok(tok_root);
		debug_rebuild_cmdline(noeud_root);
		interprete(0, noeud_root, env);
		kill_AST(noeud_root);
		// if (line_copy)
		// 	free (line_copy);
		if(fd!=-1)
		{
			// if (ft_strlen(line) >= 0)
			free(line);
			line = get_next_line(fd);
		}else{
			// i++;
			// line = tab_cmdline[i];
		}
		if (!line)
		{
			free(line);
			break ;
		}
		// perror("");
		my_error("main ");
		 errno = 0;
	}
	if(fd!=-1)
		close(fd);
}
