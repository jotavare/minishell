/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/24 18:35:07 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
    The command function handles basic command recognition
    and execution based on the input string, providing
    feedback or return values accordingly.
*/

void	command(t_attr *att)
{
	char	**tok;

	if (!att->tok_arr[0])
		return ;
	tok = att->tok_arr;
	if (!ft_strcmp(att->tok_arr[0], "echo"))
		echo(*att);
	else if (ft_strcmp(tok[0], "pwd") == 0)
		pwd();
	else if (ft_strcmp(tok[0], "cd") == 0)
		cd(att);
	else if (ft_strcmp(tok[0], "export") == 0)
		export(att);
	else if (ft_strcmp(tok[0], "unset") == 0)
		unset(att);
	else if (ft_strcmp(tok[0], "env") == 0)
		env(att);
	else if ((ft_strcmp(tok[0], "exit") == 0) || (ft_strcmp(tok[0], "\"exit\"") == 0))
		return (ft_exit(*att));
	else
		execute(att);
	return;
}
