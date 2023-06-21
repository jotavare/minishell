/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/06/21 20:14:22 by jotavare         ###   ########.fr       */
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
	int	fl_n;
	int	fl_pr;

	i = 1;
	fl_n = 0;
	fl_pr = 0;
	while (i < att.nb_tokens && att.tok_arr[i])
	{
		if (ft_strnstr(att.tok_arr[i], "-n",
				ft_strlen(att.tok_arr[i])) && fl_pr == 0)
		{
			echo_n(att);
			fl_n = 1;
		}
		else if (ft_strnstr(att.tok_arr[i], "$?",
				ft_strlen(att.tok_arr[i])))
			printf("%d", g_last_return_value);
		else
		{
			printf("%s", att.tok_arr[i]);
			fl_pr = 1;
		}
		if (i != att.nb_tokens - 1 && fl_pr == 1)
			printf(" ");
		i++;
	}
	if (fl_n == 0)
		printf("\n");
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
