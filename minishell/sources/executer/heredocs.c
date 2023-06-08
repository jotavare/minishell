/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:13:14 by alexfern          #+#    #+#             */
/*   Updated: 2023/06/08 01:35:32 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	valid_dirdoc(t_attr *att)
{
	if (!ft_strcmp(att->tok_arr[0], ">") || !ft_strcmp(att->tok_arr[0], "<"))
		return (1);
	else if (!ft_strcmp(att->tok_arr[0], ">>") || !ft_strcmp(att->tok_arr[0],
				"<<"))
		return (1);
	return (0);
}

void	heredocs(t_attr *att)
{
	if (valid_dirdoc(att))
		printf("bash: syntax error near unexpected token 'newline'\n");
	return ;
}

/* void count_dirdoc(t_attr *att)
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
} */