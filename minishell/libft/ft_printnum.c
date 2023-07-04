/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:25:40 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 06:11:07 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnum(long num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		num = (num * -1);
		count++;
	}
	if (num >= 10)
	{
		count += ft_printnum(num / 10);
		num = (num % 10);
	}
	if (num < 10)
	{
		count += ft_printchar(num + '0');
	}
	return (count);
}
