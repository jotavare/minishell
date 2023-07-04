/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:19:08 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	error_last(char *str, char c)
{
	int	len;

	len = ft_strlen(str);
	if (len == 0)
		return (0);
	if (str[len - 1] == c)
	{
		if (c != '|')
			printf(ERROR_NLINE);
		else
		{
			if (str[len - 2] == c)
				printf(ERROR_PIPE2);
			else
				printf(ERROR_PIPE1);
		}
		return (1);
	}
	return (0);
}

int	error_simple(char *str, char c)
{
	if (!str)
		return (0);
	if (str[0] == c && str[1] == c)
	{
		printf(ERROR_SIMPLE_2, str[0], str[1]);
		return (1);
	}
	else if (str[0] == c)
	{
		printf(ERROR_SIMPLE_1, str[0]);
		return (1);
	}
	return (0);
}

int	especialcase(char *str, int i)
{
	if (!str || i < 0)
		return (0);
	if (str[i] == '>' && str[i + 1] == '|' && str[i + 2] == '\0' && str[i
			- 1] != '>')
	{
		printf(ERROR_NLINE);
		return (1);
	}
	else if (str[i] == '<' && str[i + 1] == '|')
	{
		while ((i + 2) < (int)ft_strlen(str))
		{
			if (str[i + 2] != ' ' && str[i + 2] != '\t')
				return (0);
			i++;
		}
	}
	return (0);
}

int	especialcase_two(char *str, int i)
{
	char	c;

	c = str[i];
	if (!str || i < 0)
		return (0);
	if (str[i - 1] == c && str[i] == c && str[i + 1] == '|' && str[i
			+ 2] == '|')
	{
		printf(ERROR_PIPE2);
		return (1);
	}
	else if (str[i - 1] == c && str[i] == c && str[i + 1] == '|')
	{
		printf(ERROR_PIPE1);
		return (1);
	}
	return (0);
}
