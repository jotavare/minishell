/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:25 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/23 22:02:01:26 by jotavare         ###   ########.fr       */
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
				return (-1);
			}
		}
		args->i++;
	}
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

void	execute_core(t_attr *att, t_exec *args)
{
	if (args->command[0] == '/')
		exec_absolute_path(args, att);
	else if (args->command[0] == '.')
		exec_binaries(args, att);
	else
		exec_commands(args, att);
	printf("%s: command not found \n", att->tok_arr[0]);
	exit(WEXITSTATUS(g_value));
}

int	execute(t_attr *att, int index)
{
	t_exec	args;
	int		exit_status;

	start_args(&args, att);
	args.pid = fork();
	if (args.pid == -1)
		return (-1);
	if (args.pid == 0)
	{
		if (att->skip)
			exit(g_value);
		if (att->read_from_pipe)
			read_from_pipe(att);
		else if (att->read_from_file)
		{
			if (read_from_file(att, index) < 0)
				exit(g_value);
		}
		if (att->heredoc)
			heredoc(att->commands_arr[att->i + 2], att);
		if (att->write_to_pipe && att->read_from_pipe)
			att->pipeindex++;
		if (att->write_to_pipe)
			write_to_pipe(att);
		if (att->redir)
			redir_append(att, index);
		if (!ft_strcmp(att->tok_arr[0], "pwd"))
			pwd();
		else if (!ft_strcmp(att->tok_arr[0], "echo"))
			g_value = echo(*att);
		else if (!ft_strcmp(att->tok_arr[0], "env"))
			g_value = env(att);
		else if (ft_strcmp(att->tok_arr[0], "export") == 0)
			export_print(*att);
		else
			execute_core(att, &args);
		free_start_args(&args);
		printf("Return value [CHILD]: %d\n", g_value);
		exit(g_value);
	}
	else
		waitpid(args.pid, &g_value, 0);
	if (att->read_from_pipe)
		att->pipeindex++;
	close_pipeline(att);
	//see_flags_and_pipes(*att);
	free_start_args(&args);
	exit_status = WEXITSTATUS(g_value);
	printf("Return value [PARENT]: %d\n", exit_status);
	return (exit_status);
}
