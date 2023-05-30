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

char *prompt(t_attr *att)
{
	char *str;
	char *user = custom_getenv("USER", att);
	char *pwd = custom_getenv("PWD", att);
	if (pwd != NULL && user != NULL)
	{
		printf("┏━"GREEN_BOLD" %s@:" GREEN_BOLD, user);
		printf(CYAN_BOLD "%s\n" CYAN_BOLD, pwd);
	}
	str = readline(RESET"┗━"RED_BOLD" minihell$"RED_BOLD" "RESET"");
	return (str);
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
		str = prompt(&attr);
		if (str == NULL)
		{
			rl_clear_history();
			break ;
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