/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/31 03:02:59 by jotavare         ###   ########.fr       */
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

	i = 1;
	if (att.nb_tokens == 1)
		printf("\n");
	else
	{
		while (i < att.nb_tokens)
		{
			if (ft_strnstr(att.tok_arr[i], "-n", ft_strlen(att.tok_arr[i])))
				echo_n(att);
			else if (ft_strnstr(att.tok_arr[i], "$?",
						ft_strlen(att.tok_arr[i])))
				printf("%d", g_last_return_value);
			else
				printf("%s ", att.tok_arr[i]);
			i++;
		}
		printf("\n");
	}
}

/*
	prints the string after echo command to the terminal
	with the -n option = no new line at the end of the string
*/

void	echo_n(t_attr att)
{
	int i;

	i = 2;
	while (i < att.nb_tokens)
	{
		ft_putstr_fd(att.tok_arr[i], 1);
		if (att.tok_arr[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
}

void	echo_doll_ques(t_attr att)
{
	int i;

	i = 2;
	while (i < att.nb_tokens)
	{
		ft_putstr_fd(att.tok_arr[i], 1);
		if (att.tok_arr[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
}