/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:25:40 by jotavare          #+#    #+#             */
/*   Updated: 2023/06/30 06:11:26 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest2;
	const char		*src2;

	dest2 = dest;
	src2 = src;
	if (!dest && !src)
		return (NULL);
	if (src < dest)
	{
		while (n--)
			dest2[n] = src2[n];
	}
	else
		while (n--)
			*dest2++ = *src2++;
	return (dest);
}
