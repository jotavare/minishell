/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/31 03:15:51 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i++]);
	}
}

void	free_tokens(char **tokens, t_attr *t)
{
	int	i;

	i = 0;
	while (i <= t->nb_tokens)
		free(tokens[i++]);
}

void	free_g_env(t_attr *att)
{
	int	i;

	i = 0;
	while (att->g_env[i])
	{
		free(att->g_env[i]);
		i++;
	}
	//free(att->d_env[i]);
	free(att->g_env);
}

void	free_d_env(t_attr *att)
{
	int	i;

	i = 0;
	while (att->d_env[i])
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
	while (att->exp_env[i])
	{
		free(att->exp_env[i]);
		i++;
	}
	free(att->exp_env[i]);
	free(att->exp_env);
}

void	free_d_exp_env(t_attr *att)
{
	int	i;

	i = 0;
	while (att->d_exp_env[i])
	{
		free(att->d_exp_env[i]);
		i++;
	}
	free(att->d_exp_env);
}


void	exit_free(t_attr *attr)
{
	free_tokens(attr->tok_arr, attr);
	free(attr->tok_arr);
}
