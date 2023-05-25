/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/24 20:33:20 by lde-sous         ###   ########.fr       */
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

void	refresh_addenv(t_attr *att, char *add)
{
	int i = 0;

	double_myenv(att);
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
	att->g_env[att->len_myenv] = 0;
}

/*
    main function of the export command
*/

int	check_the_arr(t_attr *att, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[j] != '=')
		j++;
	j--;
	while (att->g_env[i])
	{
		if (!ft_strncmp(att->g_env[i], str, j))
			return (1);
		i++;
	}
	return (0);
}

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
		double_myenv(att);
		if (!check_alpha(att->tok_arr[j]))
			printf("bash: export: '%s': not a valid identifier\n", att->tok_arr[j]);
		else if (check_equal(att->tok_arr[j]) && check_the_arr(att, att->tok_arr[j]))
		{
			refresh_rmenv(att, find_index(att->g_env, att->tok_arr[j]));
			refresh_addenv(att, att->tok_arr[j]);
		}
		else if (check_equal(att->tok_arr[j]))
		{
			refresh_addenv(att, att->tok_arr[j]);
			export_sort(att);
		}
		free_d_env(att);
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
