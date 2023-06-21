/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:25 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/21 17:38:03 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	redir_append(t_attr *att, int index)
{
	char	*file_name;
	
	if (strcmp(att->commands_arr[index + 1], ">") == 0)
	{
		while (!strcmp(att->commands_arr[att->i + 3], ">")
			|| !strcmp(att->commands_arr[att->i + 3], ">>"))
		{
			att->i = att->i + 2;
			create_file(att);
		}
		att->i = att->i + 2;
		file_name = ft_strtrim(att->commands_arr[att->i], " ");
		att->redir_fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		free(file_name);
		dup2(att->redir_fd, STDOUT_FILENO);
		close(att->redir_fd);
		att->redir = 0;
		att->number_of_redir--;
	}
	else if (strcmp(att->commands_arr[index + 1], ">>") == 0)
	{
		while (!strcmp(att->commands_arr[att->i + 3], ">>")
			|| !strcmp(att->commands_arr[att->i + 3], ">"))
		{
			att->i = att->i + 2;
			create_file(att);
		}
		att->i = att->i + 2;
		file_name = ft_strtrim(att->commands_arr[att->i], " ");
		att->redir_fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
		dup2(att->redir_fd, STDOUT_FILENO);
		close(att->redir_fd);
		att->redir = 0;
	}
}

int	read_from_file(t_attr *att, int index)
{
	char	*file_name;
	int		filefd;

	file_name = ft_strtrim(att->commands_arr[index + 2], " ");
	filefd = open(file_name, O_RDONLY);
	if ((filefd) < 0)
	{
		perror("Minishell");
		return (-1);
	}
	free(file_name);
	dup2(filefd, 0);
	close(filefd);
	att->read_from_file = 0;
	return (0);
}

void	heredoc(char *delimiter, t_attr *att)
{
	char	*line;
	int		fd;

	fd = open(".heredoc", O_CREAT | O_WRONLY | O_APPEND, 0644);
	while (1)
	{
		write(1, ">", 1);
		line = get_next_line(0, 1);
		write(fd, line, strlen(line));
		if (strncmp(line, delimiter, strlen(delimiter)) == 0)
		{
			free(line);
			break ;
		}
		free(line);
	}
	att->redir_fd = open(".heredoc", O_RDONLY);
	dup2(att->redir_fd, 0);
	exit(0);
}

void	create_file(t_attr *att)
{
	char	*file_name;

	file_name = ft_strtrim(att->commands_arr[att->i], " ");
	att->redir_fd = open(file_name, O_CREAT, 0644);
}
		