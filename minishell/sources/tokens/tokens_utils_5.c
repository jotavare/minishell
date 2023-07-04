/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:52:47 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:10:50 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	reinit_gt_var(t_attr *att, t_toki *tok)
{
	tok->gt_result = NULL;
	att->tok_arr_i = 0;
	tok->gt_flag = 0;
	tok->gt_quotes = 0;
}

char	*give_token(char *s, t_attr *att, t_toki *tok)
{
	if (tok->gt_quotes >= 2)
		return (process_multi_quote(s, att, tok));
	else
		return (process_default(s, att));
}

int	to_quote(char *s, t_attr *att, t_toki *tok)
{
	att->inside_single_quotes = 1;
	tok->gt_flag = 1;
	tok->gt_quotes++;
	if (att->o_quotes == tok->gt_quotes && s[att->tok_arr_i + 1])
	{
		if (s[att->tok_arr_i + 1] == ' ')
		{
			att->tok_arr_i++;
			return (1);
		}
	}
	return (0);
}

int	to_dquote(char *s, t_attr *att, t_toki *tok)
{
	att->inside_single_quotes = 0;
	tok->gt_flag = 2;
	tok->gt_quotes++;
	if (att->o_dquotes == tok->gt_quotes && s[att->tok_arr_i + 1])
	{
		if (s[att->tok_arr_i + 1] == ' ')
		{
			att->tok_arr_i++;
			return (1);
		}
	}
	return (0);
}
