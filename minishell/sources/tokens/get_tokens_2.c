/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/03 12:11:38 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_tokens2(char *s, t_attr *att)
{
	if (!s)
		return (0);
	att->l = ft_strlen(s) - 1;
	while (att->l >= 0)
	{
		if (att->pars_data.nb_tokenst == 0 || (s[att->l - 1] && (s[att->l + 1]
					== '|' || s[att->l + 1] == '<' || s[att->l + 1] == '>')))
			att->pars_data.nb_tokenst++;
		backup_in_quotes(s, '\'', att);
		backup_in_quotes(s, '"', att);
		if (s[att->l] != ' ' && s[att->l] != '|' && s[att->l] 
			!= '<' && s[att->l] != '>' && s[att->l]
			!= '"' && s[att->l] != '\'')
		{
			while (att->l >= 0 && (s[att->l] != '|' && s[att->l]
					!= '<' && s[att->l] != '>' && s[att->l]
					!= '"' && s[att->l] != '\''))
				att->l--;
		}
		else if (s[att->l] == ' ')
			att->l--;
		else if (s[att->l] == '|' || s[att->l] == '<' || s[att->l] == '>')
			att->l = process_next_token(att, s);
	}
	return (++att->pars_data.nb_tokenst);
}

char	*get_token2(char *s, t_attr *att)
{
	char	*token;
	int		i;

	i = 0;
	att->j = 0;
	token = 0;
	while (s[att->j])
	{
		if (s[0] == '|' || s[0] == '<' || s[0] == '>')
			return (process_next_check(s, att));
		advance_in_quotes(s, '\'', att);
		advance_in_quotes(s, '"', att);
		if (s[att->j] == '|' || s[att->j] == '<' || s[att->j] == '>')
			break ;
		att->j++;
	}
	token = malloc(sizeof(char) * (att->j + 1));
	while (i < att->j)
	{
		token[i] = s[i];
		i++;
	}
	token[att->j] = '\0';
	return (token);
}

void	create_array2(char *s, t_attr *att)
{
	int	count;

	att->index = 0;
	att->pars_data.pars_arr = malloc((att->pars_data.nb_tokenst + 1)
			* sizeof(char *));
	att->pars_data.pars_arr[att->pars_data.nb_tokenst] = NULL;
	if (!att->pars_data.pars_arr)
		return ;
	count = 0;
	while (count < att->pars_data.nb_tokenst)
	{
		while (*s == ' ')
			s++;
		att->pars_data.pars_arr[count] = get_token2(s, att);
		s += ft_strlen(att->pars_data.pars_arr[count]);
		count++;
	}
}

char	**get_tokens2(char *str, t_attr *att)
{
	if (!str)
		return (NULL);
	att->pars_data.nb_tokenst = 0;
	att->pars_data.pars_arr = NULL;
	count_tokens2(str, att);
	create_array2(str, att);
	return (att->pars_data.pars_arr);
}
