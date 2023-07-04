/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 01:30:44 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:17:27 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_the_arr(char **search, char *str)
{
	int	j;

	if (check_equal(str))
	{
		j = 0;
		while (str[j] != '=')
		{
			j++;
		}
		return (check_the_arr_with_equal(search, str, j));
	}
	else
		return (check_the_arr_without_equal(search, str));
}

int	check_the_arr_without_equal(char **search, char *str)
{
	int		length;
	char	*to_find;
	int		result;

	length = 0;
	while (str[length])
		length++;
	to_find = add_equal(str);
	result = check_the_arr_with_equal(search, to_find, length);
	free(to_find);
	return (result);
}

int	check_the_arr_with_equal(char **search, char *to_find, int length)
{
	int	i;

	i = 0;
	while (search[i])
	{
		if (!ft_strncmp(search[i], to_find, length))
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	check_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '=')
			return (0);
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}
