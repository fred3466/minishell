
#include "minishell.h"

int	escape(char	*s, char	*c)
{
	int	ret;

	ret = (c && s) && (c != s && (*(c - 1)  == '\\'));
	return  (ret);
}


char	*_got_q(char **s, char **p_quote_deb, char **p_quote_fin, char q)
{
	char	*save;

	*p_quote_deb =ft_strchr(*s, q);
	if (*p_quote_deb)
	{
		if (escape(*s, *p_quote_deb))
		{
			save =(*p_quote_deb)+1;
			return (_got_q(&save , p_quote_deb, p_quote_fin, q));
		}
		*p_quote_fin = ft_strchr(*p_quote_deb + 1, q);
		if (*p_quote_deb && !*p_quote_fin)
			perror("A GERER !!! problème d'apostrophe non fermé.");
	}
	else
		*p_quote_deb = NULL;
	return (*p_quote_deb);
}

int	_check_mismatch(char **s, char c)
{
	int	nb;
	char	*deb;

	nb = 0;
	deb = *s;
	deb = ft_strchr(deb, c);
	while (deb)
	{
		if (!escape(*s, deb))
			nb++;
		deb = ft_strchr(deb+1, c);
	}
	if (nb == 0)
		return (1);
	return (nb % 2 == 0);
}

int	_check_micmac(t_quotes_res *qr)
{
	if (qr->p_quote_deb && qr->p_dquote_deb
			&& qr->p_quote_deb < qr->p_dquote_deb
			&& qr->p_quote_fin > qr->p_dquote_fin)
	{
		perror("A GERER !!! micmac dans les apostrophes et guillemets");
		return (0);
	}

	if (qr->p_quote_deb && qr->p_dquote_deb
			&& qr->p_quote_deb > qr->p_dquote_deb
			&& qr->p_quote_fin < qr->p_dquote_fin)
	{
		perror("A GERER !!! micmac dans les apostrophes et guillemets");
		return (0);
	}
	return (1);
}

char	**_q_ou_dq(char **ret, t_quotes_res *qr)
{
	if (qr->p_quote_deb)
		{
			ret[0] = qr->p_quote_deb;
			ret[1] = qr->p_quote_fin;
		}
		else if (qr->p_dquote_deb)
		{
			ret[0]= qr->p_dquote_deb;
			ret[1]= qr->p_dquote_fin;
		}
	return (ret);
}

char	**	_q_et_dq(char **ret, t_quotes_res *qr)
{
	if (qr->p_quote_deb < qr->p_dquote_deb)
	{
		ret[0] = qr->p_quote_deb + 1;
		ret[1] = qr->p_quote_fin;
	}
	else if (qr->p_quote_deb > qr->p_dquote_deb)
	{
		ret[0]= qr->p_dquote_deb + 1;
		ret[1]= qr->p_dquote_fin;
	}
	return (ret);
}

char	**quotes(char **s)
{
	t_quotes_res *qr;
	char	**ret;

	qr = quote_res_create();
	ret = malloc(sizeof(char**) * 2);
	ret[0] = NULL;
	ret[1] = NULL;
	_got_q(s, &qr->p_quote_deb, &qr->p_quote_fin, '\'');
	_got_q(s, &qr->p_dquote_deb, &qr->p_dquote_fin, '\"');
	if (! _check_micmac(qr))
		return NULL;
	if ( ! _check_mismatch(s, '\''))
	{
		perror("Micmac avec les apostrophes.\n");
		return NULL;
	}
	if ( ! _check_mismatch(s, '\"'))
	{
			perror("Micmac avec les guillemets.\n");
			return NULL;
	}
	if (qr->p_quote_deb && qr->p_dquote_deb)
		_q_et_dq(ret, qr);
	else
		_q_ou_dq(ret,qr);
	free (qr);
	return (ret);
}
