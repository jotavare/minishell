/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/22 21:12:07 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char **expand_tokens(char** tokens, t_attr *att)
{
    int i = 0;
    while (tokens[i] != NULL)
	{
        if (tokens[i][0] == '$' && tokens[i][1] != '\0')
		{
            char *variable_name = tokens[i] + 1; // Skip the '$' sign
				
            char *value = custom_getenv(variable_name, att);
            if (value != NULL)
			{
                size_t expanded_length = ft_strlen(value);
                char* expanded_token = malloc((expanded_length + 1) * sizeof(char));
                ft_strcpy(expanded_token, value);
                free(tokens[i]);
                tokens[i] = expanded_token;
            }
        }
        i++;
    }
    return tokens;
}

char    *custom_getenv(const char* variable_name, t_attr *att)
{
    if (att->g_env == NULL)
        return NULL;

    int i = 0;
    while (att->g_env[i] != NULL)
    {
        char* entry = att->g_env[i];
        char* delimiter = ft_strchr(entry, '=');
        if (delimiter != NULL)
        {
            size_t variable_length = delimiter - entry;
            if (ft_strncmp(entry, variable_name, variable_length) == 0 && variable_name[variable_length] == '\0')
                return delimiter + 1; // Return the value after the '=' sign
        }
        i++;
    }

    return NULL; // Variable not found
}


char *ft_strcpy(char* destination, const char* source)
{
    char* start = destination;

    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';  // Append null character at the end
    return start;
}

/*
char    *expand_variable(const char *env_var, char **g_env)
{
    // Find the '$' character
    while (*env_var != '$')
    {
        if (*env_var == '\0')
            break ;  // Reached the end of the string without finding '$'
        printf("%c", *env_var);
        env_var++;
    }

    // Increment the pointer to skip '$'
    env_var++;
    
    // Search for the matching environment variable
    char *exp_env_var = NULL;
    int i = 0;
    while (g_env[i])
    {
        if (!strncmp(g_env[i], env_var, strlen(env_var)))
        {
            char *equals_sign = strchr(g_env[i], '=');
            if (equals_sign)
            {
                exp_env_var = equals_sign + 1;
            }
            break;
        }
        i++;
    }
    if(!exp_env_var)
        exp_env_var = "";
    return(exp_env_var);
}
*/

/*
bool verify_quotes(const char *str)
{
    bool inside_quotes = false;
    bool inside_double_quotes = false;

    while (*str != '\0') {
        if (*str == '\'') {
            // Single quote encountered
            if (inside_quotes) {
                inside_quotes = false;  // Closing quote
            } else {
                inside_quotes = true;  // Opening quote
            }
        } else if (*str == '"') {
            // Double quote encountered
            if (inside_double_quotes) {
                inside_double_quotes = false;  // Closing quote
            } else {
                inside_double_quotes = true;  // Opening quote
            }
        }

        str++;
    }

    // Verify that all quotes are closed
    if (inside_quotes || inside_double_quotes) {
        return false;
    }

    return true;
}*/