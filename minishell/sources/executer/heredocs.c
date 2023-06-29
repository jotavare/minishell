/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:25 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/28 15:23:28 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	heredoc(char *delimiter, t_attr *att)
{
	char	*line;
	int		fd;

	set_signals2();
	signal(SIGINT, &heredoc_handler);
	signal(SIGQUIT, &heredoc_handler);
	fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{
		write(1, ">", 1);
		line = get_next_line(0, 1);
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		free(line);
	}
	close(fd);
	att->redir_fd = open(".heredoc", O_RDONLY);
	dup2(att->redir_fd, 0);
	close(att->redir_fd);
	unlink(".heredoc");
}

void	handle_heredoc(t_attr *att)
{
	int		i;
	char	**d;

	i = 1;
	d = ft_split(att->commands_arr[att->i + 2], ' ');
	if (d[1] != NULL)
	{
		while (d[i])
		{
			printf("%s: %s: No such file or directory\n",
				att->commands_arr[att->i], d[i]);
			i++;
		}
	}
	heredoc(d[0], att);
	free_arr(d);
}
