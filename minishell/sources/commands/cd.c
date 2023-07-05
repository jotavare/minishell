/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/04 22:50:38 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*search_var_in_g_env(t_attr *att, char *s)
{
	int		i;
	int		s_size;
	char	*path;

	i = 0;
	s_size = (int)ft_strlen(s);
	while (att->g_env[i] != NULL)
	{
		if (!ft_strncmp(att->g_env[i], s, s_size))
		{
			path = att->g_env[i];
			path += s_size + 1;
			return (path);
		}
		i++;
	}
	return (NULL);
}

void	cd_rm_add_path(t_attr *att, char *to_remove, char *s)
{
	if (find_index(att->g_env, to_remove))
		refresh_rmenv(att, check_the_arr(att->g_env, to_remove));
	refresh_addenv(att, s);
	if (find_index(att->exp_env, to_remove))
		refresh_rmexp_env(att, check_the_arr(att->exp_env, to_remove));
	refresh_add_exp(att, s);
}

int	print_free_return(char *curr_path)
{
	ft_putstr_fd("minishell: cd: too many arguments\n", 1);
	free(curr_path);
	return (1);
}

int	cd(t_attr *att)
{
	char	*destiny_path;
	char	*current_path;

	destiny_path = att->tok_arr[1];
	current_path = getcwd(NULL, 0);
	if (att->nb_tokens > 2)
		return (print_free_return(current_path));
	if (!destiny_path || !ft_strcmp(destiny_path, "~"))
		destiny_path = search_var_in_g_env(att, "HOME");
	else if (!ft_strcmp(att->tok_arr[1], "-"))
		cd_previous_path(att, &destiny_path);
	if (!current_path || chdir(destiny_path))
	{
		printf(ERROR_CD, att->tok_arr[1]);
		free(current_path);
		return (1);
	}
	update_oldpwd(att, current_path);
	update_pwd(att);
	free(current_path);
	att->is_builtin = 1;
	return (0);
}

void	cd_previous_path(t_attr *att, char **destiny_path)
{
	if (!att->first_flag)
	{
		*destiny_path = search_var_in_g_env(att, "PWD");
		att->first_flag = 1;
		printf("%s\n", *destiny_path);
	}
	else
	{
		*destiny_path = att->last_path;
		printf("%s\n", *destiny_path);
	}
}
