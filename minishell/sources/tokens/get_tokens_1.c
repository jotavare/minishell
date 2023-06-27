/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/24 02:15:10 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_token(char *s, t_attr *att)
{
	int	flag;
	int	quotes;

	att->inside_single_quotes = 0;
	flag = 0;
	quotes = 0;
	att->tok_arr_i = 0;
	while (s[att->tok_arr_i])
	{
		if (s[att->tok_arr_i] == '"' && (flag == 0 || flag == 2))
		{
			flag = 2;
			quotes++;
			if (att->o_dquotes == quotes && s[att->tok_arr_i + 1])
			{
				if (s[att->tok_arr_i + 1] == ' ')
				{
					att->tok_arr_i++;
					break ;
				}
			}
		}
		else if (s[att->tok_arr_i] == '\'' && (flag == 0 || flag == 1))
		{
			flag = 1;
			quotes++;
			if (att->o_quotes == quotes && s[att->tok_arr_i + 1])
			{
				if (s[att->tok_arr_i + 1] == ' ')
				{
					att->tok_arr_i++;
					break ;
				}
			}
		}
		else if (s[att->tok_arr_i] == ' ' && quotes % 2 == 0 && quotes % 2 == 0)
			break ;
		else if (s[att->tok_arr_i] == '|' && s[att->tok_arr_i + 1] != '|'
				&& att->o_quotes % 2 == 0 && att->o_dquotes % 2 == 0)
			return (process_token_two(s, att));
		else if (s[att->tok_arr_i] == '|' && s[att->tok_arr_i + 1] == '|'
				&& att->o_quotes % 2 == 0 && att->o_dquotes % 2 == 0)
			return (process_token_three(s, att));
		else if (s[att->tok_arr_i] == '>' && s[att->tok_arr_i + 1] != '>'
				&& att->o_quotes % 2 == 0 && att->o_dquotes % 2 == 0)
			return (process_token_two(s, att));
		else if (s[att->tok_arr_i] == '>' && s[att->tok_arr_i + 1] == '>'
				&& att->o_quotes % 2 == 0 && att->o_dquotes % 2 == 0)
			return (process_token_three(s, att));
		else if (s[att->tok_arr_i] == '<' && s[att->tok_arr_i + 1] != '<'
				&& att->o_quotes % 2 == 0 && att->o_dquotes % 2 == 0)
			return (process_token_two(s, att));
		else if (s[att->tok_arr_i] == '<' && s[att->tok_arr_i + 1] == '<'
				&& att->o_quotes % 2 == 0 && att->o_dquotes % 2 == 0)
			return (process_token_three(s, att));
		att->tok_arr_i++;
	}
	if (quotes >= 2)
	{
		return (process_multi_quote(s, att));
	}
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

char	*process_default(char *s, t_attr *att)
{
	char	*token;
	int		i;

	i = 0;
	token = malloc(sizeof(char) * (att->tok_arr_i + 1));
	if (!token)
		return (NULL);
	token[att->tok_arr_i] = '\0';
	while (i < att->tok_arr_i)
	{
		token[i] = s[i];
		i++;
	}
	return (token);
}

char	*process_multi_quote(char *s, t_attr *att)
{
	char	*token;
	int		i;
	int		j;
	int		pos;
	int		flag;

	j = 0;
	i = 0;
	token = NULL;
	flag = 0;
	while (s[i])
	{
		if (s[i] == '"' && (flag == 0 || flag == 2))
		{
			att->inside_single_quotes = 0;
			flag = 2;
			att->o_dquotes--;
			j++;
			if (s[i + 1])
			{
				if (s[i + 1] == ' ' && j % 2 == 0)
				{
					i++;
					pos = i - j;
					token = quotentoken(s, att, flag, pos);
					return (token);
				}
			}
			else if (!s[i + 1])
			{
				i++;
				pos = i - j;
				token = quotentoken(s, att, flag, pos);
				return (token);
			}
		}
		if (s[i] == '\'' && (flag == 0 || flag == 1))
		{
			flag = 1;
			att->inside_single_quotes = 1;
			att->o_quotes--;
			j++;
			if (s[i + 1])
			{
				if (s[i + 1] == ' ' && j % 2 == 0)
				{
					i++;
					pos = i - j;
					token = quotentoken(s, att, flag, pos);
					return (token);
				}
			}
			else if (!s[i + 1])
			{
				i++;
				pos = i - j;
				token = quotentoken(s, att, flag, pos);
				return (token);
			}
		}
		if (s[i] == ' ' && j % 2 == 0 && j > 1)
		{
			pos = i - j;
			token = quotentoken(s, att, flag, pos);
			return (token);
		}
		i++;
	}
	pos = i - j;
	token = quotentoken(s, att, flag, pos);
	return (token);
}

char	*quotentoken(char *s, t_attr *att, int flag, int pos)
{
	int i;
	int j;
	char *token;
	int closed;

	token = malloc(sizeof(char) * (pos + 1));
	token[pos] = 0;
	closed = 0;
	i = 0;
	j = 0;
	while (j < pos && s[i] != '\0')
	{
		if (flag == 1)
		{
			if (s[i] == 39)
				closed++;
			while (s[i] != 39 && s[i] != '\0')
			{
				if (closed >= 2 && s[i] == ' ')
					return (token);
				token[j] = s[i];
				j++;
				i++;
			}
			if (s[i] == 34)
				att->o_dquotes--;
		}
		else if (flag == 2)
		{
			if (s[i] == 34)
				closed++;
			while (s[i] != 34 && s[i] != '\0')
			{
				if (closed >= 2 && s[i] == ' ')
					return (token);
				token[j] = s[i];
				j++;
				i++;
			}
			if (s[i] == 39)
				att->o_quotes--;
		}
		i++;
	}
	return (token);
}