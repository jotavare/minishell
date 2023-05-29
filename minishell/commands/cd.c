/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/29 18:02:16 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
 
/*
    change directory to path given an argument
*/

void	cd(t_attr *att)
{
	char	*current_path;
	char	*destiny_path;

	if (att->nb_tokens > 2)
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 1);
		att->last_return_value = 1;
		return ;
	}
	destiny_path = att->tok_arr[1];
	if (!destiny_path || !ft_strcmp(destiny_path, "~"))
		destiny_path = getenv("HOME");
	else if (!ft_strcmp(att->tok_arr[1], "-"))
		destiny_path = att->last_path;
	else if (ft_strnstr(destiny_path, "$", ft_strlen(destiny_path)))
		destiny_path = expand_variable(destiny_path, att->g_env);
	current_path = getcwd(NULL, 0);
	if (!current_path)
		return ;
	att->last_path = ft_strdup(current_path);
	if (chdir(destiny_path))
	{
		printf("minishell: cd: %s: No such file or directory\n",
				att->tok_arr[1]);
		att->last_return_value = 1;
	}
	free(current_path);
}
