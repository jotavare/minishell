/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:52:47 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:11:07 by alexfern         ###   ########.fr       */
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
				tok->token = quotentoken(s, tok);
				break ;
			}
		}
		else if (!s[tok->i + 1])
		{
			tok->i++;
			tok->pos = tok->i - tok->j;
			tok->token = quotentoken(s, tok);
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
				tok->token = quotentoken(s, tok);
				break ;
			}
		}
		else if (!s[tok->i + 1])
		{
			tok->i++;
			tok->pos = tok->i - tok->j;
			tok->token = quotentoken(s, tok);
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
			tok->token = quotentoken(s, tok);
			return (tok->token);
		}
		tok->i++;
	}
	tok->token = quotentoken(s, tok);
	return (tok->token);
}
