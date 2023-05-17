/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:51:22 by alexfern          #+#    #+#             */
/*   Updated: 2023/05/16 19:27:21 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
    removes the spaces at the end of the string and
    returns the new string without the spaces at the
    end of the string.
*/

char	*trim_back(const char *input)
{
	char *result;
	int i;
	int j;
	
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

char    *white_sp_rm(const char *str)
{
    char    *output;
    int     i;
    int     j;
	
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