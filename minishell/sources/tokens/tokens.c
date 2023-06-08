/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/08 03:13:07 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	create_array(char *s, t_attr *att)
{
	int	count;

	att->index = 0;
	att->beforet = malloc((att->nb_tokenst + 1) * sizeof(char *));
	att->beforet[att->nb_tokenst] = NULL;
	if (!att->beforet)
		return ;
	count = 0;
	while (count < att->nb_tokenst)
	{
		while (*s == ' ')
			s++;
		att->beforet[count] = get_token(s, att);
		s += att->tok_arr_i;
		count++;
	}
}

char	**get_tokens(char *str, t_attr *att)
{
	if (!str)
		return (NULL);
	count_tokens(str, att);
	create_array(str, att);
	//expand_tokens(att->tok_arr, att);
	return (att->beforet);
}