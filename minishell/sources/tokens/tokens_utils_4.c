/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:52:47 by joaoalme          #+#    #+#             */
/*   Updated: 2023/06/29 15:06:48 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	flag2up(char *s, t_attr *att, t_toki *tok)
{
	tok->flag = 2;
	att->o_dquotes--;
	while (s[tok->i])
	{
		if (s[tok->i] == 34)
			tok->j++;
		if (s[tok->i + 1])
		{
			if (s[tok->i + 1] == ' ' && tok->j % 2 == 0)
			{
				tok->i++;
				tok->pos = tok->i - tok->j;
				tok->token = quotentoken(s, att, tok);
				break ;
			}
		}
		else if (!s[tok->i + 1])
		{
			tok->i++;
			tok->pos = tok->i - tok->j;
			tok->token = quotentoken(s, att, tok);
			break ;
		}
		tok->i++;
	}
}

void	flag1up(char *s, t_attr *att, t_toki *tok)
{
	tok->flag = 1;
	att->o_quotes--;
	while (s[tok->i])
	{
		if (s[tok->i] == 39)
			tok->j++;
		if (s[tok->i + 1])
		{
			if (s[tok->i + 1] == ' ' && tok->j % 2 == 0)
			{
				tok->i++;
				tok->pos = tok->i - tok->j;
				tok->token = quotentoken(s, att, tok);
				break ;
			}
		}
		else if (!s[tok->i + 1])
		{
			tok->i++;
			tok->pos = tok->i - tok->j;
			tok->token = quotentoken(s, att, tok);
			break ;
		}
		tok->i++;
	}
}

char	*process_multi_quote(char *s, t_attr *att, t_toki *tok)
{
	reinit_toki(tok);
	while (s[tok->i])
	{
		if (s[tok->i] == '"' && (tok->flag == 0 || tok->flag == 2))
		{
			flag2up(s, att, tok);
			return (tok->token);
		}
		else if (s[tok->i] == '\'' && (tok->flag == 0 || tok->flag == 1))
		{
			flag1up(s, att, tok);
			return (tok->token);
		}
		else if (s[tok->i] == ' ' && tok->j % 2 == 0 && tok->j > 1)
		{
			tok->pos = tok->i - tok->j;
			tok->token = quotentoken(s, att, tok);
			return (tok->token);
		}
		tok->i++;
	}
	tok->pos = tok->i - tok->j;
	tok->token = quotentoken(s, att, tok);
	return (tok->token);
}

char	*process_single_quotes(char *s, t_attr *att, t_toki *tok)
{
	int	closed;

	closed = 0;
	while (tok->j < tok->pos && s[tok->i] != '\0')
	{
		if (s[tok->i] == 39)
			closed++;
		while (s[tok->i] != 39 && s[tok->i] != '\0')
		{
			if (closed >= 2 && s[tok->i] == ' ')
				return (tok->token);
			tok->token[tok->j] = s[tok->i];
			tok->j++;
			tok->i++;
		}
		if (s[tok->i] == 34)
			att->o_dquotes--;
		tok->i++;
	}
	return (tok->token);
}

char	*process_double_quotes(char *s, t_attr *att, t_toki *tok)
{
	int	closed;

	closed = 0;
	while (tok->j < tok->pos && s[tok->i] != '\0')
	{
		if (s[tok->i] == 34)
			closed++;
		while (s[tok->i] != 34 && s[tok->i] != '\0')
		{
			if (closed >= 2 && s[tok->i] == ' ')
				return (tok->token);
			tok->token[tok->j] = s[tok->i];
			tok->j++;
			tok->i++;
		}
		if (s[tok->i] == 39)
			att->o_quotes--;
		tok->i++;
	}
	return (tok->token);
}
