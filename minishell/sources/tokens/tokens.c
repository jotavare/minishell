/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/28 18:01:35 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	create_array(char *s, t_attr *att)
{
	int	count;

	att->index = 0;
	//printf("NUM TOKS = %d\n", att->nb_tokens);
	att->beforet = malloc((att->nb_tokens + 1) * sizeof(char *));
	att->beforet[att->nb_tokens] = NULL;
	if (!att->beforet)
		return ;
	count = 0;
	while (count < att->nb_tokens)
	{
		while (*s == ' ')
			s++;
		att->beforet[count] = get_token(s, att);
		//printf("TOKEN GIVEN = %s\n", att->beforet[count]);
		if (att->beforet[count] == 0 && count < att->nb_tokens)
		{
			s = NULL;
			return ;
		}
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
	return (att->beforet);
}
