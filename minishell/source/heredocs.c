/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:13:14 by alexfern          #+#    #+#             */
/*   Updated: 2023/05/31 18:20:20 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int check_heredocs(t_attr *att)
{
    int i;

    i = 0;
    while (att->tok_arr[i])
    {
        if (att->tok_arr[i] == '>')
            return (1);
        i++;
    }
    return (0);
}

