/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 00:50:35 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:28:53 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec_commands(t_exec *args, t_attr *att)
{
	char	*s;

	args->i = 0;
	s = ft_strjoin("/", att->tok_arr[0]);
	args->path_command = build_path(args->all_paths, args->nb_of_paths, s);
	while (args->i < args->nb_of_paths)
	{
		if (!access(args->path_command[args->i], X_OK))
		{
			args->ret = execve(args->path_command[args->i], att->tok_arr,
					att->g_env);
			if (args->ret != 0)
			{
				perror("execve");
				free_arr(args->path_command);
				return (-1);
			}
		}
		args->i++;
	}
	free_arr(args->path_command);
	return (0);
}

int	exec_binaries(t_exec *args, t_attr *att)
{
	char	*filepath;

	getcwd(args->curr_path, PATH_MAX);
	args->command++;
	filepath = ft_strjoin(args->curr_path, args->command);
	if (!access(filepath, X_OK))
	{
		args->ret = execve(filepath, att->tok_arr, att->g_env);
		if (args->ret != 0)
		{
			perror("execve");
			free(filepath);
			return (-1);
		}
	}
	free(filepath);
	return (0);
}

int	exec_absolute_path(t_exec *args, t_attr *att)
{
	if (!access(att->tok_arr[0], X_OK))
	{
		args->ret = execve(att->tok_arr[0], att->tok_arr, att->g_env);
		if (args->ret != 0)
		{
			perror("execve");
			return (-1);
		}
	}
	return (0);
}
