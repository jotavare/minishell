/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/24 01:50:22 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
    custom implementation of the getenv() function.
    returns the value of the environment variable
    named "variable_name" and if not found, returns NULL.
*/

char	*custom_getenv(const char *variable_name, t_attr *att)
{
	int		i;
	char	*entry;
	char	*delimiter;
	size_t	variable_length;

	if (att->g_env == NULL)
		return (NULL);
	i = 0;
	while (att->g_env[i] != NULL)
	{
		entry = att->g_env[i];
		delimiter = ft_strchr(entry, '=');
		if (delimiter != NULL)
		{
			variable_length = delimiter - entry;
			if (ft_strncmp(entry, variable_name, variable_length) == 0
				&& variable_name[variable_length] == '\0')
				return (delimiter + 1);
		}
		i++;
	}
	return (NULL);
}

char	**expand_tokens(char **tokens, t_attr *att)
{
	char	*variable_name;
	char	*value;
	size_t	expanded_length;
	size_t	token_length;
	char	*expanded_token;
	int		j;
	int		i;
	int		has_quote;

	has_quote = 0;
	variable_name = NULL;
	value = NULL;
	expanded_length = 0;
	token_length = 0;
	expanded_token = NULL;
	i = 0;
	while (tokens[i])
	{
		j = 0;
		{
			if (tokens[i][j] == '\'')
				has_quote = 1;
			if (tokens[i][j] == '$' && tokens[i][j + 1])
			{
				variable_name = tokens[i] + j + 1;
				if (has_quote == 1)
					variable_name = has_correct_name(tokens[i] + j + 1);
				value = custom_getenv(variable_name, att);
				if (value)
				{
					expanded_length = ft_strlen(value);
					token_length = ft_strlen(tokens[i]);
					expanded_token = malloc((token_length + expanded_length + 1)
							* sizeof(char));
					ft_strncpy(expanded_token, tokens[i], j);
					expanded_token[j] = '\0';
					ft_strcat(expanded_token, value);
					ft_strcat(expanded_token, tokens[i] + j
							+ ft_strlen(variable_name) + 1);
					free(tokens[i]);
					tokens[i] = expanded_token;
					if (has_quote)
						free(variable_name); 
					j += expanded_length;
				}
			}
			j++;
		}
		i++;
	}
	return (tokens);
}

char	*has_correct_name(char *str)
{
	int	i;
	int j;
	char	*correct;

	correct = malloc(sizeof(char) * (ft_strlen(str)));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '\'')
		{
			correct[j] = str[i];
		    j++;
		}
		i++;
	}
	correct[j] = 0;
	return (correct);
}