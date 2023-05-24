/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/24 13:39:56 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_equal(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '=')
			return (0);
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	already_exist(t_attr *att, char *add)
{
	int i = 0;
	int j = 0;

	while (add[j] != '=')
		j++;
	j++;
	while (att->g_env[i])
	{
		if (ft_strncmp(att->d_env[i], add_equal(add), j) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	refresh_addenv(t_attr *att, char *add)
{
	int i = 0;

	free_g_env(att);
	att->g_env = malloc(sizeof(char *) * att->len_myenv + 2);
	if(!att->g_env)
		return ;
	while (i < att->len_myenv)
	{
		att->g_env[i] = ft_strdup(att->d_env[i]);
		i++;
	}
	att->g_env[att->len_myenv] = ft_strdup(add);
	att->len_myenv++;
	att->g_env[att->len_myenv] = '\0';
}

/*
    main function of the export command
*/

void	export(t_attr *att)
{
	int j;

	j = 1;
	if (!att->tok_arr[1])
	{
		export_sort(att);
		export_print(att);
		return ;
	}
	while (att->tok_arr[j])
	{
		if (check_equal(att->tok_arr[j]) == 1)
		{
			double_myenv(att);
			refresh_addenv(att, att->tok_arr[j]);
			export_sort(att);
		}
		/* if (already_exist(att, att->tok_arr[j]) == 1)
		{
			refresh_rmenv(att, find_index(att->g_env, att->tok_arr[j]));
			refresh_addenv(att, att->tok_arr[j]);
		} */
		j++;
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
