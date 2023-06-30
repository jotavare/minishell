/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by jotavare          #+#    #+#             */
/*   Updated: 2023/06/30 06:14:00 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_token(char *s, t_attr *att, t_toki *tok)
{
	reinit_gt_var(att, tok);
	while (s[att->tok_arr_i])
	{
		if (s[att->tok_arr_i] == '"' && (tok->gt_flag == 0
				|| tok->gt_flag == 2))
		{
			if (to_dquote(s, att, tok) == 1)
				break ;
		}
		else if (s[att->tok_arr_i] == '\'' && (tok->gt_flag == 0
				|| tok->gt_flag == 1))
		{
			if (to_quote(s, att, tok) == 1)
				break ;
		}
		else if (s[att->tok_arr_i] == ' ' && tok->gt_quotes % 2 == 0
			&& tok->gt_quotes % 2 == 0)
			break ;
		tok->gt_result = processt2_t3(s, att);
		if (tok->gt_result != NULL)
			return (tok->gt_result);
		att->tok_arr_i++;
	}
	return (give_token(s, att, tok));
}

char	*processt2_t3(char *s, t_attr *att)
{
	if (s[att->tok_arr_i] == '|' && s[att->tok_arr_i + 1] != '|'
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
	return (NULL);
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
