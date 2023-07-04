/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:15:57 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_symbol(char *s)
{
	char	*symbols[5];
	int		i;

	symbols[0] = ">";
	symbols[1] = "<";
	symbols[2] = ">>";
	symbols[3] = "<<";
	symbols[4] = "|";
	if (s[0] == '\0')
	{
		return (0);
	}
	i = 0;
	while (i < 5)
	{
		if (!ft_strcmp(s, symbols[i]))
			return (1);
		i++;
	}
	return (0);
}

void	reset_flags(t_attr *att)
{
	att->write_to_pipe = 0;
	att->redir = 0;
	att->read_from_pipe = 0;
	att->read_from_file = 0;
	att->heredoc = 0;
	att->skip = 0;
	att->create_file = 0;
	att->only_create = 0;
}

void	next_step_sub2(t_attr *att)
{
	if (!ft_strcmp(att->commands_arr[att->i - 1], "|"))
		att->read_from_pipe = 1;
	if (!ft_strcmp(att->commands_arr[att->i - 1], ">>")
		|| !ft_strcmp(att->commands_arr[att->i - 1], ">"))
		att->skip = 1;
	if (!ft_strcmp(att->commands_arr[att->i - 1], "<"))
		att->skip = 1;
	if (!ft_strcmp(att->commands_arr[att->i - 1], "<<"))
		att->skip = 1;
}

void	next_step_sub(t_attr *att)
{
	if (!ft_strcmp(att->commands_arr[att->i + 1], "|"))
		att->write_to_pipe = 1;
	else if (!ft_strcmp(att->commands_arr[att->i + 1], ">")
		|| !ft_strcmp(att->commands_arr[att->i + 1], ">>"))
		att->redir = 1;
	else if (!ft_strcmp(att->commands_arr[att->i + 1], "<"))
	{
		att->read_from_file = 1;
		if (!ft_strcmp(att->commands_arr[att->i + 3], "|"))
			att->write_to_pipe = 1;
	}
	else if (!ft_strcmp(att->commands_arr[att->i + 1], "<<"))
		att->heredoc = 1;
}

int	check_next_step(t_attr *att)
{
	reset_flags(att);
	if (!ft_strcmp(att->commands_arr[0], ">")
		|| !ft_strcmp(att->commands_arr[0], ">>"))
	{
		att->only_create = 1;
		att->skip = 1;
	}
	else if (att->commands_arr[att->i] && att->commands_arr[att->i + 1])
		next_step_sub(att);
	if (att->i > 1)
		next_step_sub2(att);
	return (0);
}
