/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/06/20 01:58:02 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	prints the string after echo command to the terminal
	with a new line at the end of the string
*/

extern int	g_last_return_value;

void	echo(t_attr att)
{
	int	i;
	int flag_n;
	int flag_print;

	i = 1;
	flag_n = 0;
	flag_print = 0;
	if (att.nb_tokens == 1)
		printf("\n");
	else
	{
		while (i < att.nb_tokens)
		{
			if (ft_strnstr(att.tok_arr[i], "-n", ft_strlen(att.tok_arr[i])) && flag_print == 0)
			{
				echo_n(att);
				flag_n = 1;				
			}
			else if (ft_strnstr(att.tok_arr[i], "$?", ft_strlen(att.tok_arr[i])))
				printf("%d", g_last_return_value);
			else
			{
				printf("%s", att.tok_arr[i]);
				flag_print = 1;
			}
			if (i != att.nb_tokens - 1 && flag_print == 1)
				printf(" ");
			i++;
		}
		if (flag_n == 0)
			printf("\n");
	}
	//kill(getpid(), SIGTERM);
}

/*
	prints the string after echo command to the terminal
	with the -n option = no new line at the end of the string
*/

void	echo_n(t_attr att)
{
	int	i;

	i = 1;

	if (strcmp(att.tok_arr[i], "-n") != 0)
		ft_putstr_fd(att.tok_arr[i], 1);
	i++;
}