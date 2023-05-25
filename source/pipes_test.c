/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:38:30 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/25 16:27:17 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int	piprectise(int ac, char **av)
{
	int	fd[2]; //create file descriptors variables
	int	pid1;  //create first pid to child1
	int	pid2;  //create second pid to child2
	
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
}