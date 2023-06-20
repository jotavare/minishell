/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/06/20 05:42:36 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_last_return_value;

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

void	cd(t_attr *att)
{
	char	*destiny_path;
	char	*current_path;

	destiny_path = att->tok_arr[1];
	current_path = getcwd(NULL, 0);
	if (att->nb_tokens > 2)
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 1);
		g_last_return_value = 1;
		return ;
	}
	if (!destiny_path || !ft_strcmp(destiny_path, "~"))
		destiny_path = search_var_in_g_env(att, "HOME");
	else if (!ft_strcmp(att->tok_arr[1], "-"))
		destiny_path = att->last_path;
	if (!current_path)
		return ;
	if (chdir(destiny_path))
	{
		printf(ERROR_CD, att->tok_arr[1]);
		g_last_return_value = 1;
	}
	update_oldpwd(att, current_path);
	update_pwd(att);
	free(current_path);
}

void	update_oldpwd(t_attr *att, const char *current_path)
{
	char	*str_pwd;

	str_pwd = ft_strjoin("OLDPWD=", current_path);
	cd_rm_add_path(att, "OLDPWD", str_pwd);
	free(str_pwd);
	att->last_path = search_var_in_g_env(att, "OLDPWD");
}

void	update_pwd(t_attr *att)
{
	char	*current_path;
	char	*str_pwd;

	current_path = getcwd(NULL, 0);
	str_pwd = ft_strjoin("PWD=", current_path);
	cd_rm_add_path(att, "PWD", str_pwd);
	free(str_pwd);
	free(current_path);
}
