/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/29 17:34:42 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
char    *expand_variable(const char *env_var)
{
    while(*env_var != '$')
        env_var++;
    char *exp_env_var = getenv(env_var + 1);
    return (exp_env_var);
}
*/

/*
    expands the environment variable after finding the '$' character
    returns the expanded environment variable afte the '=' character
*/

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