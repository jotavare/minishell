/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:38:30 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/19 16:13:47 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_t_attr(t_attr *att)
{
    printf(YELLOW_BOLD"\n====== DEBUGGING INFO ======\n"RESET);
	printf("\n");
	printf("  "YELLOW_BOLD"[TOKENS]:\n"RESET);
    int i = 0;
    while (att->tok_arr[i]) {
        printf("     %i: %s\n", i, att->tok_arr[i]);
        i++;
    }
	i = 0;
	printf("  "YELLOW_BOLD"[ARRAY]:\n"RESET);
    while (att->commands_arr[i]) {
        printf("     %i: %s\n", i, att->commands_arr[i]);
        i++;
    }
    printf("  "YELLOW_BOLD"[Nº TOKENS]:"RESET" %d\n", att->nb_tokens);
    printf("  "YELLOW_BOLD"[LEN d_env]:"RESET" %d\n", att->len_d_env);
    printf("  "YELLOW_BOLD"[LEN g_env]:"RESET" %d\n", att->len_g_env);
    printf("  "YELLOW_BOLD"[LAST PATH]:"RESET" %s\n", att->last_path);
    printf(YELLOW_BOLD"\n====== DEBUGGING INFO ======\n\n"RESET);
}

void	ft_print_array(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		printf ("%d - %s\n", i, array[i]);
		i++;
	}
	printf("end of array\n\n");
}

void  see_flags_and_pipes(t_attr att)
{
    printf("----------------------\n");
    printf("nb of pipes: %d\n", att.number_of_pipes);
    printf("token: %s, index: %d\n", att. commands_arr[att.i], att.i);
    printf("read from pipe: %d\n", att.read_from_pipe);
    printf("write to pipe: %d\n", att.write_to_pipe);
    printf("redir: %d\n", att.redir);
    printf("read from file: %d\n", att.read_from_file);
    printf("----------------------\n");
}
