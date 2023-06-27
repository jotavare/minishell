/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/06/27 15:05:21 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
    handle_interrupt is a signal handler for Ctrl+C
    (SIGINT) that clears the current input line and
    starts a new line with a new prompt.
	SIGINT - CTRL C
	SIGQUIT - CTRL BACKSLSH
	SIGTSTP - CTRL Z
*/

void	handle_interrupt(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	g_value = 130;
}

void	handler_exec(int sig)
{
	g_value = 131;
	printf("entrou");
	if (sig == SIGQUIT)
		kill(0, SIGINT);
}

void	set_signals(void)
{
	signal(SIGINT, handle_interrupt);
	signal(SIGQUIT, SIG_IGN);
}