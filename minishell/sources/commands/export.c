/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/31 03:03:21 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_equal(char *str)
{
	int	i;

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
	int	i;

	i = 0;
	double_myenv(att);
	free_g_env(att);
	att->g_env = malloc(sizeof(char *) * (att->len_g_env + 3));
	if (!att->g_env)
		return ;
	while (i < att->len_g_env)
	{
		att->g_env[i] = ft_strdup(att->d_env[i]);
		i++;
	}
	att->g_env[att->len_g_env] = ft_strdup(add);
	att->len_g_env++;
	att->g_env[att->len_g_env] = 0;
	free_d_env(att);
}

void	refresh_add_exp(t_attr *att, char *add)
{
	int	i;

	i = 0;
	double_exp_env(att);
	free_exp_env(att);
	att->exp_env = malloc(sizeof(char *) * (att->len_exp_env + 3));
	if (!att->exp_env)
		return ;
	while (i < att->len_exp_env)
	{
		att->exp_env[i] = ft_strdup(att->d_exp_env[i]);
		i++;
	}
	att->exp_env[att->len_exp_env] = ft_strdup(add);
	att->len_exp_env++;
	att->exp_env[att->len_exp_env] = 0;
	// temp = malloc(sizeof(char *) * (att->len_exp_env));
	// temp = att->exp_env;
	// temp[att->len_exp_env] = 0;
	free_d_exp_env(att);
}

/*
    main function of the export command
*/

int	check_the_arr(char **search, char *str)
{
	int		i;
	char	*to_find;
	int		j;

	j = 0;
	i = 0;
	if (check_equal(str))
	{
		while (str[j] != '=')
			j++;
		to_find = str;
		while (search[i])
		{
			if (!ft_strncmp(search[i], to_find, j))
			{
				return (i);
			}
			i++;
		}
	}
	else
	{
		while (str[j])
			j++;
		j++;
		to_find = add_equal(str);
		while (search[i])
		{
			if (!ft_strncmp(search[i], to_find, j))
			{
				free(to_find);
				return (i);
			}
			i++;
		}
		free(to_find);
	}
	return (0);
}

void	export(t_attr *att)
{
	int	j;

	j = 1;
	if (!att->tok_arr[1])
	{
		export_sort(*att);
		export_print(*att);
		return ;
	}
	while (att->tok_arr[j])
	{
		if (!check_alpha(att->tok_arr[j]))
		{
			printf("bash: export: '%s': not a valid identifier\n",
					att->tok_arr[j]); //check
			j++;
		}
		else if (check_equal(att->tok_arr[j]))
		{
			if (check_the_arr(att->g_env, att->tok_arr[j]))
				refresh_rmenv(att, check_the_arr(att->g_env, att->tok_arr[j]));
			if (check_the_arr(att->exp_env, att->tok_arr[j]))
				refresh_rmexp_env(att, check_the_arr(att->exp_env,
							att->tok_arr[j]));
			refresh_addenv(att, att->tok_arr[j]);
			refresh_add_exp(att, att->tok_arr[j]);
			j++;
		}
		else if (!check_equal(att->tok_arr[j]))
		{
			if (check_the_arr(att->exp_env, att->tok_arr[j]))
				refresh_rmexp_env(att, check_the_arr(att->exp_env,
							att->tok_arr[j]));
			refresh_add_exp(att, att->tok_arr[j]);
			j++;
		}
	}
}

/*
    sorts the environment variables alphabetically
    using the bubble sort algorithm
*/

void	export_sort(t_attr att)
{
	int		sorted;
	int		i;
	char	*temp;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (att.exp_env[i + 1] != NULL)
		{
			if (ft_strcmp(att.exp_env[i], att.exp_env[i + 1]) > 0)
			{
				temp = att.exp_env[i];
				att.exp_env[i] = att.exp_env[i + 1];
				att.exp_env[i + 1] = temp;
				sorted = 0;
			}
			i++;
		}
	}
}

/*
    prints the environment in the format required by the subject of the project
*/

void	add_quotes(char *s)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 1;
	while (s[i])
	{
		if (s[i] == '=' && flag)
		{
			flag = 0;
			ft_putchar_fd(s[i], 1);
			ft_putchar_fd('"', 1);
		}
		else
			ft_putchar_fd(s[i], 1);
		i++;
		j++;
	}
	ft_putchar_fd('"', 1);
}

void	export_print(t_attr att)
{
	int i;

	i = 0;
	while (att.exp_env[i])
	{
		ft_putstr_fd("declare -x ", 1);
		if (check_equal(att.exp_env[i]))
		{
			add_quotes(att.exp_env[i]);
			i++;
		}
		else
		{
			ft_putstr_fd(att.exp_env[i], 1);
			i++;
		}
		ft_putchar_fd('\n', 1);
	}
	printf("SIZE: %d\n", att.len_exp_env);
}