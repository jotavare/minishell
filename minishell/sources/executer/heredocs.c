/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:25 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:50:58 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_array(t_attr att, int i)
{
	int	count;

	count = 0;
	while (!ft_strcmp(att.commands_arr[i], "<<"))
	{
		count++;
		i = i + 2;
	}
	return (count);
}

char	**create_delims(t_attr att, int i, int count)
{
	char	**delims;
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
	return (delims);
}

void	init_h_doc(t_attr att, t_hdoc *hdoc)
{
	hdoc->i = att.i + 1;
	hdoc->count = count_array(att, hdoc->i);
	hdoc->delims = create_delims(att, hdoc->i, hdoc->count);
	hdoc->temp = hdoc->delims;
	hdoc->line = NULL;
	hdoc->fd = 0;
	hdoc->line2 = NULL;
}

void	heredoc2(t_attr *att, t_hdoc *hdoc)
{
	free_arr(hdoc->temp);
	close(hdoc->fd);
	att->redir_fd = open(".heredoc", O_RDONLY);
	dup2(att->redir_fd, 0);
	close(att->redir_fd);
	unlink(".heredoc");
}

void	heredoc(t_attr *att)
{
	t_hdoc	h_doc;

	init_h_doc(*att, &h_doc);
	set_signals2();
	signal(SIGINT, &heredoc_handler);
	signal(SIGQUIT, &heredoc_handler);
	h_doc.fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{
		write(1, ">", 1);
		h_doc.line = get_next_line(0, 1);
		h_doc.line2 = ft_strtrim(h_doc.line, "\n");
		if (ft_strcmp(h_doc.delims[0], h_doc.line2) == 0)
		{
			h_doc.delims++;
			h_doc.count--;
		}
		else
			write(h_doc.fd, h_doc.line, ft_strlen(h_doc.line));
		if (h_doc.count == 0)
			break ;
		free(h_doc.line);
	}
	heredoc2(att, &h_doc);
}
