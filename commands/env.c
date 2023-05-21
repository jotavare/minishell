/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/21 20:13:23 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env(t_attr *att)
{
	int	i;

	i = 0;
	while (i < att->len_myenv)
	{
		printf("%s\n", att->g_env[i]);
		i++;
	}
	i = 1;
	while (att->tok_arr[i])
		printf("%s\n", att->tok_arr[i++]);
	printf("SIZE: %d\n", att->len_myenv);
}
