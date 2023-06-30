/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chck.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:25:40 by jotavare          #+#    #+#             */
/*   Updated: 2023/06/30 06:08:57 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_chck(char to_check)
{
	char	*format;
	int		i;

	i = 0;
	format = "csidxXup%";
	while (format[i])
	{
		if (to_check == format[i])
			return (format[i]);
		i++;
	}
	return (0);
}
