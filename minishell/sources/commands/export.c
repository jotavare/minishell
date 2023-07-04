/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:31:00 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	export(t_attr *att)
{
	int	j;

	j = 1;
	if (!att->tok_arr[1])
	{
		export_sort(*att);
		export_print(*att);
		return (0);
	}
	while (att->tok_arr[j])
	{
		if (!check_alpha(att->tok_arr[j]))
			printf(ERROR_EXPORT, att->tok_arr[j]);
		else if (check_equal(att->tok_arr[j]))
			export_check_equal(att, j);
		else if (!check_equal(att->tok_arr[j]))
			export_not_equal(att, j);
		j++;
	}
	return (0);
}

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

int	export_print(t_attr att)
{
	int	i;

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
	return (0);
}

void	export_check_equal(t_attr *att, int j)
{
	if (check_the_arr(att->g_env, att->tok_arr[j]) >= 0)
		refresh_rmenv(att, check_the_arr(att->g_env, att->tok_arr[j]));
	if (check_the_arr(att->exp_env, att->tok_arr[j]) >= 0)
		refresh_rmexp_env(att, check_the_arr(att->exp_env, att->tok_arr[j]));
	refresh_addenv(att, att->tok_arr[j]);
	refresh_add_exp(att, att->tok_arr[j]);
}

void	export_not_equal(t_attr *att, int j)
{
	if (check_the_arr(att->exp_env, att->tok_arr[j]) >= 0)
		return ;
	refresh_add_exp(att, att->tok_arr[j]);
}
