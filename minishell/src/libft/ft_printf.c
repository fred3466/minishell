/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:48:33 by fbourgue          #+#    #+#             */
/*   Updated: 2023/04/12 15:49:32 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	format_hexa(int *ret, unsigned int val, const char b_upper)
{
	char	*t;

	t = ft_itoa_base_n(16, val);
	if (t)
	{
		if (b_upper)
			ft_strtoupper(t);
		*ret += ft_putstr_fd(1, t);
		free(t);
	}
}

void	format_pointer(int *ret, long long unsigned int val)
{
	char	*tmp;

	if (! val)
	{
		ft_putstr_fd(1, "(nil)");
		*ret += 5;
		return ;
	}
	tmp = ft_itoau_base_n(16, (unsigned long long) val);
	if (tmp)
	{
		*ret += ft_putstr_fd(1, "0x");
		*ret += ft_putstr_fd(1, tmp);
		free(tmp);
	}
}

int	part_format(char f, va_list vals_list)
{
	int		ret;

	ret = 0;
	if (! f)
		return (0);
	if ('c' == f)
		ret += ft_putchar_fd(1, (va_arg(vals_list, int)));
	else if ('s' == f)
		ret += ft_putstr_fd(1, va_arg(vals_list, char *));
	else if ('d' == f || 'i' == f)
		ret += ft_putnbr_fd(1, (va_arg(vals_list, int)));
	else if ('u' == f)
		ret += ft_putnbru_fd(1, (va_arg(vals_list, unsigned int)));
	else if ('x' == f)
		format_hexa(&ret, va_arg(vals_list, unsigned int), 0);
	else if ('X' == f)
		format_hexa(&ret, va_arg(vals_list, unsigned int), 1);
	else if ('p' == f)
		format_pointer(&ret, va_arg(vals_list, long long unsigned int));
	else if ('%' == f)
		ret += ft_putchar_fd(1, '%');
	return (ret);
}

void	process(const char *fmt, int *ret, va_list	vals_list)
{
	int		sz;
	int		i;

	sz = 0;
	i = 0;
	while (fmt[i])
	{
		if ('%' == fmt[i])
		{
			sz = part_format(fmt[i + 1], vals_list);
			*ret += sz;
			i += 2;
			continue ;
		}
		*ret += ft_putchar_fd(1, fmt[i]);
		i++;
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	vals_list;
	int		ret;

	if (! fmt)
		return (0);
	va_start(vals_list, fmt);
	ret = 0;
	process(fmt, &ret, vals_list);
	va_end(vals_list);
	return (ret);
}
