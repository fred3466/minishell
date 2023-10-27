/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:09:47 by fbourgue          #+#    #+#             */
/*   Updated: 2023/10/26 23:34:40 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	on_spaces(char **s)
{
	char	*c;

	while (*s && (
			**s == ' ' || **s == '\t'
		)
	)
		(*s)++;
}

char	*grab(char **s)
{
	char	*tok_val;
	char	*next_sep;
	char	*r;

	r = NULL;
	next_sep = ft_strchr(*s, ' ');
	if (!next_sep)
		next_sep = ft_strchr(*s, '\n');
	if (!next_sep)
		next_sep = ft_strchr(*s, '\0');
	if (next_sep)
		r = ft_substr(*s, 0, next_sep - *s);
	(*s) += next_sep - *s;
	return (r);
}

t_tok	*parse(char **s)
{
	char	*tok_val;
	t_tok	*tok;
	t_tok	*tok_root;
	t_tok	*tok_last;

	tok_root = NULL;
	tok_last = tok_root;
	while (**s && *s)
	{
		on_spaces(s);
		tok_val = grab(s);
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

void	interpret(t_tok	*tok_root)
{

}

int	main(int ac, char **av)
{
	t_tok	*tok_root;

	char	*s = "cat  run.sh > t";
	tok_root = parse(&s);

	t_tok	*t = tok_root;
	while(t)
	{
		printf("%d\t%s\n", t->type, t->val);
		t = t->suivant;
	}

//	while(*s != 0)
//		write(1, s++, 1);
}
