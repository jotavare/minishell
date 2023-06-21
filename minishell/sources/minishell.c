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
	t_attr	att;
	char	*str;

	rl_clear_history();
	set_signals();
	init_params(ac, av, &att, envp);
	while (1)
	{
		att.i = 0;
		str = prompt(&att);
		if (str == NULL)
		{
			rl_clear_history();
			break ;
		}
		reinit_attributes(&att);
		if (str)
		{
			add_history(str);
			att.commands_arr = get_tokens2(str, &att);
			init_pipes(&att);
			while (att.commands_arr[att.i]
				&& !verify_readline(str) && att.commands_arr[att.i][0] != '\0')
			{
				if (is_symbol(att.commands_arr[att.i]))
					att.i++;
				check_next_step(&att);
				att.tok_arr = get_tokens(att.commands_arr[att.i], &att);
				command(&att, att.i);
				free_tokens(att.tok_arr, &att);
				free(att.tok_arr);
				att.i = att.i + 2;
			}
			while (waitpid(-1, NULL, 0) > 0)
				continue ;
			ft_delete_matrix(att.pipesfd);
			free_arr(att.commands_arr);
			free(str);
		}
	}
	free_g_env(&att);
	free_exp_env(&att);
	return (0);
}
