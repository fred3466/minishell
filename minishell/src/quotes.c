
#include "minishell.h"

char	*_got_q(char **s, char **p_quote_deb, char **p_quote_fin, char q)
{
	*p_quote_deb =ft_strchr(*s, q);
	if (*p_quote_deb == *s)
	{
		*p_quote_fin = ft_strchr(*p_quote_deb + 1, q);
		if (*p_quote_deb && !*p_quote_fin)
			perror("A GERER !!! problème d'apostrophe non fermé.");
	}
	else
		*p_quote_deb = NULL;
	return (*p_quote_deb);
}

int	_check_micmac(char *p_quote_deb, char *p_quote_fin, char *p_dquote_deb, char *p_dquote_fin)
{
	if (p_quote_deb && p_dquote_deb
			&& p_quote_deb < p_dquote_deb
			&& p_quote_fin > p_dquote_fin)
	{
		perror("A GERER !!! micmac dans les apostrophes et guillemets");
		return (0);
	}

	if (p_quote_deb && p_dquote_deb
			&& p_quote_deb > p_dquote_deb
			&& p_quote_fin < p_dquote_fin)
	{
		perror("A GERER !!! micmac dans les apostrophes et guillemets");
		return (0);
	}
	return (1);
}

char	**_q_ou_dq(char **ret, char **p_quote_deb, char **p_quote_fin, char **p_dquote_deb, char **p_dquote_fin)
{
	if (*p_quote_deb)
		{
			ret[0] = *p_quote_deb + 1;
			ret[1] = *p_quote_fin;
		}
		else if (*p_dquote_deb)
		{
			ret[0]= *p_dquote_deb + 1;
			ret[1]= *p_dquote_fin;
		}
	return (ret);
}

char	**	_q_et_dq(char **ret, char *p_quote_deb, char *p_quote_fin, char *p_dquote_deb, char *p_dquote_fin)
{
	if (p_quote_deb < p_dquote_deb)
	{
		ret[0] = p_quote_deb + 1;
		ret[1] = p_quote_fin;
	}
	else if (p_quote_deb > p_dquote_deb)
	{
		ret[0]= p_dquote_deb + 1;
		ret[1]= p_dquote_fin;
	}
	return (ret);
}

char	**quotes(char **s)
{
	char	*p_quote_deb;
	char	*p_quote_fin;
	char	*p_dquote_deb;
	char	*p_dquote_fin;
	char	**ret;

	p_dquote_deb = NULL;
	p_dquote_fin = NULL;
	p_quote_deb = NULL;
	p_quote_fin = NULL;
	ret = malloc(sizeof(char**) * 2);
	ret[0] = NULL;
	ret[1] = NULL;
	_got_q(s, &p_quote_deb, &p_quote_fin, '\'');
	_got_q(s, &p_dquote_deb, &p_dquote_fin, '\"');
	if (! _check_micmac(p_quote_deb, p_quote_fin, p_dquote_deb, p_dquote_fin))
		return NULL;
	if (p_quote_deb && p_dquote_deb)
		_q_et_dq(ret, p_quote_deb, p_quote_fin, p_dquote_deb, p_dquote_fin);
	else
		_q_ou_dq(ret,&p_quote_deb, &p_quote_fin, &p_dquote_deb, &p_dquote_fin);
	return (ret);
}
