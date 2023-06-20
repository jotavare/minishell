/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/06/20 11:39:10 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_last_return_value;

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

int	double_quote(char *str, char c)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c && flag == 0)
			flag = 1;
		else if (str[i] == '\'' && flag == 1)
			flag = 2;
		else if (str[i] == '\'' && flag == 2)
			flag = 1;
		else if (str[i] == c && flag == 1)
			flag = 0;
		i++;
	}
	if (flag)
	{
		printf(ERROR_UNCLOSED);
		return (1);
	}
	return (0);
}

int	single_quote(char *str, char c)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c && flag == 0)
			flag = 1;
		else if (str[i] == '\"' && flag == 1)
			flag = 2;
		else if (str[i] == '\"' && flag == 2)
			flag = 1;
		else if (str[i] == c && flag == 1)
			flag = 0;
		i++;
	}
	if (flag)
	{
		printf(ERROR_UNCLOSED);
		return (1);
	}
	return (0);
}

int	error_quotes(char *str)
{
	if (double_quote(str, '\"') || single_quote(str, '\''))
		return (1);
	return (0);
}

int	verify_readline(char *str)
{
	if (error_pipes(str))
	{
		g_last_return_value = 2;
		return (1);
	}
	else if (error_dirdoc(str))
	{
		g_last_return_value = 2;
		return (1);
	}
	else if (error_quotes(str))
	{
		g_last_return_value = 2;
		return (1);
	}
	return (0);
}
