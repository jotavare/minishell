/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/06/27 14:41:45 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	error_pipes(char *str)
{
	if (error_last(str, '|'))
		return (1);
	if (error_simple(str, '|'))
		return (1);
	if (error_onepipe(str))
		return (1);
	return (0);
}

int	error_simple_dirdoc(char *str, char c)
{
	if (!str)
		return (0);
	if (ft_strlen(str) >= 2)
	{
		if (str[0] == c && (str[1] == c || str[1] == '\0') && str[2] == '\0')
		{
			printf(ERROR_NLINE);
			return (1);
		}
	}
	return (0);
}

int	error_single(char *str, char c)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] == c && flag == 0)
			return (0);
		if (str[i] == c && flag == 0)
			flag = 1;
		else if (str[i] != c && str[i] != ' ' && flag == 1)
			flag = 0;
		else if (str[i] == c && flag == 1)
		{
			if (str[i] == c && str[i + 1] == c)
				printf(ERROR_TWO, c, c);
			else
				printf(ERROR_ONE, c);
			return (1);
		}
		i++;
	}
	return (0);
}

int	error_double(char *str, char c)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] == c && flag == 0)
			flag = 1;
		else if (str[i] != c && str[i] != ' ' && flag)
			flag = 0;
		else if (str[i] == c && flag == 1)
			flag = 2;
		else if (((str[i] == c && str[i + 1] == c) || str[i] == c) && flag == 2)
		{
			if (str[i] == c && str[i + 1] == c)
				printf(ERROR_TWO, c, c);
			else
				printf(ERROR_ONE, c);
			return (1);
		}
		i++;
	}
	return (0);
}
