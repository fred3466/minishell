
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

void	on_spaces(char **s)
{
	char	*c;
	while(*s && (
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
	next_sep =ft_strchr(*s, ' ');
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
	while(**s && *s)
	{
		on_spaces(s);
		tok_val = grab(s);
		tok = tok_create(tok_val, TOK_CMD);
		if (!tok_root)
			tok_root = tok;
		else
		{
			tok_last->suivant = tok;
			tok->precedent = tok_last;
		}
		tok_last = tok;
	}
	return (tok_root);
}


int	main(int ac, char **av)
{
	t_tok	*tok_root;

	//  echo "toto" > toto.txt
//	char	*cmd_line = readline(">");
	char	*s = "   abc def";
	tok_root = parse(&s);

	t_tok	*t = tok_root;
	while(t)
	{
		printf("%s\n", t->val);
		t = t->suivant;
	}

//	while(*s != 0)
//		write(1, s++, 1);
}
