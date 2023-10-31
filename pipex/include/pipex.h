/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:37:30 by nom               #+#    #+#             */
/*   Updated: 2023/06/07 17:12:55 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>

# define ERRO "Error\ninvalid number of arguments\n"

typedef struct s_data {
	char	*infile;
	char	*outfile;
	char	*cmd;
	char	*cmd2;
	int		infd;
	int		outfd;
	pid_t	child_1;
	pid_t	child_2;
	int		fd[2];
}				t_data;

t_data	initstruct(char **av);
void	find_path(char *cmd);
void	ft_exit_msg(char *msg);
void	ft_free(char **str);
void	close_pipe(t_data *data);
void	close_file(t_data *data);

#endif