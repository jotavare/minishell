/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:38:30 by jotavare          #+#    #+#             */
/*   Updated: 2023/06/30 06:14:25 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	see_flags_and_pipes(t_attr att)
{
	printf("----------------------\n");
	printf("nb of pipes: %d\n", att.number_of_pipes);
	printf("token: %s, index: %d\n", att.commands_arr[att.i], att.i);
	printf("read from pipe: %d\n", att.read_from_pipe);
	printf("write to pipe: %d\n", att.write_to_pipe);
	printf("redir: %d\n", att.redir);
	printf("read from file: %d\n", att.read_from_file);
	printf("----------------------\n");
}

void	ft_print_array(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		printf ("%d - %s\n", i, array[i]);
		i++;
	}
	printf("end of array\n\n");
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
	free(att->exp_env);
}
