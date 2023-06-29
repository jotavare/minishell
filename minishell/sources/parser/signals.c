/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/06/29 17:43:21 by jotavare         ###   ########.fr       */
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
	if (sig == SIGQUIT)
		write (1, "Quit (core dumped)", 18);
	write(1, "\n", 1);
}

void	set_signals(void)
{
	signal(SIGINT, handle_interrupt);
	signal(SIGQUIT, SIG_IGN);
}

void	set_signals2(void)
{
	signal(SIGINT, handler_exec);
	signal(SIGQUIT, handler_exec);
}

void	heredoc_handler(int sig)
{
	if (sig == SIGINT)
	{
		unlink(".heredoc");
		exit(130);
	}
	else if (sig == SIGQUIT)
	{
		unlink(".heredoc");
		exit(131);
	}
}
