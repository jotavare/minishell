/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printundec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:25:40 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 06:10:57 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printundec(unsigned int decimal)
{
	int	count;

	count = 0;
	if (decimal >= 10)
	{
		count += ft_printundec(decimal / 10);
		decimal = (decimal % 10);
	}
	if (decimal < 10)
		count += ft_printchar(decimal + '0');
	return (count);
}
