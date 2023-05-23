/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:25 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/23 18:08:24 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	execute(t_attr att, )
{
	char	*path_str;
	char	**all_paths;
	int		ret;
	pid_t	pid;
	int		i;

	i = 0;
	while (att->d_env[i])
	{
		if((ft_strncmp(att->d_env[i], "PATH", 4) == 0))
		{
			path_str = att->d_env[i];
			break;
		}
		i++;
	}
	all_paths = ft_split(path_str, ':');
	pid = fork ();
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		ret = execve(path_str, path, NULL);
		if (ret == -1)
			return (0);
	}
	else
		wait(NULL);
	return (0);
}
