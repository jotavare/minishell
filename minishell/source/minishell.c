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

/*
void	final_free(t_attr *att)
{
	free(attr.last_path);
	free_g_env(&attr);
	free_exp_env(&attr);
}
*/
void	init_params(int ac, char **av, t_attr *attr, char **envp)
{
	(void)ac;
	(void)av;

	init_attributes(attr);
	start_env(envp, attr);
	start_exp(envp, attr);
	init_paths(attr);
}

int	main(int ac, char **av, char **envp)
{
	t_attr attr;
	char *str;

	rl_clear_history();
	set_signals();
	init_params(ac, av, &attr, envp);
	while (1)
	{
		str = readline("\033[0;31mminihell$\033[0m ");
		if (str == NULL)
		{
			rl_clear_history();
		//	break ;
		}
		reinit_attributes(&attr);
		if (str)
		{	
			add_history(str);
			attr.tok_arr = get_tokens(str, &attr);
		
			command(&attr);

			free_tokens(attr.tok_arr, &attr);
			free(attr.tok_arr);
			free(str);
		}
	}
	free(attr.last_path);
	free_g_env(&attr);
	free_exp_env(&attr);
	return (0);
}