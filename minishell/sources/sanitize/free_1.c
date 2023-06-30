/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by jotavare          #+#    #+#             */
/*   Updated: 2023/06/30 06:13:48 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_in_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
}

void	free_tokens(char **tokens, t_attr *att)
{
	int	i;

	i = 0;
	while (i < att->nb_tokens)
		free(tokens[i++]);
	free(tokens);
}

void	free_g_env(t_attr *att)
{
	int	i;

	i = 0;
	while (att->g_env[i] != NULL)
	{
		free(att->g_env[i]);
		i++;
	}
	free(att->g_env);
}

void	free_d_env(t_attr *att)
{
	int	i;

	i = 0;
	while (att->d_env[i] != NULL)
	{
		free(att->d_env[i]);
		i++;
	}
	free(att->d_env);
}
