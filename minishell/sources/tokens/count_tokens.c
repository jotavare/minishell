/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/08 02:03:31 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_tokens(char *s, t_attr *att)
{
	int	len;

	len = ft_strlen(s) - 1;
	while (len >= 0)
	{
		if (s[len] == '\'')
			len = check_single_quotes(s, len, att);
		else if (s[len] == '"')
			len = check_double_quotes(s, len, att);
		else if (s[len] != ' ')
			len = check_non_space_char(s, len, att);
		else if (s[len] != ' ' && s[len] != '|' && s[len] != '<'
				&& s[len] != '>')
			len = check_special_char(s, len, att);
		else if (s[len] == ' ')
			len--;
		else
			len--;
	}
	return (att->nb_tokenst);
}

int	check_single_quotes(char *s, int len, t_attr *att)
{
	len--;
	while (len >= 0 && s[len] != '\'')
	{
		len--;
	}
	att->nb_tokenst++;
	len--;
	return (len);
}

int	check_double_quotes(char *s, int len, t_attr *att)
{
	len--;
	while (len >= 0 && s[len] != '"')
	{
		len--;
	}
	att->nb_tokenst++;
	len--;
	return (len);
}

int	check_non_space_char(char *s, int len, t_attr *att)
{
	att->nb_tokenst++;
	while (len >= 0 && s[len] != ' ')
	{
		len--;
	}
	return (len);
}

int	check_special_char(char *s, int len, t_attr *att)
{
	att->nb_tokenst++;
	while (len >= 0 && (s[len] != ' ' && s[len] != '|' && s[len] != '<'
			&& s[len] != '>'))
	{
		len--;
	}
	return (len);
}