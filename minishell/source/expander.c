/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/01 17:32:31 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
    expands the tokens that start with a '$' sign and 
    replaces the token with the value of the environment
    variable named after the token.
*/

char	**expand_tokens(char **tokens, t_attr *att)
{
	int		i;
	char	*value;
	size_t	expanded_length;
	char	*expanded_token;

	i = 0;
	while (tokens[i] != NULL)
	{
		if (tokens[i][0] == '$' && tokens[i][1] != '\0')
		{
			char *variable_name = tokens[i] + 1;
			value = custom_getenv(variable_name, att);
			if (value != NULL)
			{
				expanded_length = ft_strlen(value);
				expanded_token = malloc((expanded_length + 1) * sizeof(char));
				ft_strcpy(expanded_token, value);
				free(tokens[i]);
				tokens[i] = expanded_token;
			}
		}
		i++;
	}
	return (tokens);
}

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
