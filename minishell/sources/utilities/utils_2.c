/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:51:22 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 06:14:39 by lde-sous         ###   ########.fr       */
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

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
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
