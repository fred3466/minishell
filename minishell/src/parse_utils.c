
#include "minishell.h"



char	*_grab_to_sep(char **s)
{
	char	*sep;
	char	*sep_min;
	char	*seps=" |><\n=";
	char	**p_sep;
	char	*r;

	p_sep = &seps;
	sep_min = ft_strchr(*s, '\0');
	while (**p_sep)
	{
		sep = ft_strchr(*s, **p_sep);
		if (sep && sep < sep_min)
			sep_min = sep;
		(*p_sep)++;
	}
	if (*sep_min == **s &&	(*sep_min == '|' || *sep_min == '>'||*sep_min == '<'||*sep_min == '='))
	{
		if (*sep_min == *(*s+1))
			sep_min+=2;
		else
			sep_min+=1;
//			r = ft_substr(*s, sep_min - *s , 1);
//		(*s) ++; //= ft_strlen(r) + 0;
	}
//	else
//	{
		r = ft_substr(*s, 0, sep_min - *s);
		(*s) += ft_strlen(r) + 0;
//	}
	return (r);
}
char	*grab(char **s)
{
	char	*r;
	char	**p_quotes;

	r = NULL;
	p_quotes = quotes(s);
	if (*p_quotes)
	{
		r = ft_substr(*s, p_quotes[0] - *s, p_quotes[1] - p_quotes[0]);
		free (p_quotes);
		(*s) += ft_strlen(r) + 2;
		return (r);
	}
	free (p_quotes);
	r = _grab_to_sep(s);

	return (r);
}
