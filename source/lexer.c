/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/16 22:00:34 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
    The command function handles basic command recognition
    and execution based on the input string, providing
    feedback or return values accordingly.
*/

void command(const char *input, t_attr att)
{
    char *str1;
    char    **tok;
    
    tok = att.s_arr;
    str1 = trim_back(input);
    if ((strncmp(str1, "echo ", 5) == 0) || (strncmp(str1, "echo", 4) == 0))
        echo(str1);
    else
    {
        str1 = ft_strtrim(input, " ");
        if (strcmp(str1, "pwd") == 0)
            pwd();
        else if (strcmp(tok[0], "cd") == 0)
            cd(str1, att);
        else if (strcmp(input, "export") == 0)
            printf("export\n");
        else if (strcmp(input, "unset") == 0)
            printf("unset\n");
        else if (strcmp(input, "env") == 0)
            printf("env\n");
        else if (strcmp(input, "exit") == 0)
            return ;
        else if (!input[0])
            readline("\033[0;32mminishell$\033[0m ");
        else
            printf("%s: command not found\n", input);
    }
}

