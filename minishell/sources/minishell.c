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

int		check_next_step(t_attr *att, int *i)
{	
	if (att->commands_arr[*i + 1] && is_symbol(att->commands_arr[*i + 1]))
	{
		if (!ft_strcmp(att->commands_arr[*i + 1], "|"))
			att->write_to_pipe = 1;
		else if (!ft_strcmp(att->commands_arr[*i + 1], ">"))
			att->redir = 1;
	}
	if (*i > 1 && is_symbol(att->commands_arr[*i - 1]))
	{
		if (!ft_strcmp(att->commands_arr[*i - 1], "|"))
			att->read_from_pipe = 1;
		if (!ft_strcmp(att->commands_arr[*i - 1], ">"))
			*i = *i + 1;
	}
	return (0);
}  

void	init_pipes(t_attr *att)
{
	int	i;
	
	att->pipesfd = ft_calloc(att->number_of_pipes + 1, sizeof(int *));
	if (!att->pipesfd)
		return ;
	i = -1;
	while (++i < att->number_of_pipes)
	{
		att->pipesfd[i] = malloc(2 * sizeof(int));
		pipe(att->pipesfd[i]);
	}
}

void ft_delete_matrix (void *matrix)
{
	int i;

	i = -1;
	while (((char **)matrix)[++i])
		free(((char **)matrix)[i]);
	free(matrix);
}

int	main(int ac, char **av, char **envp)
{
	t_attr attr;
	char *str;
	int i;
	int k = 0;

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
			attr.commands_arr = get_tokens2(str, &attr);
			init_pipes(&attr);
			k = 0;
			while (attr.commands_arr[i])
			{
				if (is_symbol(attr.commands_arr[i]))
					i++;
				check_next_step(&attr, &i);
				attr.tok_arr = get_tokens(attr.commands_arr[i], &attr);
				command(&attr, k);
				free_tokens(attr.tok_arr, &attr);
				free(attr.tok_arr);
				i++;
				k++;
			}
			while (waitpid(-1, NULL, 0) > 0)
				continue;
			attr.number_of_pipes = 0;
			ft_delete_matrix(attr.pipesfd);
			free_arr(attr.commands_arr);
			free(str);
		}
	}
	free_g_env(&attr);
	free_exp_env(&attr);
	return (0);
}