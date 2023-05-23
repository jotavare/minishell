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
	init_attributes(&attr);
	start_env(envp, &attr);
	while (1)
	{
		double_myenv(&attr);
		str = readline("\033[0;31mminihell$\033[0m ");
		if (str == NULL)
		{
			rl_clear_history();
			break ;
		}
		init_attributes(&attr);
		if (str)
		{	
			add_history(str);
			attr.tok_arr = get_tokens(str, &attr);
		
			command(&attr);

			free_tokens(attr.tok_arr, attr);
			free(attr.tok_arr);
			free(str);
		}
	}
	return (0);
}