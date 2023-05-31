/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubu <lubu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:38:30 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/27 10:39:36 by lubu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* 	A IDEIA
	- pegar no que nos chega como string
		- iterar a string a procura de '|'s
			- atribuir a uma variavel o numero de '|'s existentes
	- verificar o resto dos tokens com o lexer
		- criar pids e forks com o numero de '|'s
		- verificar se sao comandos validos
			- verificar se os '|'s e os comandos validos estao em numero correcto
	- atribuir cada token ao respectivo fork / child process
	- executar os tokens/comandos
	- fechar os fd[]
 */
/*int	count_pipes(char *s, t_attr *att) //experimental work
{
	int	len;

	len = ft_strlen(s) - 1;
	while (len >= 0)
	{
		if (s[len] != '|')
		{
			att->nb_pipes++;
			while (len > 0 && s[len] != '|')
				len--;
		}
		if (s[len] == '|')
			len--;
		if (len == 0)
			break;
	}
	return (att->nb_pipes);
	if (!s)
		return (0);
	else
		att->nb_pipes++;
	while (s[att->p_i++] && (att->p_i < len))
	{
		if (s[att->p_i] == '|')
			att->nb_pipes++;
	}
	return (1);
}

int	pipework(t_attr *att)
{
	int	i;
	int	dyn_pid;
//	int	fd[2]; //create file descriptors variables
//	int	pid1;  //create first pid to child1
//	int	pid2;  //create second pid to child2
	
	if (!att->tok_arr[1])
		return ;
	if (count_pipes(str, att))
	
	tok = att->tok_arr;
	if (pipe(fd) == -1) //verify the state of fd
		return (1);
	pid1 = fork(); //open a fork to the first pid
	if (pid1 < 0)
		return (2); //verify if it has not given an error
	if (pid1 == 0) //insert what you want to run  on child1 here
	{
		dup2(fd[1], STDOUT_FILENO); //dups a fd that points to the same pipe
		close(fd[0]);
		close(fd[1]);
		//insert LEXER_FUNCTION? here
	}
	pid2 = fork();
	if (pid2 < 0)
		return (3);
	if (pid2 == 0) //insert what you want to run  on child2 here
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		//insert LEXER_FUNCTION? here
	}
	close(fd[0]); //close write end of pipe
	close(fd[1]); //close write end of pipe
	waitpid(pid1, NULL, 0); // wait for child1 to finish
	waitpid(pid2, NULL, 0); // wait for child2 to finish
	return (0);
}*/