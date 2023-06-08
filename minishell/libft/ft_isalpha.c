/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:05:36 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/04 20:02:34 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int x)
{
	if ((x > 64 && x < 91) || (x > 96 && x < 123) || x == '_')
		return (1);
	else
		return (0);
}
