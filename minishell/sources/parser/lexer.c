/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/16 02:18:22 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
    The command function handles basic command recognition
    and execution based on the input string, providing
    feedback or return values accordingly.
*/

void	command(t_attr *att, int index)
{
	if (!att->tok_arr[0])
		return ;
	if (!ft_strcmp(att->tok_arr[0], "echo"))
		echo(*att);
	else if (ft_strcmp(att->tok_arr[0], "pwd") == 0)
		pwd();
	else if (ft_strcmp(att->tok_arr[0], "cd") == 0)
		cd(att);
	else if (ft_strcmp(att->tok_arr[0], "export") == 0)
		export(att);
	else if (ft_strcmp(att->tok_arr[0], "unset") == 0)
		unset(att);
	else if (ft_strcmp(att->tok_arr[0], "env") == 0)
		env(att);
	else if ((ft_strcmp(att->tok_arr[0], "exit") == 0)
			|| (ft_strcmp(att->tok_arr[0], "\"exit\"") == 0))
		return (ft_exit(att));
	else
	{
		if (att->number_of_pipes == 0)
			execute(att, index);
		else if (att->number_of_pipes > 0
				&& (att->write_to_pipe || att->read_from_pipe)) 
			execute_pipeline(att, index);
	}
	return ;
}
