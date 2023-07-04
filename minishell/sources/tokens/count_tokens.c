/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:13:18 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_tokens(char *s, t_attr *att)
{
	int	len;
	int	i;

	count_d_s_quotes(s, att);
	att->nb_tokens = 0;
	len = ft_strlen(s) - 1;
	i = 0;
	while (i <= len)
	{
		if (s[i] == '\'')
			i = check_single_quotes(s, len, i, att);
		else if (s[i] == '"')
			i = check_double_quotes(s, len, i, att);
		else if (s[i] != ' ')
			i = check_non_space_char(s, len, i, att);
		else if (s[i] != ' ' && s[i] != '|' && s[i] != '<'
			&& s[i] != '>')
			i = check_special_char(s, len, i, att);
		else if (s[i] == ' ')
			i++;
		else
			i++;
	}
	return (att->nb_tokens);
}

int	check_single_quotes(char *s, int len, int i, t_attr *att)
{
	int	quotes;

	quotes = 0;
	att->nb_tokens++;
	if (s[i + 1] && s[i + 1] == '\''
		&& ((s[i + 2] && s[i + 2] == ' ') || !s[i + 2]))
		return (i + 2);
	while (i <= len && quotes <= att->o_quotes)
	{
		if (s[i] == '\'')
			quotes++;
		if (quotes % 2 == 0 && s[i + 1] && s[i + 1] == ' ')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}

int	check_double_quotes(char *s, int len, int i, t_attr *att)
{
	int	quotes;

	quotes = 0;
	att->nb_tokens++;
	if (s[i + 1] && s[i + 1] == '"'
		&& ((s[i + 2] && s[i + 2] == ' ') || !s[i + 2]))
		return (i + 2);
	while (i <= len && quotes <= att->o_dquotes)
	{
		if (s[i] == '"')
			quotes++;
		if (quotes % 2 == 0 && s[i + 1] && s[i + 1] == ' ')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}

int	check_non_space_char(char *s, int len, int i, t_attr *att)
{
	att->nb_tokens++;
	while (i <= len && s[i] != ' ')
		i++;
	return (++i);
}

int	check_special_char(char *s, int len, int i, t_attr *att)
{
	att->nb_tokens++;
	while (i <= len && (s[i] != ' ' && s[i] != '|' && s[i] != '<'
			&& s[i] != '>'))
		i++;
	return (++i);
}
