/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/16 22:35:13 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	prints the string after echo command to the terminal
	> format: "echo <string>"
	> status: working
*/
void	echo(const char *input)
{
	if (strncmp(input, "echo ", 5) == 0)
    {
		input = input + 5;
		rl_redisplay();
		printf("%s\n", input);
	}
	else if (strcmp(input, "echo") == 0)
		printf("\n");
}