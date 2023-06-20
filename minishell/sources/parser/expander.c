/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/20 02:15:05 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
    expands the tokens that start with a '$' sign and 
    replaces the token with the value of the environment
    variable named after the token.
*/

/* char	**expand_tokens(char **tokens, t_attr *att)
{
	int		i;
	char	*value;
	size_t	expanded_length;
	char	*expanded_token;
	char	*variable_name;
	int		j;

	i = 0;
	while (tokens[i])
	{
		j = 0;
		while (tokens[i][j])
		{
			if (tokens[i][j] == '$')
			{
				j = 0;
				while (tokens[i][j] != '$' && tokens[i][j])
				{
					ft_putchar_fd(tokens[i][j++], 1);
				}
			}
		}
		i++;
	}
	i = 0;
	while (tokens[i] != NULL)
	{
		j = 0;
		while (tokens[i][j])
		{
			if (tokens[i][j] == '$' && tokens[i][j + 1] != '\0')
			{
				j++;
				variable_name = tokens[i] + j;
				//printf("var=<%s>\n", variable_name);
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
			j++;
		}
		i++;
	}
	return (tokens);
} */

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

char **expand_tokens(char **tokens, t_attr *att)
{
	char *variable_name = NULL;
	char *value = NULL;
	size_t expanded_length = 0;
	size_t token_length = 0;
	char *expanded_token = NULL;
	int		j;
	int		i;
	
    i = 0;

	if (expanded_token == NULL)
		return (NULL);
    while (tokens[i])
    {
        j = 0;
        while (tokens[i][j])
        {
            if (tokens[i][j] == '$' && tokens[i][j + 1])
            {
                variable_name = tokens[i] + j + 1;
                value = custom_getenv(variable_name, att);
                if (value)
                {
                    expanded_length = strlen(value);
                    token_length = strlen(tokens[i]);
                    expanded_token = malloc((token_length + expanded_length + 1) * sizeof(char));
					strncpy(expanded_token, tokens[i], j); // Copy the portion before the variable
                    expanded_token[j] = '\0'; // Null-terminate the copied portion
                    strcat(expanded_token, value); // Concatenate the expanded value
                    strcat(expanded_token, tokens[i] + j + strlen(variable_name) + 1); // Concatenate the remaining part
                    free(tokens[i]);
                    tokens[i] = expanded_token;
                    j += expanded_length; // Skip the expanded part in the token
                }
            }
            j++;
        }
        i++;
    }
    return (tokens);
}
