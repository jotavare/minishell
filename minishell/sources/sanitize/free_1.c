/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/21 19:20:23 by jotavare         ###   ########.fr       */
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
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

void	free_tokens(char **tokens, t_attr *att)
{
	int	i;

	i = 0;
	while (i < att->nb_tokens)
		free(tokens[i++]);
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
	free(att->d_env[i]);
	free(att->d_env);
}

void	free_exp_env(t_attr *att)
{
	int	i;

	i = 0;
	while (att->exp_env[i] != NULL)
	{
		free(att->exp_env[i]);
		i++;
	}
	free(att->exp_env[i]);
	free(att->exp_env);
}

void free_start_args(t_exec *args)
{
    int i = 0;
    while (args->all_paths[i] != NULL)
    {
        free(args->all_paths[i]);
        i++;
    }
    free(args->all_paths);
}
