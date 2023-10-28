/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:52:09 by fbourgue          #+#    #+#             */
/*   Updated: 2023/08/27 23:27:00 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_current_line(char **current_line)
{
	char	*ret;
	char	*p_save_current_line;
	char	*nl_pos;

	if (! *current_line)
		return (NULL);
	nl_pos = ft_strchr(*current_line, '\n');
	if (nl_pos)
	{
		ret = ft_substr(*current_line, 0, nl_pos - *current_line + 1);
		p_save_current_line = *current_line;
		*current_line = ft_strdup(nl_pos + 1);
		return (free(p_save_current_line), ret);
	}
	ret = ft_strdup(*current_line);
	free(current_line);
//	*current_line = NULL;
	if (ret[0] == 0)
		return (free(ret), NULL);
	return (ret);
}

void	grab_from_file2(char **buf_line, char *p_save_buf_line, char *read_buf)
{
	if (buf_line) 
	{
		p_save_buf_line = *buf_line;
		*buf_line = ft_strjoin(p_save_buf_line, read_buf);
	}
	else
		*buf_line = ft_strdup(read_buf);
}

void	grab_from_file(int fd, char *read_buf, char **buf_line)
{
	int		lu;
	char	*p_save_buf_line;

	p_save_buf_line = NULL;
	lu = read(fd, read_buf, BUFFER_SIZE);
	if (lu == -1)
	{
		free(*buf_line);
		*buf_line = NULL;
	}
	while (lu > 0)
	{
		read_buf[lu] = 0;
		if (! *buf_line)
			*buf_line = ft_strdup(read_buf);
		else
		{
			grab_from_file2(buf_line, p_save_buf_line, read_buf);
		}
		if (ft_strchr(read_buf, '\n'))
			break ;
		lu = read(fd, read_buf, BUFFER_SIZE);
	}
	free(read_buf);
}

char	*get_next_line(int fd)
{
	static char	*buf_line;
	char		*read_buf;
	char		*res;

	if (BUFFER_SIZE < 1)
		return (NULL);
	read_buf = malloc(BUFFER_SIZE + 1);
	if (!read_buf)
		return (NULL);
	if (fd < 0)
	{
		if (buf_line)
			free(buf_line);
		buf_line = NULL;
		return (free(read_buf), NULL);
	}
	grab_from_file(fd, read_buf, &buf_line);
	res = get_current_line(&buf_line);
	return (res);
}
