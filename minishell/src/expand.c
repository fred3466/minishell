/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:19:12 by fbourgue          #+#    #+#             */
/*   Updated: 2023/11/20 18:20:38 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_caract_autorises(char c, int b_first)
{
	int	ret;

	ret = 0;
	if (b_first)
	{
		ret = ft_isalpha(c);
		if (c == '?')
				ret = -1;
	}
	else
	{
		ret = ft_isalnum(c) || c ==  '_';
	}
	return (ret);
}

void	_capture(t_parse_res *pr, char *s_start_with_$)
{
	char	*sep;
	char	*sep_end;
	char	*var_name;
	char	*p_s_start_with_$;

	p_s_start_with_$ = s_start_with_$;
	while( ++s_start_with_$)
	{
		if (! is_caract_autorises(*s_start_with_$, p_s_start_with_$ == s_start_with_$))
		{
				sep = s_start_with_$;
				break ;
		}
	}
	s_start_with_$ = p_s_start_with_$;
	var_name = ft_substr((s_start_with_$), 0, sep- s_start_with_$);
	pr ->s_captured = var_name;
	pr->fin_pre = s_start_with_$;
	pr->deb_post = sep;
//	pr->post = sep;
}
void	_capture(t_parse_res *pr, char *s_start_with_$)
{
	char	*sep;
	char	*sep_end;
	char	*var_name;
	char	*p_s_start_with_$;
	int	res_is_caract_autorises;

	p_s_start_with_$ = s_start_with_$;
	while( ++s_start_with_$)
	{
		res_is_caract_autorises = is_caract_autorises(*s_start_with_$, (p_s_start_with_$ + 1) == s_start_with_$);
		if (! res_is_caract_autorises || (res_is_caract_autorises == -1))
		{
			if (res_is_caract_autorises == -1)
				sep = ++s_start_with_$;
			else
				sep = s_start_with_$;

			break ;
		}
	}
	s_start_with_$ = p_s_start_with_$;
	var_name = ft_substr((s_start_with_$), 0, sep- s_start_with_$);
	pr ->s_captured = var_name;
	pr->fin_pre = s_start_with_$;
	pr->deb_post = sep;
//	pr->post = sep;
}

t_parse_res	*_get_next_var(char *s)
{
	t_parse_res *pr;
	char	*save_s;

	save_s = s;
	pr =parse_res_create();
	while (s && *s)
	{
		if (s && *s == '$')
		{
			_capture(pr, s);
			break ;
		}
		(s)++;
	}
	if (! pr->s_captured)
		pr->s_pre = ft_strdup(save_s);
	else
		pr->s_pre = ft_substr(save_s, 0, pr->fin_pre - save_s);
//	s = *save;
	return (pr);
}

char	*ft_strjoin_remove_escape_in_s2(char const *s1, char const *s2)
{
	char	*r;
	char	*save;
	r = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (! r)
		return (NULL);
	save = r;
	while (s1 && *s1)
		*r++ = *s1++;

	while (s2 && *s2)
	{
		if ((*s2 == '\\') && (*(s2+1)) && (*(s2+1) == '\"'))
			(*r++ = '"') && (s2 += 2);
		else if((*s2 == '\\') && (*(s2+1)) && (*(s2+1) == '\''))
			(*r++ = '\'') && (s2 += 2);
		else
			*r++ = *s2++;
	}
	*r++ = 0;
	return (save);
}

void	concat(char **s1, char *s2)
{
	char	*save;
//	char	*save2;

	if (s2)
	{
		save = *s1;
//		save2 = s2;
		if (DEBUG_EXP)
			dprintf(2, "[%s][%s]\n", *s1, s2);
		*s1 = ft_strjoin_remove_escape_in_s2(*s1, s2);
		free (save);
//		free (save2);
	}
}

char	*_parse(char **s, t_env *env_lst)
{
	t_parse_res	*pr;
	char	*new;
	char	*save_s;
	int	sz;

	if (DEBUG_EXP)
		dprintf(2, "----------\nparse [%s]\n",*s);
	save_s = *s;
	new = ft_strdup("");
	while(s && *s && **s)
	{
		pr = _get_next_var(*s);
		if (pr->s_captured)
		{
			pr->s_rempl = get_var_env(env_lst, (pr->s_captured) + 1);
			if (DEBUG_EXP)
			{
				dprintf(2, "\trempl.\t[%s] <= [%s]\n", pr->s_captured,pr->s_rempl);
				dprintf(2, "\tstatic\t [%s]\n", pr->s_pre);
			}
		}
		concat(&new, pr->s_pre);
		concat(&new, pr->s_rempl);
		concat(&new, pr->deb_post);
		sz = ft_strlen(pr->s_pre) + ft_strlen(pr->s_captured)+ ft_strlen(pr->deb_post);
		*s += sz;
	}
	free (pr->s_captured);
	free (pr->s_pre);
//	free (pr->s_rempl);
	free (pr);
	*s = save_s;
	return (new);
}
char	*_parse(char **s, t_env *env_lst, int last_exec_status)
{
	t_parse_res	*pr;
	char	*new;
	char	*save_s;
	int	sz;

	if (DEBUG_EXP)
		dprintf(2, "----------\nparse [%s]\n",*s);
	save_s = *s;
	new = ft_strdup("");
	while(s && *s && **s)
	{
		pr = _get_next_var(*s);
		if (pr->s_captured)
		{
			if (ft_strncmp(pr->s_captured, "$?", 2) == 0)
				pr->s_rempl = ft_itoa(last_exec_status);
			else
				pr->s_rempl = get_var_env(env_lst, (pr->s_captured) + 1);
			if (DEBUG_EXP)
			{
				dprintf(2, "\trempl.\t[%s] <= [%s]\n", pr->s_captured,pr->s_rempl);
				dprintf(2, "\tstatic\t [%s]\n", pr->s_pre);
			}
		}
		concat(&new, pr->s_pre);
		concat(&new, pr->s_rempl);
		concat(&new, pr->deb_post);
		sz = ft_strlen(pr->s_pre) + ft_strlen(pr->s_captured)+ ft_strlen(pr->deb_post);
		*s += sz;
	}
	free (pr->s_captured);
	free (pr->s_pre);
//	free (pr->s_rempl);
	free (pr);
	*s = save_s;
	return (new);
}

void	expand(t_noeud *n, t_env *env_lst, int last_exec_status)
{
	char	*save;
	t_arg	*arg;
	t_arg	**arg_save;
	char	*copy;

//	copy = (n->str_valeur);
	if (n->b_expanse_allowed)
	{
		save = _parse(&n->str_valeur, env_lst, last_exec_status);
		free (n->str_valeur);
		n->str_valeur = save;
	}
//	free (copy);
	arg_save = n->args;
	while (n && arg_save && *arg_save && (*arg_save)->b_expanse_allowed)
	{
		arg = *arg_save;
		save = _parse(&arg->val, env_lst);
		(*arg_save)->val = save;
		(arg_save)++;
	}
//	n->args = arg_save;
}
