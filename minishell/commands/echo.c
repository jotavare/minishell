/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/29 17:26:57 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	prints the string after echo command to the terminal
	with a new line at the end of the string
*/

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
			else if (ft_strnstr(att.tok_arr[i], "$?",ft_strlen(att.tok_arr[i])))
                printf("%d", att.last_return_value);
			else if (ft_strnstr(att.tok_arr[i], "$",ft_strlen(att.tok_arr[i])))
				printf("%s ", expand_variable(att.tok_arr[i], att.g_env));
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