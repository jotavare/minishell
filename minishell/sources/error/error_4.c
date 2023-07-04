/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:18:50 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	print_error_pipe(char *str, int i)
{
	if (str[i] == '|' && str[i + 1] == '|')
		printf(ERROR_PIPE2);
	else
		printf(ERROR_PIPE1);
	return (1);
}

int	error_onepipe(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			i = vrl_skip_quotes(str, i);
		else if ((str[i] == '>' || str[i] == '<') && str[i + 1] == '|')
		{
			if (especialcase(str, i) || especialcase_two(str, i))
				return (1);
		}
		else if ((str[i] == '|' || str[i] == '>' || str[i] == '<') && flag == 0)
			flag = 1;
		else if ((str[i] != '|' && str[i] != ' ') && flag == 1)
			flag = 0;
		else if (str[i] == '|' && flag == 1)
			return (print_error_pipe(str, i));
		i++;
	}
	return (0);
}

int	print_mixed_error(char *str, char r, int i)
{
	if (str[i] == r && str[i + 1] == r)
		printf(ERROR_TWO, r, r);
	else
		printf(ERROR_ONE, r);
	return (1);
}

int	error_mixed(char *str, char c, char r)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			i = vrl_skip_quotes(str, i);
		else if (str[i] == '>' && str[i + 1] == '|')
			return (0);
		else if (str[i] == '<' && str[i + 1] == '>' && flag == 0)
			return (0);
		else if (str[i] == c && flag == 0)
			flag = 1;
		else if (str[i] == c && flag == 1)
			flag = 2;
		else if ((str[i] != c && str[i] != ' ' && str[i] != r) && (flag == 1
				|| flag == 2))
			flag = 0;
		else if (str[i] == r && (flag == 1 || flag == 2))
			print_mixed_error(str, r, i);
		i++;
	}
	return (0);
}

int	start_args_error(t_attr *att, t_exec *args, int *g_value)
{
	if (start_args(args, att) == -1)
	{
		att->has_path = 0;
		printf("Minishell: %s: No such file or directory\n", att->tok_arr[0]);
		return (*g_value);
	}
	return (-1);
}
