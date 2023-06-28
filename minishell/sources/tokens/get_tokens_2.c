/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/28 17:18:57 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_tokens2(char *s, t_attr *att)
{
	int	len;

	if (!s)
		return (0);
	len = ft_strlen(s) - 1;
	while (len >= 0)
	{
		if (s[len] != ' ' && s[len] != '|' && s[len] != '<' && s[len] != '>')
		{
			att->pars_data.nb_tokenst++;
			while (len > 0 && (s[len] != '|' && s[len] != '<' && s[len] != '>'))
				len--;
		}
		if (s[len] == ' ')
			len--;
		else
			len = process_next_token(att, s, len);
	}
	return (att->pars_data.nb_tokenst++);
}

char	*get_token2(char *s, t_attr *att)
{
	char	*token;
	int		i;
	int		j;

	i = 0;
	j = 0;
	token = 0;
	if (s[j] != '|' && s[j] != '>' && s[j] != '<')
	{
		while (s[j] != '|' && s[j] != '>' && s[j] != '<' && s[j] != '\0')
			j++;
		token = malloc(sizeof(char) * (j + 1));
		if (!token)
			return (NULL);
		token[j] = '\0';
		while (i < j)
		{
			token[i] = s[i];
			i++;
		}
	}
	else
		process_next_check(s, j, att, &token);
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
