/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:38:30 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/01 00:39:06 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	first_step(char **envp, t_attr *att, t_toki *tok)
{
	rl_clear_history();
	set_signals();
	init_params(att, envp);
	init_toki(tok);
}

void	void_params(int ac, char **av)
{
	(void)ac;
	(void)av;
}

void	del_stuff(t_attr *att, char *str)
{
	ft_delete_matrix(att->pipesfd);
	free_arr(att->commands_arr);
	free(str);
}

void	chkstep_gettok(t_attr *att, t_toki *tok)
{
	check_next_step(att);
	att->tok_arr = get_tokens(att->commands_arr[att->i], att, tok);
	command(att, att->i);
	free_tokens(att->tok_arr, att);
	att->i = att->i + 2;
}

void	str_is_true(char *str, t_attr *att, t_toki *tok)
{
	add_history(str);
	att->commands_arr = get_tokens2(str, att);
	init_pipes(att);
	while (att->commands_arr[att->i] && att->commands_arr[att->i][0] != '\0')
		chkstep_gettok(att, tok);
	del_stuff(att, str);
}
