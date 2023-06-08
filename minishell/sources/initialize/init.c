/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/18 150:00 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_params(int ac, char **av, t_attr *attr, char **envp)
{
	(void)ac;
	(void)av;
	init_attributes(attr);
	start_env(envp, attr);
	start_exp(envp, attr);
	init_paths(attr);
}

void	init_attributes(t_attr *att)
{
	att->nb_tokenst = 0;
	att->index = 0;
	att->tok_arr = NULL;
	att->d_env = NULL;
	att->len_d_env = 0;
	att->d_exp_env = NULL;
	att->len_d_exp_env = 0;
	att->commands_arr = NULL;
	att->tok_arr_i = 0;
}

void	init_paths(t_attr *att)
{
	att->last_path = search_var_in_g_env(att, "HOME");
}

int	count_commands(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (s[i])
	{
		if (s[i] == '|')
			count++;
		i++;
	}
	return (count);
}

void	reinit_attributes(t_attr *att)
{
	att->nb_tokenst = 0;
	att->index = 0;
	att->tok_arr = NULL;
	att->tok_arr_i = 0;
	att->last_path = search_var_in_g_env(att, "OLDPWD");
}
