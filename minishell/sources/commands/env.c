/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/31 21:21:31 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	env(t_attr *att)
{
	int	i;

	i = 1;
	while (att->tok_arr[i])
	{
		if (!check_equal(att->tok_arr[i]))
		{
			printf("env: ‘%s’: No such file or directory\n", att->tok_arr[i]);
			return ;
		}
		i++;
	}
	i = 0;
	while (i < att->len_g_env)
	{
		printf("%s\n", att->g_env[i]);
		i++;
	}
	i = 1;
	while (att->tok_arr[i])
	{
		if (check_equal(att->tok_arr[i]))
			printf("%s\n", att->tok_arr[i]);
		i++;
	}
	printf("SIZE: %d\n", att->len_g_env);
}
