/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:33:44 by alexfern         ###   ########.fr       */
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
	var->x = 0;
	var->y = 0;
	var->correct = NULL;
	var->len = 0;
	var->full = 0;
}

void	expand_tokens2(char **tokens, t_exp *info)
{
	info->expanded_length = ft_strlen(info->value);
	info->token_length = ft_strlen(tokens[info->i]) - info->j + 1;
	info->expanded_token = malloc((info->token_length
				+ info->expanded_length + 1) * sizeof(char));
	ft_strncpy(info->expanded_token, tokens[info->i], info->j);
	info->expanded_token[info->j] = '\0';
	ft_strcat(info->expanded_token, info->value);
	ft_strcat(info->expanded_token, tokens[info->i]
		+ info->j + ft_strlen(info->var_name) + 1);
	free(tokens[info->i]);
	tokens[info->i] = info->expanded_token;
	if (info->var_name)
		free(info->var_name);
	info->j += info->expanded_length;
}

void	countj(char *str, t_exp *info)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			break ;
		i++;
		info->j++;
	}
}

char	**expand_tokens(char **tokens, t_attr *att)
{
	t_exp	info;

	init_var(&info);
	while (tokens[info.i])
	{
		info.j = 0;
		find_it(tokens[info.i], &info);
		info.value = custom_getenv(info.var_name, att);
		if (info.value)
			expand_tokens2(tokens, &info);
		if (!info.value)
			free(info.correct);
		info.i++;
	}
	return (tokens);
}
