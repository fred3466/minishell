/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:33:10 by slecoq            #+#    #+#             */
/*   Updated: 2023/06/06 14:32:10 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_rd_to_new_line(char *rstr, int fd)
{
	int		index_fd;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	index_fd = 1;
	while (!ft_strchr_gnl(rstr, '\n') && index_fd != 0)
	{
		index_fd = read(fd, buff, BUFFER_SIZE);
		if (index_fd == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[index_fd] = '\0';
		rstr = ft_strjoin_gnl(rstr, buff);
	}
	free(buff);
	return (rstr);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*rstr[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	rstr[fd] = ft_rd_to_new_line(rstr[fd], fd);
	if (!rstr[fd])
		return (NULL);
	str = ft_get_line(rstr[fd]);
	rstr[fd] = ft_new_rstr(rstr[fd]);
	return (str);
}
