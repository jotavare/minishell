/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:52:47 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:11:21 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

void	reinit_toki(t_toki *tok)
{
	tok->j = 0;
	tok->i = 0;
	tok->pos = 0;
	tok->token = NULL;
	tok->flag = 0;
}

char	*process_special_char(char *s, t_attr *att)
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
