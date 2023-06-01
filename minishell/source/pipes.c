/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:38:30 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/31 20:49:33 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* 	A IDEIA
	- pegar no que nos chega como string
		- iterar a string a procura de '|'s - ✅
			- atribuir a uma variavel o numero de '|'s existentes ✅
	- verificar o resto dos tokens com o lexer ❓
		- criar pids e forks com o numero de '|'s ✅
		- verificar se sao comandos validos ✅
			- verificar se os '|'s e os comandos validos estao em numero correcto ❌
	- atribuir cada token ao respectivo fork / child process ❌
	- executar os tokens/comandos
	- fechar os fd[] ❓
 */
int	pipework(t_attr *att)
{
	int	pid1; // create pid1
	int	pid2; // create pid2
	int	fd[2]; // create file descriptors main pipe
	int	nb;
	int	n;
	
	if (att->nb_pipes < 1)
		return (1);
	nb = 0;
	n = 0;
	while (nb < att->nb_pipes)
	{
		if (pipe(fd) < 0) //verify the state of fd and nextfd
			return (1);
		if (ft_strcmp(att->tok_arr[n], "|") != 0)
		{
			pid1 = fork(); //open a fork to the pid[nb]
			if (pid1 == -1)
				return (1); //verify if it has not given an error
			if (pid1 == 0)
			{
				close(1);
				dup2(fd[1], STDOUT_FILENO); //dups the WRITE end to the to the next pipe READ end
				close(fd[0]);
				write()
				n++;
			}
			pid2 = fork(); //open a fork to the pid[nb]
			if (pid2 < 0)
				return (1); //verify if it has not given an error
			if (pid2 == 0)
			{
				if (ft_strcmp(att->tok_arr[n], "|") == 0)
					n++;
				close(0);
				dup2(fd[0], STDIN_FILENO); //dups the WRITE end to the to the next pipe READ end
				close(fd[1]);
				read
			}
			else
			{
				close(fd[1]); //close WRITE end of pipe
				close(fd[0]); //close READ end of pipe
				waitpid(pid1, NULL, 0);
				waitpid(pid2, NULL, 0);
			}
			n++;
		}
		else
			n++;
		nb++;
	}
	return (0);
}