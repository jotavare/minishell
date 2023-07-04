/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:25:40 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:23:01 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	j;

	j = 0;
	if ((start > ft_strlen(s)) || (!s) || (len == 0))
	{
		sub = (char *)malloc(sizeof(char) * 1);
		sub[0] = 0;
		return (sub);
	}
	else
	{
		if (len >= ft_strlen(s))
			len = ft_strlen(s) - start;
		sub = (char *)malloc(sizeof(char) * (len + 1));
		if (!sub)
			return (NULL);
		while (j < ft_strlen(s) && len > 0)
		{
			sub[j++] = s[start++];
			len--;
		}
		sub[j] = 0;
	}
	return (sub);
}
