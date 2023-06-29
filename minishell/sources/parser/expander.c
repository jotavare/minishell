/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/29 12:15:59 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
    custom implementation of the getenv() function.
    returns the value of the environment variable
    named "var_name" and if not found, returns NULL.
*/

char	*custom_getenv(const char *var_name, t_attr *att)
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
			if (ft_strncmp(entry, var_name, variable_length) == 0
				&& var_name[variable_length] == '\0')
				return (delimiter + 1);
		}
		i++;
	}
	return (NULL);
}

void	init_var(t_exp *var)
{
	var->var_name = NULL;
	var->value = NULL;
	var->expanded_length = 0;
	var->token_length = 0;
	var->expanded_token = 0;
	var->i = 0;
	var->j = 0;
	var->has_quote = 0;
}

void	expand_tokens2(char **tokens, t_exp *info, int j)
{
	info->expanded_length = ft_strlen(info->value);
	info->token_length = ft_strlen(tokens[info->i]) - j + 1;
	info->expanded_token = malloc((info->token_length
				+ info->expanded_length + 1) * sizeof(char));
	ft_strncpy(info->expanded_token, tokens[info->i], j);
	info->expanded_token[j] = '\0';
	ft_strcat(info->expanded_token, info->value);
	ft_strcat(info->expanded_token, tokens[info->i]
		+ j + ft_strlen(info->var_name) + 1);
	free(tokens[info->i]);
	tokens[info->i] = info->expanded_token;
	if (info->has_quote)
		free(info->var_name);
	j += info->expanded_length;
}

char	**expand_tokens(char **tokens, t_attr *att)
{
	t_exp	info;
	int		j;

	init_var(&info);
	while (tokens[info.i])
	{
		j = 0;
		while (tokens[info.i][j])
		{
			if (tokens[info.i][j] == '"')
				info.has_quote = 1;
			else if ((tokens[info.i][j] == '$' && tokens[info.i][j + 1]))
			{
				info.var_name = tokens[info.i] + j + 1;
				if (info.has_quote == 1)
					info.var_name = correct_name(tokens[info.i] + j + 1);
				info.value = custom_getenv(info.var_name, att);
				if (info.value)
					expand_tokens2(tokens, &info, j);
			}
			j++;
		}
		info.i++;
	}
	return (tokens);
}

char	*correct_name(char *str)
{
	int		i;
	int		j;
	char	*correct;

	correct = malloc(sizeof(char) * (ft_strlen(str) + 1));
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
