/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:15:17 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:25:05 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*tempvector;
	size_t		i;
	size_t		total;

	total = nmemb * size;
	tempvector = malloc(total);
	if (!tempvector)
		return (NULL);
	i = 0;
	while (i < total)
	{
		tempvector[i] = '\0';
		i++;
	}
	return ((void *)tempvector);
}
