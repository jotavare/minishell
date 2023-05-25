/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/22 00:16:01 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
    change directory to path given an argument
*/

void	cd(t_attr *attr)
{
	char	*current_path;
	char	*destiny_path;

	if (attr->nb_tokens > 2)
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 1);
		return ;
	}
	destiny_path = attr->tok_arr[1];
	if (!destiny_path || !ft_strcmp(destiny_path, "~"))
		destiny_path = getenv("HOME");
	else if (!ft_strcmp(attr->tok_arr[1], "-"))
		destiny_path = attr->last_path;
	current_path = getcwd(NULL, 0);
	if (!current_path)
		return ;
	attr->last_path = ft_strdup(current_path);
	printf("current path: %s\n", current_path);
	if (chdir(destiny_path))
		printf("minishell: cd: %s: No such file or directory\n",
			attr->tok_arr[1]);
	else
		printf("Directory changed to: %s\n", getcwd(NULL, 0));
	free(current_path);
}
