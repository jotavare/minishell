/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/08 02:03:27 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_token(char *s, t_attr *att)
{
	int	o_quotes;
	int	o_dquotes;

	o_quotes = 0;
	o_dquotes = 0;
	att->tok_arr_i = 0;
	while (s[att->tok_arr_i])
	{
		if (s[att->tok_arr_i] == '"')
			o_dquotes++;
		else if (s[att->tok_arr_i] == '\'')
			o_quotes++;
		else if ((s[att->tok_arr_i] == '"' && o_dquotes % 2 == 0)
					|| (s[att->tok_arr_i] == '"' && (o_quotes % 2 == 0)))
		{
			att->tok_arr_i++;
			break ;
		}
		else if (s[att->tok_arr_i] == ' ' && o_quotes % 2 == 0 && o_dquotes
				% 2 == 0)
			break ;
		else if (s[att->tok_arr_i] == '|' && s[att->tok_arr_i + 1] != '|'
				&& o_quotes % 2 == 0 && o_dquotes % 2 == 0)
			return (process_token_two(s, att));
		else if (s[att->tok_arr_i] == '|' && s[att->tok_arr_i + 1] == '|'
				&& o_quotes % 2 == 0 && o_dquotes % 2 == 0)
			return (process_token_three(s, att));
		else if (s[att->tok_arr_i] == '>' && s[att->tok_arr_i + 1] != '>'
				&& o_quotes % 2 == 0 && o_dquotes % 2 == 0)
			return (process_token_two(s, att));
		else if (s[att->tok_arr_i] == '>' && s[att->tok_arr_i + 1] == '>'
				&& o_quotes % 2 == 0 && o_dquotes % 2 == 0)
			return (process_token_three(s, att));
		else if (s[att->tok_arr_i] == '<' && s[att->tok_arr_i + 1] != '<'
				&& o_quotes % 2 == 0 && o_dquotes % 2 == 0)
			return (process_token_two(s, att));
		else if (s[att->tok_arr_i] == '<' && s[att->tok_arr_i + 1] == '<'
				&& o_quotes % 2 == 0 && o_dquotes % 2 == 0)
			return (process_token_three(s, att));
		att->tok_arr_i++;
	}
	if (o_dquotes > 1 || o_quotes > 1)
		return (process_multi_quote(s, att));
	else
		return (process_default(s, att));
}

char	*process_token_two(char *s, t_attr *att)
{
	char	*token;

	token = malloc(sizeof(char) * 2);
	if (!token)
		return (NULL);
	token[0] = s[att->tok_arr_i];
	token[1] = '\0';
	return (token);
}

char	*process_token_three(char *s, t_attr *att)
{
	char	*token;

	token = malloc(sizeof(char) * 3);
	if (!token)
		return (NULL);
	token[0] = s[att->tok_arr_i];
	token[1] = s[att->tok_arr_i + 1];
	token[2] = '\0';
	return (token);
}

char	*process_multi_quote(char *s, t_attr *att)
{
	char	*token;
	int		i;

	token = malloc(sizeof(char) * (att->tok_arr_i - 2));
	if (!token)
		return (NULL);
	token[att->tok_arr_i - 2] = '\0';
	i = 0;
	while (i < att->tok_arr_i - 2)
	{
		token[i] = s[i + 1];
		i++;
	}
	return (token);
}

char	*process_default(char *s, t_attr *att)
{
	char	*token;
	int		i;

	token = malloc(sizeof(char) * (att->tok_arr_i + 1));
	if (!token)
		return (NULL);
	token[att->tok_arr_i] = '\0';
	i = 0;
	while (i < att->tok_arr_i)
	{
		token[i] = s[i];
		i++;
	}
	return (token);
}
