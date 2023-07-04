/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:14:03 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_d_exp_env(t_attr *att)
{
	int	i;

	i = 0;
	while (att->d_exp_env[i] != NULL)
	{
		free(att->d_exp_env[i]);
		i++;
	}
	free(att->d_exp_env);
}

void	exit_free(t_attr *att)
{
	free_tokens(att->tok_arr, att);
	free_g_env(att);
	free_exp_env(att);
	free_arr(att->commands_arr);
	ft_delete_matrix(att->pipesfd);
}

void	ft_delete_matrix(void *matrix)
{
	int	i;

	i = -1;
	while (((char **)matrix)[++i])
		free(((char **)matrix)[i]);
	free(matrix);
}

void	free_start_args(t_exec *args, t_attr *att)
{
	int	i;

	i = 0;
	if (att->has_path == 1)
	{
		while (args->all_paths[i] != NULL)
		{
			free(args->all_paths[i]);
			i++;
		}
		free(args->all_paths);
	}
}

void	free_child(t_attr *att, t_exec *args)
{
	free_start_args(args, att);
	free_g_env(att);
	free_exp_env(att);
	free_arr(att->commands_arr);
	ft_delete_matrix(att->pipesfd);
	free_tokens(att->tok_arr, att);
}
