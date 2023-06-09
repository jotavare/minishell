/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:25 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/09 19:48:54 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

# define READ_END 0 
# define WRITE_END 1

char	**build_path(char **all_paths, int nb, char *command)
{
	char	**paths_comm;
	int		i;

	paths_comm = malloc(sizeof(char *) * nb + 1);
	i = 0;
	paths_comm[nb - 1] = NULL;
	while (i < nb)
	{
		paths_comm[i] = ft_strjoin(all_paths[i], command);
		i++;
	}
	free(command);
	return (paths_comm);
}

int	count_paths(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == ':')
			count++;
		s++;
	}
	return (count);
}

char	*get_str_paths(t_attr *att, char *path_str)
{
	int	i;

	i = 0;
	while (att->g_env[i])
	{
		if (!ft_strncmp(att->g_env[i], "PATH", 4))
		{
			path_str = att->g_env[i];
			return (path_str);
		}
		i++;
	}
	return (NULL);
}

int	exec_commands(t_exec *args, t_attr *att)
{
	args->i = 0;
	args->path_command = build_path(args->all_paths, args->nb_of_paths,
			ft_strjoin("/", att->tok_arr[0]));
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

void    pipe_out(int fd[2])
{
    dup2(fd[1], 1);
    close(fd[0]);
    close(fd[1]);
}

void    pipe_in(int fd[2])
{
    dup2(fd[0], 0);
    close(fd[0]);
    close(fd[1]);
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
		exit(0);
} 

int		execute(t_attr *att)
{
	t_exec	args;
	//int		pipefd[2];

	start_args(&args, att);
	args.pid = fork();
	if (args.pid == -1)
		return (-1);
	if (args.pid == 0)
	{
		execute_core(att, &args);
	}
	else
		wait(NULL);
	free_arr(args.all_paths);
	//free(args.all_paths);
	return (0);
}

// n - 1
int		execute_write_p(t_attr *att)
{
	t_exec	args;

	start_args(&args, att);
	args.pid = fork();
	if (args.pid == -1)
		return (-1);
	if (args.pid == 0)
	{
		pipe_out(att->pipefd);		
		execute_core(att, &args);
	}
	else
		wait(NULL);
	free_arr(args.all_paths);
	// close(att->pipefd[0]);
	close(att->pipefd[WRITE_END]);
	att->write_to_pipe = 0;
	return (0);
}

int		execute_read_p(t_attr *att)
{
	t_exec	args;

	start_args(&args, att);
	args.pid = fork();
	if (args.pid == -1)
		return (-1);
	if (args.pid == 0)
	{
		pipe_in(att->pipefd);
		execute_core(att, &args);
	}
	else
		wait(NULL);
	free_arr(args.all_paths);
	// close(att->pipefd[READ_END]);
	// close(att->pipefd[1]);
	att->read_from_pipe = 0;
	return (0);
}


/* int	execute(t_attr *att)
{
	t_exec	args;

	start_args(&args, att);
	int	flag = 0;
	args.pid = fork();
	if (args.pid == -1)
		return (-1);
	if (args.pid == 0)
	{
		if (args.command[0] == '/')
			exec_absolute_path(&args, att);
		else if (args.command[0] == '.')
			exec_binaries(&args, att);
        else if (!ft_strcmp(args.command, "minishell"))
        {
            printf("Minishell: command not found: %s\n", att->tok_arr[0]);
			flag = 1;
        }
		else
			exec_commands(&args, att);
		if (flag == 0)
			printf("Minishell: command not found: %s\n", att->tok_arr[0]);
	}
	else
		wait(NULL);
	return (0);
} */
