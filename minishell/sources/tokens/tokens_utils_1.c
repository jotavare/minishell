/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:52:47 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:11:47 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	count_quotes(char *s, t_attr *att)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '"')
			att->o_dquotes++;
		else if (s[i] == '\'')
			att->o_quotes++;
		i++;
	}
}

int	process_next_token(t_attr *att, char *s)
{
	if (count_if_pipe(att, s))
		return (att->l);
	else if (count_if_redir(att, s))
		return (att->l);
	else if (count_if_read(att, s))
		return (att->l);
	else
		return (att->l - 1);
}

int	count_if_pipe(t_attr *att, char *s)
{
	if (s[att->l] == '|' && s[att->l - 1] != '|')
	{
		att->l = att->l - 1;
		att->pars_data.nb_tokenst++;
		return (1);
	}
	else if (s[att->l] == '|' && s[att->l - 1] == '|')
	{
		att->l = att->l - 2;
		att->pars_data.nb_tokenst++;
		return (1);
	}
	return (0);
}

int	count_if_redir(t_attr *att, char *s)
{
	if (s[att->l] == '>' && s[att->l - 1] != '>')
	{
		att->l = att->l - 1;
		att->pars_data.nb_tokenst++;
		return (1);
	}
	else if (s[att->l] == '>' && s[att->l - 1] == '>')
	{
		att->l = att->l - 2;
		att->pars_data.nb_tokenst++;
		return (1);
	}
	return (0);
}

int	count_if_read(t_attr *att, char *s)
{
	if (s[att->l] == '<' && s[att->l - 1] != '<')
	{
		att->l = att->l - 1;
		att->pars_data.nb_tokenst++;
		return (1);
	}
	else if (s[att->l] == '<' && s[att->l - 1] == '<')
	{
		att->l = att->l - 2;
		att->pars_data.nb_tokenst++;
		return (1);
	}
	return (0);
}
