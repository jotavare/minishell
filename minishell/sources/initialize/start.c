/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 01:30:53 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:17:37 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	start_args(t_exec *args, t_attr *att)
{
	args->i = 0;
	args->command = att->tok_arr[0];
	args->path_srt = get_str_paths(att, args->path_srt);
	if (args->path_srt == NULL)
		return (-1);
	args->path_srt += 5;
	args->nb_of_paths = count_paths(args->path_srt);
	args->all_paths = ft_split(args->path_srt, ':');
	args->path_command = NULL;
	return (0);
}

void	start_env(char **envp, t_attr *att)
{
	int	i;

	i = 0;
	att->len_g_env = 0;
	while (envp[att->len_g_env])
		att->len_g_env++;
	att->g_env = malloc(sizeof(char *) * (att->len_g_env + 2));
	if (!att->g_env)
		return ;
	while (i < att->len_g_env)
	{
		att->g_env[i] = ft_strdup(envp[i]);
		i++;
	}
	att->g_env[i] = 0;
}

void	start_exp(char **envp, t_attr *att)
{
	int	j;

	j = 0;
	att->len_exp_env = 0;
	while (envp[att->len_exp_env])
		att->len_exp_env++;
	att->exp_env = malloc(sizeof(char *) * (att->len_g_env + 1));
	if (!att->exp_env)
		return ;
	while (j < att->len_exp_env)
	{
		att->exp_env[j] = ft_strdup(envp[j]);
		j++;
	}
	att->exp_env[j] = 0;
}
