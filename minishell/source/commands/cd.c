/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/31 03:02:55 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
    change directory to path given an argument
*/
extern int	g_last_return_value;

char	*search_var_in_g_env(t_attr *att, char *s)
{
	int		i;
	int		s_size;
	char	*path;

	i = 0;
	s_size = (int)ft_strlen(s);
	while (ft_strncmp(att->g_env[i], s, s_size))
		i++;
	path = att->g_env[i];
	path += s_size + 1;
	return (path);
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
	char	*current_path;
	char	*destiny_path;
	char	*str_pwd;

	if (att->nb_tokens > 2)
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 1);
		g_last_return_value = 1;
		return ;
	}
	destiny_path = att->tok_arr[1];
	if (!destiny_path || !ft_strcmp(destiny_path, "~"))
		destiny_path = search_var_in_g_env(att, "HOME");
	else if (!ft_strcmp(att->tok_arr[1], "-"))
		destiny_path = att->last_path;
	current_path = getcwd(NULL, 0);
	if (!current_path)
		return ;
	if (chdir(destiny_path))
	{
		printf("minishell: cd: %s: No such file or directory\n",
				att->tok_arr[1]);
		g_last_return_value = 1;
	}
	str_pwd = ft_strjoin("OLDPWD=", current_path);
	cd_rm_add_path(att, "OLDPWD", str_pwd);
	free(str_pwd);
	att->last_path = search_var_in_g_env(att, "OLDPWD");
	free(current_path);
	current_path = getcwd(NULL, 0);
	str_pwd = ft_strjoin("PWD=", current_path);
	cd_rm_add_path(att, "PWD", str_pwd);
	free(str_pwd);
	free(current_path);
}

/* void	cd(t_attr *att)
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
 */