/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/22 11:25:22 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
    main function of the export command
*/

void	export(t_attr *att)
{
	if (!att->tok_arr[1])
	{
		export_sort(att);
		export_print(att);
	}
}

/*
    sorts the environment variables alphabetically
    using the bubble sort algorithm
*/

void	export_sort(t_attr *att)
{
	int		sorted;
	int		i;
	char	*temp;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (att->g_env[i + 1] != NULL)
		{
			if (ft_strcmp(att->g_env[i], att->g_env[i + 1]) > 0)
			{
				temp = att->g_env[i];
				att->g_env[i] = att->g_env[i + 1];
				att->g_env[i + 1] = temp;
				sorted = 0;
			}
			i++;
		}
	}
}

/*
    prints the environment in the format required by the subject of the project
*/

void	export_print(t_attr *att)
{
	int	i;

	i = 0;
	while (att->g_env[i])
	{
		printf("declare -x %s\n", att->g_env[i]);
		i++;
	}
	printf("SIZE: %d\n", att->len_myenv);
}
