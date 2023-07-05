/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/04 17:40:34 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	vrl_skip_quotes(char *str, int i)
{
	if (str[i] == '\'')
	{
		i++;
		while (str[i] != '\'')
			i++;
	}
	else if (str[i] == '"')
	{
		i++;
		while (str[i] != '"' && str[i])
			i++;
	}
	return (i);
}
