/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:51:22 by jotavare          #+#    #+#             */
/*   Updated: 2023/07/02 12:15:31 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	if the string is a valid variable name
	(no spaces, no numbers, no special characters).
*/

int	check_firstchar(char *str)
{
	if (!str)
		return (0);
	if (str[0] != '\0')
	{
		if (str[0] >= '0' && str[0] <= '9')
			return (1);
		if (!(ft_isalpha(str[0])))
			return (1);
	}
	return (0);
}

int	check_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '=')
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (check_firstchar(str))
			return (0);
		if (!ft_isalpha(str[i]) && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strcat(char *dest, const char *src)
{
	char	*ptr;

	ptr = dest;
	while (*ptr)
		ptr++;
	while (*src)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dest);
}

int	str_empty(char *str)
{
	if (str == NULL)
	{
		rl_clear_history();
		return (1);
	}
	return (0);
}
