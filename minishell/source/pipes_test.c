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
	int	dyn_pid; // create dynamic PID
	int	fd[2]; // create file descriptors main pipe
	int	nextfd[2]; // create file descriptors pipe[i]
	int	i;
	int	n;
	
	i = 1;
	n = 0;
	dyn_pid = 0;
	while (i <= att->nb_pipes)
	{
		if (att->nb_pipes < 1)
			return (1);
		if (pipe(fd) == -1 && pipe(nextfd) == -1) //verify the state of fd and nextfd
			return (1);
		if (ft_strcmp(att->tok_arr[n], "|") != 0)
		{
			dyn_pid = fork(); //open a fork to the first pid
			if (dyn_pid < 0)
				return (1); //verify if it has not given an error
			if (dyn_pid == 0)
			{
				dup2(fd[1], nextfd[0]); //dups the write end to the to the next pipe read
				command(att);
				close(fd[1]);
				close(fd[0]);
			}
			close(fd[0]); //close READ end of pipe
			close(fd[1]); //close WRITE end of pipe
			waitpid(dyn_pid, NULL, 0); // wait for child1 to finish
		}
		i++;
		n++;
	}
	return (0);
}