/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/08 02:59:49 by jotavare         ###   ########.fr       */
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
	//ft_print_array(att->beforet);
	//printf("p_nbr= %d\n", att->nb_pipes);
	return (att->beforet);
}

void	print_t_attr(t_attr *attr)
{
    printf("\n====== DEBUGGING INFO ======\n");
	printf("\n");
	printf("  "YELLOW_BOLD"[TOKENS]:\n"RESET);
    int i = 0;
    while (attr->tok_arr[i]) {
        printf("     %i: %s\n", i, attr->tok_arr[i]);
        i++;
    }
	i = 0;
	printf("  "YELLOW_BOLD"[ARRAY]:\n"RESET);
    while (attr->commands_arr[i]) {
        printf("     %i: %s\n", i, attr->commands_arr[i]);
        i++;
    }
    printf("  "YELLOW_BOLD"[Nº TOKENS]"RESET": %d\n", attr->nb_tokenst);
    printf("  "YELLOW_BOLD"[LEN d_env]"RESET": %d\n", attr->len_d_env);
    printf("  "YELLOW_BOLD"[LEN g_env]"RESET": %d\n", attr->len_g_env);
    printf("\n====== DEBUGGING INFO ======\n\n");
}
