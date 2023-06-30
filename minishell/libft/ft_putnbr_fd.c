/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:25:40 by jotavare          #+#    #+#             */
/*   Updated: 2023/06/30 06:07:31 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;

	if (fd < 0)
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		number = (unsigned int)(n * -1);
	}
	else
		number = (unsigned int)n;
	if (number >= 10)
		ft_putnbr_fd(number / 10, fd);
	ft_putchar_fd((char)(number % 10 + '0'), fd);
}
