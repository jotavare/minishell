/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/21 13:14:37 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env(char **envp, t_attr *att)
{
	int	i;

	i = 0;
	while (envp[att->len_myenv])
		att->len_myenv++;
	att->g_env = malloc(sizeof(char *) * att->len_myenv + 1);
	if (!att->g_env)
		return ;
	while (i < att->len_myenv)
	{
		att->g_env[i] = ft_strdup(envp[i]);
		printf("%s\n", att->g_env[i]);
		i++;
	}
	printf("SIZE: %d\n", att->len_myenv);
}


