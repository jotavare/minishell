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

int is_symbol(char *s)
{
    char *symbols[] = {">", "<", ">>", "<<", "|" };
    int i;

    if (s[0] == '\0')
	{
        return 0;
    }

    i = 0;
    while (i < 5)
    {
        if (!ft_strcmp(s, symbols[i]))
            return 1;
        i++;
    }
    return 0;
}

int		check_next_step(t_attr *att, int i)
{	
	if (att->commands_arr[i + 1] && is_symbol(att->commands_arr[i + 1]))
	{
		if (!ft_strcmp(att->commands_arr[i + 1], "|"))
			att->write_to_pipe = 1;
	}
	if (i > 1 && is_symbol(att->commands_arr[i - 1]))
	{
		if (!ft_strcmp(att->commands_arr[i - 1], "|"))
			att->read_from_pipe = 1;
	}
	return (0);
}  

/* void	init_pipes(t_attr *att)
{
	int	i;
	
	i = 0;
	while (i < att->number_of_pipes)
	{
		pipe(att->pipefd[i]);
	}
} */

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
			//pipe(attr.pipefd);
			attr.commands_arr = get_tokens2(str, &attr);
			//init_pipes(&attr);
			//ft_print_array(attr.commands_arr);
			while (attr.commands_arr[i])
			{
				if (is_symbol(attr.commands_arr[i]))
					i++;
				check_next_step(&attr, i);
				attr.tok_arr = get_tokens(attr.commands_arr[i], &attr);
				//ft_print_array(attr.tok_arr);
				// print_t_attr(&attr);
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