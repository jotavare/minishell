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

char	**build_path(char **paths, int nb, char *command)
{
	char	**paths_comm = malloc(sizeof(char *) * nb + 1);
	int		i = 0;

	paths_comm[nb - 1] = NULL;
	while (i < nb)
	{
			paths_comm[i] = ft_strjoin(paths[i], command);
			i++;
	}
	return (paths_comm);
}

int	count_paths(char *s)
{
	int count;

	count = 0;
	while(*s)
	{
		if (*s == ':')
			count++;
		s++;
	}
	return(count);
}

int  execute(t_attr *att)
{
    char    *path_str;
    char    **all_paths;
    char    **path_command;
    char    *command;
    char    curr_path[PATH_MAX];
    int     ret;
    pid_t   pid;
    int     i;
    int     nb_of_paths;


    i = 0;
    nb_of_paths = 0;
	path_str = 0;
    command = att->tok_arr[0];
    if (getcwd(curr_path, PATH_MAX) == NULL)
        exit(EXIT_FAILURE);
    while (att->g_env[i])
    {
        if(!ft_strncmp(att->g_env[i], "PATH", 4))
        {
            path_str = att->g_env[i];
            break;
        }
        i++;
    }
    path_str += 5;
    nb_of_paths = count_paths(path_str);
    all_paths = ft_split(path_str, ':');
    path_command = build_path(all_paths, nb_of_paths, ft_strjoin("/",att->tok_arr[0]));
    pid = fork ();
    if (pid == -1)
        return (0);
    if (pid == 0)
    {
        if (command[0] == '/')
        {
            if (!access(att->tok_arr[0], X_OK))
                {
                        ret = execve(att->tok_arr[0], att->tok_arr, att->g_env);
                        if (ret != 0)   
                            perror("execve");
                }
        }
        else
		
		
		 if (command[0] == '.')
        {
            command++;
            if (!access(ft_strjoin(curr_path, command), X_OK))
            {
                    ret = execve(ft_strjoin(curr_path, command), att->tok_arr, att->g_env);
                    if (ret != 0)   
                        perror("execve");
            }
        }
        else
        {
            i = 0;
            while (i < nb_of_paths)
            {
                if (!access(path_command[i], X_OK))
                {
                        ret = execve(path_command[i], att->tok_arr, att->g_env);
                        if (ret != 0)   
                            perror("execve");
                }
                i++;
            }
        }
        printf("Minishell: command not found: %s\n", att->tok_arr[0]);
    }
    else
        wait(NULL);
    return (0);
}
