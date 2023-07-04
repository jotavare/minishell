/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:19:20 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*add_equal(char *str)
{
	char	*p_equal;
	int		i;

	i = 0;
	p_equal = malloc(sizeof(char) * ft_strlen(str) + 2);
	while (str[i])
	{
		p_equal[i] = str[i];
		i++;
	}
	p_equal[i++] = '=';
	p_equal[i] = '\0';
	return (p_equal);
}

int	find_index(char **search, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j] && str[j] != '=')
		j++;
	if (str[j] == '=')
		j++;
	while (search[i])
	{
		if (!ft_strncmp(search[i], str, j))
		{
			return (i);
		}
		i++;
	}
	return (0);
}

void	double_myenv(t_attr *att)
{
	int	i;

	i = 0;
	att->d_env = malloc(sizeof(char *) * (att->len_g_env + 1));
	att->len_d_env = att->len_g_env;
	if (!att->d_env)
		return ;
	while (i < att->len_g_env)
	{
		att->d_env[i] = ft_strdup(att->g_env[i]);
		i++;
	}
	att->d_env[i] = 0;
}

void	double_exp_env(t_attr *att)
{
	int	i;

	i = 0;
	att->d_exp_env = malloc(sizeof(char *) * (att->len_exp_env + 1));
	att->len_d_exp_env = att->len_exp_env;
	if (!att->d_exp_env)
		return ;
	while (i < att->len_d_exp_env)
	{
		att->d_exp_env[i] = ft_strdup(att->exp_env[i]);
		i++;
	}
	att->d_exp_env[i] = 0;
}

int	unset(t_attr *att)
{
	int	j;

	j = 1;
	if (!att->tok_arr[1])
		return (0);
	while (att->tok_arr[j])
	{
		if (!check_alpha(att->tok_arr[j]))
		{
			printf("TOKEN: %s \n", att->tok_arr[j]);
			printf("bash: unset: '%s': not a valid identifier\n",
				att->tok_arr[j]);
			return (1);
		}
		if ((find_index(att->g_env, att->tok_arr[j])))
			refresh_rmenv(att, check_the_arr(att->g_env, att->tok_arr[j]));
		if ((find_index(att->exp_env, att->tok_arr[j])))
			refresh_rmexp_env(att, find_index(att->exp_env, att->tok_arr[j]));
		j++;
	}
	return (0);
}
