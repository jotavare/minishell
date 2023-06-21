/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/21 17:11:34 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_symbol(char *s)
{
	char	*symbols[] = {">", "<", ">>", "<<", "|" };
	int		i;

	if (s[0] == 0)
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

int	check_next_step(t_attr *att)
{
	att->write_to_pipe = 0;
	att->redir = 0;
	att->read_from_pipe = 0;
	att->read_from_file = 0;
	att->heredoc = 0;
	att->skip = 0;
	att->create_file = 0;
	if (att->commands_arr[att->i] && att->commands_arr[att-> i+ 1])
	{
		if (!ft_strcmp(att->commands_arr[att->i + 1], "|"))
			att->write_to_pipe = 1;
		else if (!ft_strcmp(att->commands_arr[att->i + 1], ">") || !ft_strcmp(att->commands_arr[att->i + 1], ">>"))
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
	if (att->i > 1 )
	{
		if (!ft_strcmp(att->commands_arr[att->i - 1], "|"))
			att->read_from_pipe = 1;
		if (!ft_strcmp(att->commands_arr[att->i - 1], ">>")
			|| !ft_strcmp(att->commands_arr[att->i - 1], ">"))
			att->skip = 1;
		if (!ft_strcmp(att->commands_arr[att->i - 1], "<"))
			att->skip = 1;
	}
	return (0);
}