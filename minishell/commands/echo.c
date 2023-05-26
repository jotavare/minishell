/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/22 19:02:59 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	prints the string after echo command to the terminal
	with a new line at the end of the string
*/

void echo(t_attr att)
{
    int i;

    i = 1;
    if (att.nb_tokens == 1)
        ft_putchar_fd('\n', 1);
    else if (!strcmp(att.tok_arr[0], "echo") && !strcmp(att.tok_arr[1], "-n"))
    {
        echo_n(att);
    }
    else if (!strcmp(att.tok_arr[0], "echo") && strcmp(att.tok_arr[1], "$") == 0)
    {
        char *env_var = getenv(att.tok_arr[2]); // this is not the correct way to do it
        if (env_var != NULL)
            ft_putstr_fd(env_var, 1);
        ft_putchar_fd('\n', 1);
    }
    else if (!strcmp(att.tok_arr[0], "echo"))
    {
        while (i < att.nb_tokens)
        {
            ft_putstr_fd(att.tok_arr[i], 1);
            ft_putchar_fd(' ', 1);
            i++;
        }
        ft_putchar_fd('\n', 1);
    }
}

/*
	prints the string after echo command to the terminal
	with the -n option = no new line at the end of the string
*/

void	echo_n(t_attr att)
{
	int	i;

	i = 2;
	while (i < att.nb_tokens)
	{
		ft_putstr_fd(att.tok_arr[i], 1);
		if (att.tok_arr[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
}
