/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/31 02:24:52 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_arr(char **arr)
{
	int i = 0;

	while (arr[i])
	{
		free (arr[i++]);
	}
}

void	free_tokens(char **tokens, t_attr *t)
{
	int	i;

	i = 0;
	while (i < t->nb_tokens)
		free(tokens[i++]);
}

/*
void	final_free(t_attr *att)
{
	free(attr.last_path);
	free_g_env(&attr);
	free_exp_env(&attr);
}
*/