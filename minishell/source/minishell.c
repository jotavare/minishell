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

#include "../includes/minishell.h"

int	g_last_return_value;

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
			
			//count_dirdoc(&attr);	//teste
			if (attr.nb_pipes < 1)
				command(&attr);
			else
				pipework(&attr); // testing
			free_tokens(attr.tok_arr, &attr);
			free(attr.tok_arr);
			free(str);
		}
	}
	free_g_env(&attr);
	free_exp_env(&attr);
	return (0);
}