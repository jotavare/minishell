/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by alexfern          #+#    #+#             */
/*   Updated: 2023/06/30 23:10:43 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	create_array(char *s, t_attr *att, t_toki *tok)
{
	int	count;

	att->index = 0;
	att->beforet = malloc((att->nb_tokens + 1) * sizeof(char *));
	att->beforet[att->nb_tokens] = NULL;
	if (!att->beforet)
		return ;
	count = 0;
	while (count < att->nb_tokens)
	{
		while (*s == ' ')
			s++;
		att->beforet[count] = get_token(s, att, tok);
		if (att->beforet[count] == 0 && count < att->nb_tokens)
		{
			s = NULL;
			return ;
		}
		s += att->tok_arr_i;
		count++;
	}
}

char	**get_tokens(char *str, t_attr *att, t_toki *tok)
{
	if (!str)
		return (NULL);
	count_tokens(str, att);
	create_array(str, att, tok);
	return (att->beforet);
}

int	count_true_chars(char *str, t_toki *tok)
{
	while (str[tok->i])
	{
		if (str[tok->i] == 34)
		{
			tok->i++;
			dif_from_c(str, 34, tok);
		}
		else if (str[tok->i] == ' ')
			break ;
		else if (str[tok->i] == 39)
		{
			tok->i++;
			dif_from_c(str, 39, tok);
		}
		if (str[tok->i] != 34 && str[tok->i] != 39)
			tok->endmalloc++;
		tok->i++;
	}
	return (tok->endmalloc);
}

void	dif_from_c(char *str, char c, t_toki *tok)
{
	while (str[tok->i] != c)
	{
		tok->endmalloc++;
		tok->i++;
	}
}
