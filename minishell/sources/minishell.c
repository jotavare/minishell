/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/06/29 14:36:30 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_value = 0;

int	check_and_clear_history_if_null(char *str)
{
	if (str == NULL)
	{
		rl_clear_history();
		return (1);
	}
	return (0);
}

void	free_resources(char *str, t_attr att)
{
	ft_delete_matrix(att.pipesfd);
	free_arr(att.commands_arr);
	free(str);
}

void	process_commands_loop(char *str, t_attr att, t_toki tok)
{
	while (1)
	{
		att.i = 0;
		str = prompt(&att);
		if (check_and_clear_history_if_null(str))
			break ;
		reinit_attributes(&att);
		if (str)
		{
			add_history(str);
			att.commands_arr = get_tokens2(str, &att);
			init_pipes(&att);
			while (att.commands_arr[att.i] && !verify_readline(str) \
					&& att.commands_arr[att.i][0] != '\0')
			{
				check_next_step(&att);
				att.tok_arr = get_tokens(att.commands_arr[att.i], &att, tok);
				command(&att, att.i);
				free_tokens(att.tok_arr, &att);
				att.i = att.i + 2;
			}
			free_resources(str, att);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_attr	att;
	t_toki	tok;
	char	*str;

	str = NULL;
	rl_clear_history();
	set_signals();
	init_params(argc, argv, &att, envp);
	init_toki(&tok);
	process_commands_loop(str, att, tok);
	free_g_env(&att);
	free_exp_env(&att);
	return (0);
}
