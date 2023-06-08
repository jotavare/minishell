/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/18 150:00 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_last_return_value;

int	main(int ac, char **av, char **envp)
{
	t_attr attr;
	char *str;
	int i;

	rl_clear_history();
	set_signals();
	init_params(ac, av, &attr, envp);
	while (1)
	{
		i = 0;
		str = prompt(&attr);
		if (str == NULL)
		{
			rl_clear_history();
			break ;
		}
		reinit_attributes(&attr);
		if (str)
		{
			add_history(str);
			attr.commands_arr = ft_split_set(str, ">|<");
			while (attr.commands_arr[i])
			{
				attr.tok_arr = get_tokens(attr.commands_arr[i], &attr);
				//ft_print_array(attr.tok_arr);
				command(&attr);
				free_tokens(attr.tok_arr, &attr);
				free(attr.tok_arr);
				i++;
			}
			free_arr(attr.commands_arr);
			free(str);
		}
	}
	free_g_env(&attr);
	free_exp_env(&attr);
	return (0);
}