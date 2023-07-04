/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:25 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:18:01 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	file_create_only(t_attr *att)
{
	char	**file_name;
	int		i;

	i = 1;
	file_name = ft_split(att->commands_arr[att->i + 1], ' ');
	att->redir_fd = open(file_name[0], O_CREAT, 0664);
	if (file_name[1])
		printf("%s: command not found\n", file_name[i]);
}

void	redir_append2(t_attr *att)
{
	char	*file_name;

	while (!ft_strcmp(att->commands_arr[att->i + 3], ">>")
		|| !ft_strcmp(att->commands_arr[att->i + 3], ">"))
	{
		att->i = att->i + 2;
		create_file(att);
	}
	att->i = att->i + 2;
	file_name = ft_strtrim(att->commands_arr[att->i], " ");
	att->redir_fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0664);
	free(file_name);
	dup2(att->redir_fd, STDOUT_FILENO);
	close(att->redir_fd);
	att->redir = 0;
}

void	redir_append(t_attr *att, int index)
{
	char	*file_name;

	expand_tokens(&att->commands_arr[att->i], att);
	if (ft_strcmp(att->commands_arr[index + 1], ">") == 0)
	{
		while (!ft_strcmp(att->commands_arr[att->i + 3], ">")
			|| !ft_strcmp(att->commands_arr[att->i + 3], ">>"))
		{
			att->i = att->i + 2;
			create_file(att);
		}
		att->i = att->i + 2;
		file_name = ft_strtrim(att->commands_arr[att->i], " ");
		att->redir_fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0664);
		free(file_name);
		dup2(att->redir_fd, STDOUT_FILENO);
		close(att->redir_fd);
		att->redir = 0;
		att->number_of_redir--;
	}
	else if (ft_strcmp(att->commands_arr[index + 1], ">>") == 0)
		redir_append2(att);
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
		free(file_name);
		return (-1);
	}
	free(file_name);
	dup2(filefd, 0);
	close(filefd);
	att->read_from_file = 0;
	return (0);
}

void	create_file(t_attr *att)
{
	char	*file_name;

	file_name = ft_strtrim(att->commands_arr[att->i], " ");
	att->redir_fd = open(file_name, O_CREAT, 0644);
}
