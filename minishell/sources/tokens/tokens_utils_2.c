/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:52:47 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/03 11:54:04 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*check_if_pipe(char *s, t_attr *att)
{
	char	*token;

	token = NULL;
	if (s[att->j] == '|' && s[att->j + 1] != '|')
	{
		token = malloc(sizeof(char) * 2);
		token[0] = s[att->j];
		token[1] = 0;
		att->number_of_pipes++;
		att->j = att->j + 1;
	}
	return (token);
}

char	*check_if_redir(char *s, t_attr *att)
{
	char	*token;

	token = NULL;
	if (s[att->j] == '>' && s[att->j + 1] != '>')
	{
		token = malloc(sizeof(char) * 2);
		token[0] = s[att->j];
		token[1] = 0;
		att->j = att->j + 1;
		att->number_of_redir++;
		return (token);
	}
	else if (s[att->j] == '>' && s[att->j + 1] == '>')
	{
		token = malloc(sizeof(char) * 3);
		token[0] = s[att->j];
		token[1] = s[att->j + 1];
		token[2] = 0;
		att->j = att->j + 2;
		att->number_of_redir++;
		return (token);
	}
	return (token);
}

char	*check_if_read(char *s, t_attr *att)
{
	char	*token;

	token = NULL;
	if (s[att->j] == '<' && s[att->j + 1] != '<')
	{
		token = malloc(sizeof(char) * 2);
		token[0] = s[att->j];
		token[1] = 0;
		att->j = att->j + 1;
		att->number_of_read++;
		return (token);
	}
	else if (s[att->j] == '<' && s[att->j + 1] == '<')
	{
		token = malloc(sizeof(char) * 3);
		token[0] = s[att->j];
		token[1] = s[att->j + 1];
		token[2] = 0;
		att->j = att->j + 2;
		att->number_of_read++;
		return (token);
	}
	return (token);
}

char	*process_next_check(char *s, t_attr *att)
{
	char	*token;

	token = NULL;
	token = check_if_pipe(s, att);
	if (token != NULL)
		return (token);
	token = check_if_redir(s, att);
	if (token != NULL)
		return (token);
	token = check_if_read(s, att);
	if (token != NULL)
		return (token);
	else
		return (NULL);
}

void	count_d_s_quotes(char *s, t_attr *att)
{
	int	i;
	int	single;

	i = 0;
	single = 0;
	while (s[i])
	{
		if (s[i] == '"')
		{
			if (single == 0)
				single = 2;
			att->o_dquotes++;
		}
		else if (s[i] == '\'')
		{
			if (single == 0)
				single = 1;
			att->o_quotes++;
		}
		i++;
	}
	if (single == 1)
		att->inside_single_quotes = 1;
	else if (single == 2 || single == 0)
		att->inside_single_quotes = 0;
}
