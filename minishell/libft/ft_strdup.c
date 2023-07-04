/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:25:40 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:24:28 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sdup;
	int		i;

	i = 0;
	sdup = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!sdup)
		return (NULL);
	while (s[i])
	{
		sdup[i] = s[i];
		i++;
	}
	sdup[i] = 0;
	return (sdup);
}
