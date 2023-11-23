
#include "minishell.h"

char	*find_next_sep(char **s)
{
	char	*sep_min;
	char	*sep;
	char	*seps;

//	seps=" |><\n=,;.";
	seps = TOK_SEPS;
	sep_min = ft_strchr(*s, '\0');
	while (*seps)
	{
		sep = ft_strchr(*s, *seps);
		if (sep && (sep < sep_min))
			if ((*sep == '\"') || (*sep =='\''))
			{
				if ( (!escape(*s, sep)))
					sep_min = sep;
			}
			else
				sep_min = sep;
		(seps)++;
	}
<<<<<<< HEAD
	if (sep_min == *s)
		return (find_next_sep(s+1));
=======
>>>>>>> 0638308f0a99953bbfc96934b5138f808ae2ad15
	return (sep_min);
}

char	*_grab_to_sep(char **s)
{
	char	*sep_min;
	char	*r;

	sep_min = find_next_sep(s);
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
t_grab_res	*grab(char **s)
{
<<<<<<< HEAD
	t_grab_res	*gr;
	t_quotes_res	*quote_res;
	char	*sep_min;

	gr = grab_res_create();
	quote_res = quotes(s);
	sep_min = find_next_sep(s);
	if (quote_res && quote_res->quote_deb  == *s && (!quote_res->b_in_single_quotes))
=======
	char	*r;
	char	**p_quotes;
	char	*sep_min;

	r = NULL;
	p_quotes = quotes(s);
	sep_min = find_next_sep(s);
	if (p_quotes && *p_quotes && p_quotes[0]  == *s)
>>>>>>> 0638308f0a99953bbfc96934b5138f808ae2ad15
	{
//		if (p_quotes[0]  != *s)
//		{
//			r = ft_substr(*s, 0, p_quotes[0] - *s);
//			(*s) += ft_strlen(r);
//		}
//		else
//		{
<<<<<<< HEAD
			gr->val = ft_substr(*s, quote_res->quote_deb  - *s + 1, quote_res->quote_fin - quote_res->quote_deb - 1);
			gr->b_expanse_allowed = quote_res->b_in_single_quotes == 0;
			(*s) += ft_strlen(gr->val) + 2;
//		}
		free (quote_res);
		return (gr);
=======
			r = ft_substr(*s, p_quotes[0]  - *s + 1, p_quotes[1] - p_quotes[0] - 1);
			(*s) += ft_strlen(r) + 2;
//		}
		free (p_quotes);
		return (r);
>>>>>>> 0638308f0a99953bbfc96934b5138f808ae2ad15
	}
	gr->b_expanse_allowed = quote_res->b_in_single_quotes == 0;
	free (quote_res);
	gr->val = _grab_to_sep(s);

	return (gr);
}
