/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/24 02:15:31 by jotavare         ###   ########.fr       */
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
		if (s[len] != ' ' && s[len] != '|' && s[len] != '<' && s[len] != '>'
			&& s[len] != ';')
		{
			att->pars_data.nb_tokenst++;
			while (len > 0 && (s[len] != '|' && s[len] != '<' && s[len] != '>'
					&& s[len] != ';'))
				len--;
		}
		if (s[len] == ' ')
			len--;
		else if (s[len] == ';')
		{
			len--;
			att->pars_data.nb_tokenst++;
		}
		else if (s[len] == '|' && s[len - 1] != '|')
		{
			len--;
			att->pars_data.nb_tokenst++;
		}
		else if (s[len] == '|' && s[len - 1] == '|')
		{
			len--;
			len--;
			att->pars_data.nb_tokenst++;
		}
		else if (s[len] == '>' && s[len - 1] != '>')
		{
			len--;
			att->pars_data.nb_tokenst++;
		}
		else if (s[len] == '>' && s[len - 1] == '>')
		{
			len--;
			len--;
			att->pars_data.nb_tokenst++;
		}
		else if (s[len] == '<' && s[len - 1] != '<')
		{
			len--;
			att->pars_data.nb_tokenst++;
		}
		else if (s[len] == '<' && s[len - 1] == '<')
		{
			len--;
			len--;
			att->pars_data.nb_tokenst++;
		}
		else
			len--;
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
	if (s[j] != '|' && s[j] != '>' && s[j] != '<' && s[j] != ';')
	{
		while (s[j] != '|' && s[j] != '>' && s[j] != '<' && s[j] != ';'
			&& s[j] != '\0')
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
	else if (s[j] == ';')
	{
		token = malloc(sizeof(char) * 2);
		if (!token)
			return (NULL);
		token[0] = s[j];
		token[1] = 0;
	}
	else if (s[j] == '|' && s[j + 1] != '|')
	{
		token = malloc(sizeof(char) * 2);
		if (!token)
			return (NULL);
		token[0] = s[j];
		token[1] = 0;
		att->number_of_pipes++;
	}
	else if (s[j] == '|' && s[j + 1] == '|')
	{
		token = malloc(sizeof(char) * 3);
		if (!token)
			return (NULL);
		token[0] = s[j];
		token[1] = s[j + 1];
		token[2] = 0;
	}
	else if (s[j] == '>' && s[j + 1] != '>')
	{
		token = malloc(sizeof(char) * 2);
		if (!token)
			return (NULL);
		token[0] = s[j];
		token[1] = 0;
		att->number_of_redir++;
	}
	else if (s[j] == '>' && s[j + 1] == '>')
	{
		token = malloc(sizeof(char) * 3);
		if (!token)
			return (NULL);
		token[0] = s[j];
		token[1] = s[j + 1];
		token[2] = 0;
		att->number_of_append++;
	}
	else if (s[j] == '<' && s[j + 1] != '<')
	{
		token = malloc(sizeof(char) * 2);
		if (!token)
			return (NULL);
		token[0] = s[j];
		token[1] = 0;
	}
	else if (s[j] == '<' && s[j + 1] == '<')
	{
		token = malloc(sizeof(char) * 3);
		if (!token)
			return (NULL);
		token[0] = s[j];
		token[1] = s[j + 1];
		token[2] = 0;
	}
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
