/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubu <lubu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/22 11:11:25 by lubu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
    The command function handles basic command recognition
    and execution based on the input string, providing
    feedback or return values accordingly.
*/

void	command(const char *input, t_attr *att, char **envp)
{
	char	**tok;

	(void)envp;
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
		return (ft_exit(input, *att));
	else if (!input[0])
		readline("\033[0;32mminishell$\033[0m ");
	else
		printf("%s: command not found\n", tok[0]);
}
