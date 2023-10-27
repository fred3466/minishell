/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:33:12 by slecoq            #+#    #+#             */
/*   Updated: 2023/06/06 14:32:10 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_lengnl(char *rstr)
{
	int	i;

	if (!rstr)
		return (0);
	i = 0;
	while (rstr[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *rstr, int c)
{
	if (!rstr)
		return (0);
	while (*rstr != '\0')
	{
		if (*rstr == (char)c)
			return (rstr);
		rstr++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *rstr, char *buff)
{
	char	*dest;
	int		i;
	int		j;

	if (!rstr)
	{
		rstr = (char *)malloc(sizeof(char) * 1);
		rstr[0] = '\0';
	}
	if (!rstr)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_lengnl(rstr) + ft_lengnl(buff) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (rstr[i])
		dest[j++] = rstr[i++];
	i = 0;
	while (buff[i])
		dest[j++] = buff[i++];
	dest[j] = '\0';
	free(rstr);
	return (dest);
}

char	*ft_get_line(char *rstr)
{
	int		i;
	char	*dest;

	i = 0;
	if (!rstr[i])
		return (NULL);
	while (rstr[i] != '\n' && rstr[i])
		i++;
	dest = (char *)malloc(sizeof(char) * i + 2);
	if (!dest)
		return (NULL);
	i = 0;
	while (rstr[i] != '\n' && rstr[i])
	{
		dest[i] = rstr[i];
		i++;
	}
	if (rstr[i] == '\n')
	{
		dest[i] = rstr[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_new_rstr(char	*rstr)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (rstr[i] && rstr[i] != '\n')
		i++;
	if (rstr[i] == '\0')
	{
		free(rstr);
		return (NULL);
	}
	dest = (char *)malloc(sizeof(char) * (ft_lengnl(rstr) - i + 1));
	if (!dest)
		return (NULL);
	i++;
	j = 0;
	while (rstr[i])
		dest[j++] = rstr[i++];
	dest[j] = '\0';
	free(rstr);
	return (dest);
}
