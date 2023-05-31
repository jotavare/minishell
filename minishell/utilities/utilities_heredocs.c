/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_heredocs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:29:43 by alexfern          #+#    #+#             */
/*   Updated: 2023/05/31 20:57:30 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void count_dirdoc(t_attr *att)
{
    int i;

    i = 0;
    while (att->tok_arr[i])
    {
        if (!ft_strcmp(att->tok_arr[i], ">"))
        {
            att->dirdoc.single_right++;
            printf("dirdoc.single_right %d\n", att->dirdoc.single_right);
        }
        else if (!ft_strcmp(att->tok_arr[i], "<"))
        {
            att->dirdoc.single_left++;
            printf("dirdoc.single_left %d\n", att->dirdoc.single_left);
        }
        else if (!ft_strcmp(att->tok_arr[i], ">>"))
        {
            att->dirdoc.double_right++;
            printf("dirdoc.double_right %d\n", att->dirdoc.double_right);
        }
        else if (!ft_strcmp(att->tok_arr[i], "<<"))
        {
            att->dirdoc.double_left++;
            printf("dirdoc.double_left %d\n", att->dirdoc.double_left);
        }
        i++;
    }
}