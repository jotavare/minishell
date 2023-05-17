/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:53:09 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/10 16:06:08 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(const char *s1, const char *s2)
{
    int i = 0;
    int j = 0;
    char *allocated;

    if (!s1 || !s2)
        return NULL;

    allocated = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!allocated)
        return NULL;

    while (s1[i])
    {
        allocated[i] = s1[i];
        i++;
    }

    while (s2[j])
    {
        allocated[i] = s2[j];
        i++;
        j++;
    }

    allocated[i] = '\0';
    return allocated;
}
