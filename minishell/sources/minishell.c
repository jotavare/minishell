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
	int i;
	int k = 0;

	rl_clear_history();
	set_signals();
	init_params(ac, av, &attr, envp);
	while (1)
	{
		i = 0;
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
			attr.commands_arr = get_tokens2(str, &attr);
			init_pipes(&attr);
			k = 0;
			while (attr.commands_arr[i])
			{
				if (is_symbol(attr.commands_arr[i]))
					i++;
				check_next_step(&attr, &i);
				attr.tok_arr = get_tokens(attr.commands_arr[i], &attr);
				command(&attr, k);
				free_tokens(attr.tok_arr, &attr);
				free(attr.tok_arr);
				i++;
				k++;
			}
			while (waitpid(-1, NULL, 0) > 0)
				continue;
			attr.number_of_pipes = 0;
			ft_delete_matrix(attr.pipesfd);
			free_arr(attr.commands_arr);
			free(str);
		}
	}
	free_g_env(&attr);
	free_exp_env(&attr);
	return (0);
}