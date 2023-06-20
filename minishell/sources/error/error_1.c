/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/06/20 06:25:27 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_last_return_value;

int	error_last(char *str, char c)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 1] == c)
	{
		if (c != '|')
			printf("bash: syntax error near unexpected token 'newline'\n");
		return (1);
	}
	return (0);
}

int	error_simple(char *str, char c)
{
	if (str[0] == c && str[1] == c)
	{
		printf("bash: parse error near 'simp%c%c'\n", str[0], str[1]);
		return (1);
	}
	else if (str[0] == c)
	{
		printf("bash: syntax error near unexpected token '%c'\n", str[0]);
		return (1);
	}
	return (0);
}

int	especialcase(char *str, int i)
{
	if (str[i] == '>' && str[i + 1] == '|' && str[i + 2] == '\0' && str[i
		- 1] != '>')
	{
		printf("bash: syntax error near unexpected token 'newline'\n");
		return (1);
	}
	else if (str[i] == '<' && str[i + 1] == '|')
		while ((i + 2) < (int)ft_strlen(str))
		{
			if (str[i + 2] != ' ' && str[i + 2] != '\t')
				return (0);
			i++;
		}
	return (0);
}

int	especialcase_two(char *str, int i)
{
	char	c;

	c = str[i];
	if (str[i - 1] == c && str[i] == c && str[i + 1] == '|' && str[i
		+ 2] == '|')
	{
		printf("bash: syntax error near unexpected token '||'\n");
		return (1);
	}
	else if (str[i - 1] == c && str[i] == c && str[i + 1] == '|')
	{
		printf("bash: syntax error near unexpected token '|'\n");
		return (1);
	}
	return (0);
}

int	error_onepipe(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
			break ;
		if ((str[i] == '>' || str[i] == '<') && str[i + 1] == '|')
		{
			if (especialcase(str, i) || especialcase_two(str, i))
				return (1);
			else
				return (0);
		}
		else if ((str[i] == '|' || str[i] == '>' || str[i] == '<') && flag == 0)
			flag = 1;
		else if ((str[i] != '|' && str[i] != ' ') && flag == 1)
			flag = 0;
		else if (str[i] == '|' && flag == 1)
		{
			if (str[i] == '|' && str[i + 1] == '|')
				printf("bash: syntax error near unexpected token '||'\n");
			else
				printf("bash: syntax error near unexpected token '|'\n");
			return (1);
		}
		i++;
	}
	return (0);
}
