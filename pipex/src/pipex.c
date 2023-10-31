/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slecoq <slecoq@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:42:00 by slecoq            #+#    #+#             */
/*   Updated: 2023/10/31 14:51:37 by slecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	execute(char *cmd)
{
	char	**cmd_split;
	char	*path;

	cmd_split = ft_split(cmd, ' ');
	path = ft_strjoin("/usr/bin/", cmd_split[0]);
	execve(path, cmd_split, NULL);
}

void	child_2(t_data *data) // le second processus va recuperer les information qui on circuler dans le pipe pour y executer la seconde commande et envoyer le resultat dans un fichier texte
{
	close(data->fd[1]);
	dup2(data->outfd, 1); // cette fonction dit "le fichier outfd devient la sortie standar" (cmd > file2)
	dup2(data->fd[0], 0); // cette fonction dit "la sortie du pipe devient l'entrer standar"
	execute(data->cmd2); // une fois que c'est fait execute la commande
}

void	child_1(t_data *data) // le premier processus va recuperer ce qu'il y ecrit dans le fichier et executer la commande dessus avant d'envoyer le resultat dans le pipe
{
	close(data->fd[0]);
	dup2(data->infd, 0); // cette fonction dit "le fichier appeller infd devient l'entrer standar" (< file1)
	dup2(data->fd[1], 1);// cette fonction dit "l'entrer du pipe (fd[1]) devient la sortie standar du processus"
	execute(data->cmd); // une fois que c'est fait execute la commande
}

void	pipex(t_data *data)
{
	if (pipe(data->fd) == -1)	// Creation du pipe avec en paramettre un int *fd[2] si il est egale a -1 il n'a pas ete creer correctement
		ft_exit_msg("Pipe ");	// fd[1] est l'entrer du pipe et fd[0] est la sortie du pipe 
	data->child_1 = fork();
	if (data->child_1 < 0)
		ft_exit_msg("Fork child 1 ");
	else if (data->child_1 == 0)
		child_1(data);			// Le premier processus enfants execute la premiere commande et envois le resultat dans l'entrer du pipe
	data->child_2 = fork();
	if (data->child_2 < 0)
		ft_exit_msg("Fork child 2 ");
	else if (data->child_2 == 0)
		child_2(data);			// Le second processus enfant recupere les informations qui ont ete envoyer dans le pipe pour y executer la deuxieme commande
}

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac != 5)
		return (write(2, ERRO, ft_strlen(ERRO)));
	else
	{
		data = initstruct(av);
		find_path(data.cmd);		// je regarde en amont si les commande passer en paramettre existe ou non
		find_path(data.cmd2);
		data.infd = open(data.infile, O_RDONLY); // le premier fichier est ouvert en lecture seul, car se qui est ecrit dedant est rediriger plus tard sur l'entrer standar
		if (data.infd < 0)
			ft_exit_msg("Open infile ");
		data.outfd = open(data.outfile, O_WRONLY | O_TRUNC | O_CREAT, 0777); // le deuxieme fichier qui vq recevoir le resultat dans des deux commande est ouvert en ecriture seul (O_WRONLY), si quelque chose est ecrite dedant se sera ecraser (O_TRUNC), et si il n'existe pas il sera creer (O_CREAT), avec les droit 0777 (le zero signifi qu'il va creer le fichier avec ces droit et les conserver d'un lancemant de programme a un autre)
		if (data.outfd < 0)
			ft_exit_msg("Open outfile ");
		pipex(&data); // lancement de la fonction qui va creer le pipe, les redirection et les lancement des processus
	}
	close_pipe(&data); // une fois que les deux precessus enfant sont lancer, le pere arrive ici pour fermer ces entrer et sortie du pipe (chaque processus possede ces propre entrer et sortie)
	waitpid(data.child_1, NULL, 0); // le pere attend que ces deux enfants termine leur processus
	waitpid(data.child_2, NULL, 0);
	close_file(&data);
	return (0);
}
