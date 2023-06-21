/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/21 18:00:55 by jotavare         ###   ########.fr       */
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
	free(att->tok_arr);
}

void	ft_delete_matrix(void *matrix)
{
	int	i;

	i = -1;
	while (((char **)matrix)[++i])
		free(((char **)matrix)[i]);
	free(matrix);
}
