/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:25 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/24 20:32:46 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

int		exec_commands(t_exec *args, t_attr *att)
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
				return(-1);
			}
		}
		args->i++;
	}
	return (0);
}

int		exec_binaries(t_exec *args, t_attr *att)
{
	getcwd(args->curr_path, PATH_MAX);
	args->command++;
	if (!access(ft_strjoin(args->curr_path, args->command), X_OK))
	{
		args->ret = execve(ft_strjoin(args->curr_path, args->command),
				att->tok_arr, att->g_env);
		if (args->ret != 0)
		{
			perror("execve");
			return(-1);
		}
	}
	return(0);
}

int		exec_absolute_path(t_exec *args, t_attr *att)
{
	if (!access(att->tok_arr[0], X_OK))
			{
				args->ret = execve(att->tok_arr[0], att->tok_arr, att->g_env);
				if (args->ret != 0)
				{
					perror("execve");
					return(-1);
				}
			}
	return(0);
}

void	start_args(t_exec *args, t_attr *att)
{
	args->i = 0;
	args->command = att->tok_arr[0];
	args->path_srt = get_str_paths(att, args->path_srt);
	args->path_srt += 5;
	args->nb_of_paths = count_paths(args->path_srt);
	args->all_paths = ft_split(args->path_srt, ':');
}

int	execute(t_attr *att)
{
	t_exec	args;

	start_args(&args, att);

    if (!ft_strcmp(args.command, "minishell"))
    {
        printf("minishell: command not found: %s\n", att->tok_arr[0]);
        return (0);
    }

	args.pid = fork();
	if (args.pid == -1)
		return (-1);
	if (args.pid == 0)
	{
		if (args.command[0] == '/')
			exec_absolute_path(&args, att);
		else if (args.command[0] == '.')
			exec_binaries(&args, att);
		else
			exec_commands(&args, att);
		exit(0);
	}
	else
		wait(NULL);
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
