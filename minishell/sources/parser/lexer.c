/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/19 14:04:14 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
    The command function handles basic command recognition
    and execution based on the input string, providing
    feedback or return values accordingly.
*/

void	redir_append(t_attr *att, int index)
{
	char	*file_name;
	
	file_name = ft_strtrim(att->commands_arr[index + 2], " ");	

	if (strcmp(att->commands_arr[index + 1], ">") == 0)
	{
		att->redir_fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		free(file_name);
		dup2(att->redir_fd, STDOUT_FILENO);
		close(att->redir_fd);
		att->redir = 0;
		att->number_of_redir--;

	}
	else if (strcmp(att->commands_arr[index + 1], ">>") == 0)
	{
		att->redir_fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
		dup2(att->redir_fd, STDOUT_FILENO);
		close(att->redir_fd);
		att->redir = 0;
	}
}

void	read_from_file(t_attr *att, int index)
{
        char	*file_name;
		int		filefd;

		file_name = ft_strtrim(att->commands_arr[index + 2], " ");
		if ((filefd = open(file_name, O_RDONLY)) < 0)
			perror("Minishell");
		free(file_name);
        dup2(filefd, 0);
		close(filefd);
		att->read_from_file = 0;
}

void	command(t_attr *att, int index)
{
	
	if (!att->tok_arr[0])
		return ;
	else if (ft_strcmp(att->tok_arr[0], "cd") == 0)
		cd(att);
	else if (ft_strcmp(att->tok_arr[0], "unset") == 0)
		unset(att);
	else if ((ft_strcmp(att->tok_arr[0], "exit") == 0)
			|| (ft_strcmp(att->tok_arr[0], "\"exit\"") == 0))
		return (ft_exit(att));
	else if (ft_strcmp(att->tok_arr[0], "export") == 0 && att->tok_arr[1])
		export(att);
	else
		execute(att, index);
}
