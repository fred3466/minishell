/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:09:32 by slecoq            #+#    #+#             */
/*   Updated: 2023/06/07 17:32:22 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	close_pipe(t_data *data)
{
	close(data->fd[0]);
	close(data->fd[1]);
}

void	close_file(t_data *data)
{
	close(data->infd);
	close(data->outfd);
}
