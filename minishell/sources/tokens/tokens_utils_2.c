/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:52:47 by joaoalme          #+#    #+#             */
/*   Updated: 2023/06/28 17:18:18 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_if_pipe(char **token, int j, char *s)
{
	if (s[j] == '|' && s[j + 1] != '|')
	{
		*token = malloc(sizeof(char) * 2);
		(*token)[0] = s[j];
		(*token)[1] = 0;
		return (1);
	}
	else if (s[j] == '|' && s[j + 1] == '|')
	{
		*token = malloc(sizeof(char) * 3);
		(*token)[0] = s[j];
		(*token)[1] = s[j + 1];
		(*token)[2] = 0;
		return (1);
	}
	return (0);
}

int	check_if_redir(char **token, int j, char *s)
{
	if (s[j] == '>' && s[j + 1] != '>')
	{
		*token = malloc(sizeof(char) * 2);
		(*token)[0] = s[j];
		(*token)[1] = 0;
		return (1);
	}
	else if (s[j] == '>' && s[j + 1] == '>')
	{
		*token = malloc(sizeof(char) * 3);
		(*token)[0] = s[j];
		(*token)[1] = s[j + 1];
		(*token)[2] = 0;
		return (1);
	}
	return (0);
}

int	check_if_read(char **token, int j, char *s)
{
	if (s[j] == '<' && s[j + 1] != '<')
	{
		*token = malloc(sizeof(char) * 2);
		(*token)[0] = s[j];
		(*token)[1] = 0;
		return (1);
	}
	else if (s[j] == '<' && s[j + 1] == '<')
	{
		*token = malloc(sizeof(char) * 3);
		(*token)[0] = s[j];
		(*token)[1] = s[j + 1];
		(*token)[2] = 0;
		return (1);
	}
	return (0);
}

void	process_next_check(char *s, int j, t_attr *att, char **token)
{
	if (check_if_pipe(token, j, s))
		att->number_of_pipes++;
	else if (check_if_redir(token, j, s))
		att->number_of_redir++;
	else if (check_if_read(token, j, s))
		att->number_of_read++;
}
