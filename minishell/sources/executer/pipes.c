/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:25 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:18:13 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	write_to_pipe(t_attr *att)
{
	if (att->pipeindex >= att->number_of_pipes)
		return ;
	close(att->pipesfd[att->pipeindex][0]);
	if (dup2(att->pipesfd[att->pipeindex][WRITE_END], STDOUT_FILENO) < 0)
		close(att->pipesfd[att->pipeindex][1]);
}

void	read_from_pipe(t_attr *att)
{
	close(att->pipesfd[att->pipeindex][1]);
	if (dup2(att->pipesfd[att->pipeindex][READ_END], STDIN_FILENO) < 0)
		close(att->pipesfd[att->pipeindex][0]);
}

void	close_pipeline(t_attr *att)
{
	if (att->pipeindex > 0)
		close(att->pipesfd[att->pipeindex - 1][READ_END]);
	if (att->pipeindex < att->number_of_pipes)
		close(att->pipesfd[att->pipeindex][WRITE_END]);
}

void	init_pipes(t_attr *att)
{
	int	i;

	att->pipesfd = ft_calloc(att->number_of_pipes + 1, sizeof(int *));
	if (!att->pipesfd)
		return ;
	i = -1;
	while (++i < att->number_of_pipes)
	{
		att->pipesfd[i] = malloc(2 * sizeof(int));
		pipe(att->pipesfd[i]);
	}
}
