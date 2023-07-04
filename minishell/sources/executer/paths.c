/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:25 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:18:18 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**build_path(char **all_paths, int nb, char *command)
{
	char	**paths_comm;
	int		i;

	paths_comm = malloc(sizeof(char *) * (nb + 1));
	i = 0;
	paths_comm[nb] = NULL;
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
