/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/27 17:05:24 by alexandre        ###   ########.fr       */
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
	//char	*to_find;
	int		i;

	i = 0;
	//to_find = add_equal(str);
	while (search[i])
	{
		if (!ft_strncmp(search[i], str, ft_strlen(str)))
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

/* Free da envp para fazer refresh dela 
na proxima funcao e realocar a memoria */
void	free_g_env(t_attr *att)
{
	int	i;

	i = 0;
	while (att->g_env[i])
	{
		free(att->g_env[i]);
		i++;
	}
	free(att->g_env);
}

void	free_d_env(t_attr *att)
{
	int	i;

	i = 0;
	while (att->d_env[i])
	{
		free(att->d_env[i]);
		i++;
	}
	free(att->d_env);
}

void	free_exp_env(t_attr *att)
{
	int i;
	
	i = 0;
	while(att->exp_env[i])
	{
		free(att->exp_env[i]);
		i++;
	}
	free(att->exp_env);
}

void	free_d_exp_env(t_attr *att)
{
	int i;
	
	i = 0;
	while(att->d_exp_env[i])
	{
		free(att->d_exp_env[i]);
		i++;
	}
	free(att->d_exp_env);
}

void	double_myenv(t_attr *att)
{
	int	i;

	i = 0;
	att->d_env = malloc(sizeof(char *) * (att->len_g_env ));
	att->len_d_env = att->len_g_env;
	if (!att->d_env)
		return ;
	while (i < att->len_g_env)
	{
		att->d_env[i] = ft_strdup(att->g_env[i]);
		i++;
	}
	att->d_env[i] = 0;//27 maio
}

void	double_exp_env(t_attr *att)
{
	int i;//27 maio

	i = 0;//27 maio
	att->d_exp_env = malloc(sizeof(char *) * (att->len_exp_env));//27 maio
	att->len_d_exp_env = att->len_exp_env;//27 maio
	if (!att->d_exp_env)//27 maio
		return ;//27 maio
	while (i < att->len_d_exp_env)//27 maio
	{//27 maio
		att->d_exp_env[i] = ft_strdup(att->exp_env[i]);//27 maio
		i++;//27 maio
	}//27 maio
	att->d_exp_env[i] = 0;//27 maio
}

void	refresh_rmenv(t_attr *att, int rm_index)
{
	int	i;//27 maio
	int	j;//27 maio

	i = 0;//27 maio
	j = 0;//27 maio

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
	int i;
	int j;

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

/* Remove variable from g_env and from d_env */

void	unset(t_attr *att)
{
	int	j;

	j = 1;
	if (!att->tok_arr[1])
		return ;
	while (att->tok_arr[j])
	{
		if (!check_alpha(att->tok_arr[j]))
			printf("bash: unset: '%s': not a valid identifier\n", att->tok_arr[j]);
		if ((find_index(att->g_env, att->tok_arr[j])))
			refresh_rmenv(att, check_the_arr(att->g_env, att->tok_arr[j]));
		if ((find_index(att->exp_env, att->tok_arr[j])))
			refresh_rmexp_env(att, check_the_arr(att->exp_env, att->tok_arr[j]));
		j++;
	}
}