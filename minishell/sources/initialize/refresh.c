/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 01:30:23 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:17:46 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	free_d_exp_env(att);
}

void	refresh_rmexp_env(t_attr *att, int rm_index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	double_exp_env(att);
	free_exp_env(att);
	att->exp_env = malloc(sizeof(char *) * att->len_exp_env);
	if (!att->exp_env)
		return ;
	while (j < att->len_exp_env)
	{
		if (i == rm_index)
			i++;
		if (!att->d_exp_env[i])
			break ;
		att->exp_env[j] = ft_strdup(att->d_exp_env[i]);
		i++;
		j++;
	}
	att->exp_env[j] = 0;
	att->len_exp_env--;
	free_d_exp_env(att);
}

void	refresh_rmenv(t_attr *att, int rm_index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	double_myenv(att);
	free_g_env(att);
	att->g_env = malloc(sizeof(char *) * att->len_g_env);
	if (!att->g_env)
		return ;
	while (j < att->len_g_env)
	{
		if (i == rm_index)
			i++;
		if (!att->d_env[i])
			break ;
		att->g_env[j] = ft_strdup(att->d_env[i]);
		i++;
		j++;
	}
	att->g_env[j] = 0;
	att->len_g_env--;
	free_d_env(att);
}

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
