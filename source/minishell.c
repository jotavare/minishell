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

#include "../minishell.h"

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	t_attr attr;
	char *str;

	rl_clear_history();
	set_signals();
	init_paths(&attr);
	start_env(envp, &attr);
	while (1)
	{
		double_myenv(&attr);
		// Read the command from the user
		str = readline("\033[0;31mminihell$\033[0m ");
		if (str == NULL)
		{
			rl_clear_history();
			break ;
		}
		// Initialize the atributs struct
/* 		int i = 0;
		while (attr.g_env[i])
			printf("testes(alexfern):my_env = %s\n", attr.g_env[i++]); */
		init_attributes(&attr);
		// Add the command to the history
		add_history(str);
		attr.tok_arr = get_tokens(str, &attr);
		//testar coisas para o unset (alexfern)
		/* 		char *alex3 = "SSH_AUTH_SOCK";
		int index = find_index(&attr, alex3);
		int i = 0;
		refresh_env(&attr, index, envp);
		int j = 0;
		while (attr.g_env[j])
			printf("testes(alexfern):refresh_env = %s\n", attr.g_env[j++]); */
		//testar coisas para o unset (alexfern)
		command(str, &attr, envp);
		//unset(&attr, envp);

		// Check if the command is "exit"
		if (strcmp(str, "exit") == 0)
			break ;

		//free all alocated memory
		free_tokens(attr.tok_arr, attr);
		free(attr.tok_arr);
		free(str);
	}
	free_tokens(attr.g_env, attr);
	free(attr.g_env);
	return (0);
}