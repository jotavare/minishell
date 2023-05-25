/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/24 13:07:58 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* Adiciona um "=" no fim da nossa string para poder
encontrar a variavel precisa na envp */
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
	Encontra a posicao da string que queremos tirar do nosso array envp 
*/

int	find_index(char **search, char *str)
{
	char	*to_find;
	int		i;

	i = 0;
	to_find = add_equal(str);
	while (search[i])
	{
		if (!ft_strncmp(search[i], to_find, ft_strlen(to_find)))
		{
			free(to_find);
			return (i);
		}
		i++;
	}
	free(to_find);
	return (0);
}

/* Free da envp para fazer refresh dela 
na proxima funcao e realocar a memoria */
void	free_g_env(t_attr *att)
{
	int	i;

	i = 0;
	while (att->g_env[i])
	{
		//free(att->g_env[i]);
		att->g_env[i] = NULL;
		i++;
	}
	free(att->g_env);
}

void	double_myenv(t_attr *att)
{
	int	i;

	i = 0;
	att->d_env = malloc(sizeof(char *) * (att->len_myenv + 1));
	att->len_d_env = att->len_myenv;
	if (!att->d_env)
		return ;
	while (i < att->len_d_env)
	{
		att->d_env[i] = ft_strdup(att->g_env[i]);
		i++;
	}
	att->d_env[i] = 0;
}

void	free_d_env(t_attr *att)
{
	int	i;

	i = 0;
	while (att->d_env[i])
	{
		//free(att->d_env[i]);
		att->d_env[i] = NULL;
		i++;
	}
	free(att->d_env);
}

void	refresh_rmenv(t_attr *att, int rm_index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	double_myenv(att);
	free_g_env(att);
	att->g_env = malloc(sizeof(char *) * att->len_myenv);
	if (!att->g_env)
		return ;
	while (j < att->len_myenv)
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
	att->len_myenv--;
}

void	unset(t_attr *att)
{
	int	j;

	j = 1;
	if (!att->g_env[1])
		return ;
	while (att->tok_arr[j])
	{
		double_myenv(att);
		if ((find_index(att->g_env, att->tok_arr[j])))
		{
			refresh_rmenv(att, find_index(att->g_env, att->tok_arr[j]));
			free_d_env(att);
		}
		j++;
	}
}
