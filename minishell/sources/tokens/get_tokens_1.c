/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/29 00:28:06 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* void	get_token_aux(char *s, t_attr *att, t_toki tok)
{
	
}*/

char	*get_token(char *s, t_attr *att, t_toki tok)
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
				att->inside_single_quotes = 0;
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
			att->inside_single_quotes = 1;
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
		return (process_multi_quote(s, att, &tok));
	else
		return (process_default(s, att));
}

char	*quotentoken(char *s, t_attr *att, t_toki *tok)
{
	tok->token = malloc(sizeof(char) * (tok->pos + 1));
	tok->token[tok->pos] = 0;
	tok->i = 0;
	tok->j = 0;
	while (tok->j < tok->pos && s[tok->i] != '\0')
	{
		if (tok->flag == 1)
			tok->token = process_single_quotes(s, att, tok);
		else if (tok->flag == 2)
			tok->token = process_double_quotes(s, att, tok);
		tok->i++;
	}
	return (tok->token);
}
