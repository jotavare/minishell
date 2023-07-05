/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexfern          #+#    #+#             */
/*   Updated: 2023/07/04 23:18:21 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	error_dirdoc(char *str)
{
	if (error_simple_dirdoc(str, '>') || error_simple_dirdoc(str, '<'))
		return (1);
	else if (error_mixed(str, '>', '<') || error_mixed(str, '<', '>')
		|| error_mixed(str, '<', '|') || error_mixed(str, '>', '|'))
		return (1);
	else if (error_double(str, '>') || error_double(str, '<'))
		return (1);
	else if (error_single(str, '>') || error_single(str, '<'))
		return (1);
	else if (error_last(str, '>') || error_last(str, '<'))
		return (1);
	return (0);
}

void	unclosed_quotes_aux(t_err *error, char c, char *str)
{
	error->is_open++;
	error->i++;
	while (str[error->i] != c && str[error->i])
		error->i++;
	if (str[error->i] == c)
		error->is_open++;
}

int	unclosed_quotes(char *str, t_err *error)
{
	while (str[error->i])
	{
		if (str[error->i] == 34 && str[error->i])
			unclosed_quotes_aux(error, 34, str);
		else if (str[error->i] == 39 && str[error->i])
			unclosed_quotes_aux(error, 39, str);
		if (!str[error->i])
			break ;
		error->i++;
	}
	if (error->is_open % 2 != 0)
	{
		printf(ERROR_UNCLOSED);
		return (1);
	}
	return (0);
}

int	error_quotes(char *str)
{
	t_err	error;

	error.i = 0;
	error.is_open = 0;
	if (unclosed_quotes(str, &error))
		return (1);
	return (0);
}

int	verify_readline(char *str)
{
	if (error_quotes(str))
	{
		add_history(str);
		g_value = 2;
		return (1);
	}
	if (error_pipes(str))
	{
		add_history(str);
		g_value = 2;
		return (1);
	}
	if (error_dirdoc(str))
	{
		add_history(str);
		g_value = 2;
		return (1);
	}
	return (0);
}
