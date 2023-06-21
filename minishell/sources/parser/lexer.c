/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/21 18:03:59 by jotavare         ###   ########.fr       */
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
	expand_tokens(&att->tok_arr[0], att);
	if (!att->tok_arr[0])
		return ;
	else if (ft_strcmp(att->tok_arr[0], "cd") == 0)
		cd(att);
	else if (ft_strcmp(att->tok_arr[0], "unset") == 0)
		unset(att);
	else if ((ft_strcmp(att->tok_arr[0], "exit") == 0)
			|| (ft_strcmp(att->tok_arr[0], "\"exit\"") == 0))
		return (ft_exit(att));
	else if (ft_strcmp(att->tok_arr[0], "export") == 0 && att->tok_arr[1])
		export(att);
	else
		execute(att, index);
}