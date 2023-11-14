/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbourgue <fbourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:52:09 by fbourgue          #+#    #+#             */
/*   Updated: 2023/04/28 14:08:07 by fbourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_current_line(char **current_line)
{
	char	*ret;
	char	*p_save_current_line;
	char	*nl_pos;

	if (! *current_line)
		return (NULL);
	nl_pos = ft_strchr_gnl(*current_line, '\n');
	if (nl_pos)
	{
		ret = ft_substr_gnl(*current_line, 0, nl_pos - *current_line + 1);
		p_save_current_line = *current_line;
		*current_line = ft_strdup_gnl(nl_pos + 1);
		return (free(p_save_current_line), ret);
	}
	ret = ft_strdup_gnl(*current_line);
	free(*current_line);
	*current_line = NULL;
	if (ret[0] == 0)
		return (free(ret), NULL);
	return (ret);
}

void	grab_from_file(int fd, char *read_buf, char **buf_line)
{
	int		lu;
	char	*p_save_buf_line;

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
			*buf_line = ft_strdup_gnl(read_buf);
		else
		{
			p_save_buf_line = *buf_line;
			*buf_line = ft_strjoin_gnl(p_save_buf_line, read_buf);
			free(p_save_buf_line);
		}
		if (ft_strchr_gnl(read_buf, '\n'))
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
		return (free(read_buf), NULL);
	grab_from_file(fd, read_buf, &buf_line);
	res = get_current_line(&buf_line);
	return (res);
}

//int main(int argc, char const *argv[])
//{
//	int fd;
//	fd=open("get_next_line.h", O_RDONLY);
//	printf("%s", get_next_line(fd));
//}
