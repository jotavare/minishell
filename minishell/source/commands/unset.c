/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/31 03:19:29 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	finds a "=" in the end of our string so we can
	find the exact variable in envp.
*/

char	*add_equal(char *str)
{
	char	*p_equal;
	int		i;

	i = 0;
	p_equal = malloc(sizeof(char) * ft_strlen(str) + 2);
	while (str[i])
	{
		p_equal[i] = str[i];
		i++;
	}
	p_equal[i++] = '=';
	p_equal[i] = '\0';
	return (p_equal);
}

/* 
	finds the string position we want toremove from
	our envp array.
*/

int	find_index(char **search, char *str)
{
	int	i;
	int	j;

	//char	*to_find;
	i = 0;
	j = 0;
	//to_find = add_equal(str);
	while (str[j] && str[j] != '=')
		j++;
	if (str[j] == '=')
		j++;
	while (search[i])
	{
		if (!ft_strncmp(search[i], str, j))
		{
			//free(to_find);
			return (i);
		}
		i++;
	}
	//free(to_find);
	return (0);
	//this function is called because we know 100% str exists, make it more safe
}

/* 
	free envp and reallocate it
*/

void	double_myenv(t_attr *att)
{
	int	i;

	i = 0;
	att->d_env = malloc(sizeof(char *) * (att->len_g_env + 1));
	att->len_d_env = att->len_g_env;
	if (!att->d_env)
		return ;
	while (i < att->len_g_env)
	{
		att->d_env[i] = ft_strdup(att->g_env[i]);
		i++;
	}
	att->d_env[i] = 0; //27 maio
}
	
void	double_exp_env(t_attr *att) //27 maio
{
	int i;

	i = 0;
	att->d_exp_env = malloc(sizeof(char *) * (att->len_exp_env + 1));
	att->len_d_exp_env = att->len_exp_env;
	if (!att->d_exp_env)
		return ;
	while (i < att->len_d_exp_env)
	{
		att->d_exp_env[i] = ft_strdup(att->exp_env[i]);
		i++;
	}
	att->d_exp_env[i] = 0;
}

void	refresh_rmenv(t_attr *att, int rm_index)
{
	int i; //27 maio
	int j; //27 maio
	i = 0; //27 maio
	j = 0; //27 maio
	double_myenv(att);
	free_g_env(att);
	att->g_env = malloc(sizeof(char *) * att->len_g_env);
	if (!att->g_env)
		return ;
	while (j < att->len_g_env)
	{
		if (i == rm_index)
			i++;
		if (!att->d_env[i])
			break ;
		att->g_env[j] = ft_strdup(att->d_env[i]);
		i++;
		j++;
	}
	att->g_env[j] = 0;
	att->len_g_env--;
	free_d_env(att);
}

void	refresh_rmexp_env(t_attr *att, int rm_index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	double_exp_env(att);
	free_exp_env(att);
	att->exp_env = malloc(sizeof(char *) * att->len_exp_env);
	if (!att->exp_env)
		return ;
	while (j < att->len_exp_env)
	{
		if (i == rm_index)
			i++;
		if (!att->d_exp_env[i])
			break ;
		att->exp_env[j] = ft_strdup(att->d_exp_env[i]);
		i++;
		j++;
	}
	att->exp_env[j] = 0;
	att->len_exp_env--;
	free_d_exp_env(att);
}

/* 
	removes the variable from g_env and from d_env
*/

void	unset(t_attr *att)
{
	int j;

	j = 1;
	if (!att->tok_arr[1])
		return ;
	while (att->tok_arr[j])
	{
		if (!check_alpha(att->tok_arr[j]))
			printf("bash: unset: '%s': not a valid identifier\n",
					att->tok_arr[j]);
		if ((find_index(att->g_env, att->tok_arr[j])))
			refresh_rmenv(att, check_the_arr(att->g_env, att->tok_arr[j]));
		if ((find_index(att->exp_env, att->tok_arr[j])))
			refresh_rmexp_env(att, find_index(att->exp_env, att->tok_arr[j]));
		j++;
	}
}