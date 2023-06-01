/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:13:14 by alexfern          #+#    #+#             */
/*   Updated: 2023/05/31 20:26:27 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int valid_dirdoc(t_attr *att)
{
    if (!ft_strcmp(att->tok_arr[0], ">") || !ft_strcmp(att->tok_arr[0], "<"))
        return (1);
    else if (!ft_strcmp(att->tok_arr[0], ">>") || !ft_strcmp(att->tok_arr[0], "<<"))
        return (1);
    return (0);
} 

void    heredocs(t_attr *att)
{
    if (valid_dirdoc(att))
        printf("bash: syntax error near unexpected token 'newline'\n");
    return ;
}