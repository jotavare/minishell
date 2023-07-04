/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:12:59 by alexfern         ###   ########.fr       */
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
		if (tok->gt_flag == 0)
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

char	*quotentoken(char *s, t_toki *tok)
{
	tok->i = 0;
	tok->endmalloc = 0;
	tok->pos = count_true_chars(s, tok);
	tok->token = malloc(sizeof(char) * (tok->pos + 1));
	tok->token[tok->pos] = 0;
	tok->i = 0;
	tok->j = 0;
	deal_with_it(s, tok);
	return (tok->token);
}

void	deal_with_it(char *s, t_toki *tok)
{
	while (tok->j < tok->pos && s[tok->i])
	{
		if (s[tok->i] == 34)
		{
			tok->i++;
			while (s[tok->i] != 34)
				deal_aux(s, tok);
		}
		else if (s[tok->i] == ' ')
			break ;
		else if (s[tok->i] == 39)
		{
			tok->i++;
			while (s[tok->i] != 39)
				deal_aux(s, tok);
		}
		if (s[tok->i] != 34 && s[tok->i] != 39)
		{
			tok->token[tok->j] = s[tok->i];
			tok->j++;
		}
		tok->i++;
	}
}

void	deal_aux(char *s, t_toki *tok)
{
	tok->token[tok->j] = s[tok->i];
	tok->i++;
	tok->j++;
}
