/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:51:22 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:25:06 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
    removes the spaces at the end of the string and
    returns the new string without the spaces at the
    end of the string.
*/

char	*trim_back(const char *input)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	while (input[i] == ' ')
		i++;
	result = malloc(sizeof(char) * (ft_strlen(input) - i) + 1);
	if (!result)
		return (NULL);
	j = 0;
	while (input[i])
	{
		result[j] = input[i];
		j++;
		i++;
	}
	result[j] = '\0';
	return (result);
}

/*
    removes the spaces from the string and returns the
    new string without the spaces in the middle of the
    string and at the end of the string.
*/

char	*white_sp_rm(const char *str)
{
	char	*output;
	int		i;
	int		j;

	output = malloc(sizeof(char) * 4);
	if (!output)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
		{
			output[j] = str[i];
			j++;
		}
		i++;
	}
	output[3] = 0;
	return (output);
}

/*
	compares two strings and returns 1 if the first
	string is bigger than the second string, -1 if
	the second string is bigger than the first string
	and 0 if the strings are equal.
*/

int	ft_strcmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	if (!str1[i] || !str2[i])
		return (2);
	while (str1[i] || str2[i])
	{
		if (str1[i] == str2[i])
			i++;
		else if (str1[i] > str2[i])
			return (1);
		else if (str2[i] > str1[i])
			return (-1);
	}
	return (0);
}

/*
	counts the number of characters in a string and
	returns the number of characters in the string and
	append the null character at the end of the string.
*/

char	*ft_strcpy(char *destination, const char *source)
{
	char	*start;

	start = destination;
	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return (start);
}

/*
	counts the number of times a character appears
	in a string and returns the number of times the
	character appears in the string.
*/

int	flag_counter(char *str, char c)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] == c)
			result++;
		i++;
	}
	return (result);
}
