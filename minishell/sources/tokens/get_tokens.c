/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/17 16:03:42 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_token(char *s, t_attr *att)
{
	int	flag;
	int	quotes;
	
	flag = 0;
	quotes = 0;
	att->tok_arr_i = 0;
	while (s[att->tok_arr_i])
	{
		if (s[att->tok_arr_i] == '"' && (flag == 0 || flag == 2))
		{
			flag = 2;
			quotes++;
			if (att->o_dquotes == quotes)
			{
				att->tok_arr_i++;
				break ;
			}
		}
		else if (s[att->tok_arr_i] == '\'' && (flag == 0 || flag == 1))
		{
			flag = 1;
			quotes++;
			if (att->o_quotes == quotes)
				{
					att->tok_arr_i++;
					break ;
				}
		}
		else if (s[att->tok_arr_i] == ' ' && att->o_quotes % 2 == 0 && att->o_dquotes
				% 2 == 0)
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
	if (att->o_dquotes >= 2 || att->o_quotes >= 2)
		return (process_multi_quote(s, att));
	else
		return (process_default(s, att));
}

char	*process_token_two(char *s, t_attr *att)
{
	char	*token;	token = malloc(sizeof(char) * 2);
	if (!token)
		return (NULL);
	token[0] = s[att->tok_arr_i];
	token[1] = '\0';
	return (token);
}

char	*process_token_three(char *s, t_attr *att)
{
	char	*token;	token = malloc(sizeof(char) * 3);
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
	char	*temp;
	
	temp = malloc(sizeof(char) * 2);
	temp[1] = 0;
	strncpy(temp, s, att->tok_arr_i);
	if (strncmp(temp, "\"\"", 2) == 0 || strncmp(temp, "''", 2) == 0)
	{
		if (strncmp(temp, "\"\"", 2) == 0)
			att->o_dquotes -= 2;
		else if (strncmp(temp, "''", 2) == 0)
			att->o_quotes -= 2;
		token = malloc(sizeof(char));
		if (!token)
			return (NULL);
		token[0] = '\0';
	}
	else
		token = double_quotes_treat(s, att);
	free(temp);
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


char	*double_quotes_treat(char *s, t_attr *att)
{
	char	*token;
	int		i;
	int		j;
	int		pos;
	int		flag;

	j = 0;
	i = 0;

	pos = att->tok_arr_i - 2;
	flag = 0;
	while (s[i])
	{
		if (s[i] == '"' && (flag == 0 || flag == 2))
		{
			flag = 2;
			att->o_dquotes--;
			j++;
			if (s[i + 1])
			{
				if (s[i + 1] == ' ' && j % 2 == 0)
				{
					i++;
					pos = i - j;
					token = malloc(sizeof(char) * pos);
					break ;
				}
			}
			else if (!s[i + 1])
				{
					i++;
					pos = i - j;
					token = malloc(sizeof(char) * pos);
					break ;
				}
		}
/* 		else if (s[i] == '\'' && (flag == 0 || flag == 1))
		{
			flag = 1;
			break ;
		} */
		i++;
	}
	token[pos] = 0;
	i = 0;
	j = 0;
/* 	if (flag == 1)
	{
		pos = att->tok_arr_i - att->o_quotes;
		token = malloc(sizeof(char) * pos);
		if (!token)
			return (NULL);
		token[pos] = '\0';
	} */
	while (j < pos && s[i] != '\0')
	{
		if (flag == 1)
		{
			while (s[i] != 39 && s[i] != '\0')
			{
				if (s[i] == 34)
					att->o_dquotes--;
				token[j] = s[i];
				j++;
				i++;
			}
			if (s[i] == 39)
				att->o_quotes--;
		}
		else if (flag == 2)
		{
			while (s[i] != 34 && s[i] != '\0')
			{
				if (s[i] == 39)
					att->o_quotes--;
				token[j] = s[i];
				j++;
				i++;
			}
		}
		i++;
	}
	return (token);
}