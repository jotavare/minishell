/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:25 by jotavare          #+#    #+#             */
/*   Updated: 2023/06/30 06:13:12 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		count_array(t_attr att, int i)
{
	int	count;

	count = 0;
	while (!ft_strcmp(att.commands_arr[i], "<<"))
	{
		count++;
		i = i + 2;
	}
	return(count);
}

char	**create_delims(t_attr att, int i, int count)
{
	char **delims;
	char	*temp;
	int		j;


	j = 0;
	delims = malloc(sizeof(char *) * (count + 1));
	delims[count] = NULL;
	while (j < count)
	{
		temp = ft_strtrim(att.commands_arr[i + 1], " ");
		delims[j] = ft_strdup(temp);
		j++;
		i = i + 2;
		free(temp);
	}
	return(delims);
}

char **del_first(char **arr, int *count)
{
	char **delims;
	int		i;

	i = 0;
	delims = malloc(sizeof(char *) * (*count));
	delims[*count] = NULL;
	if (*count > 0)
	{
		while(i < *count)
		{
			if (*count > 1)
			{
				delims[i] = ft_strdup(arr[i + 1]);
				free(arr[i + 1]);
				*count = *count - 1;
			}
			else 
			{
				free(arr[0]);
				delims[i] = NULL;
				*count = *count - 1;
			}
			i++;
		}
	}
	return(delims);
}

void	heredoc(t_attr *att)
{
	char	*line;
	int		fd;
	char	**delims;
	int		i = att->i + 1;
	int		count;
	char	*line2;

	count = count_array(*att, i);
	delims = create_delims(*att, i, count);
	set_signals2();
	signal(SIGINT, &heredoc_handler);
	signal(SIGQUIT, &heredoc_handler);
	fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{
		printf("%d\n", count);
		write(1, ">", 1);
		line = get_next_line(0, 1);
		line2 = ft_strtrim(line, "\n");
		if (ft_strcmp(delims[0], line2) == 0)
			delims = del_first(delims, &count);
		if (count == 0)
			break;
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
	heredoc(att);
	free_arr(d);
}
