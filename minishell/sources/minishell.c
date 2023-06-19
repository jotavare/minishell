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

int check_next_step(t_attr *att, int *i)
{
	att->write_to_pipe = 0;
	att->redir = 0;
	att->read_from_pipe = 0;
	att->read_from_file = 0;
	
	if (att->commands_arr[*i + 1] && is_symbol(att->commands_arr[*i + 1]))
	{
		if (!ft_strcmp(att->commands_arr[*i + 1], "|"))
			att->write_to_pipe = 1;
		else if (!ft_strcmp(att->commands_arr[*i + 1], ">") || !ft_strcmp(att->commands_arr[*i + 1], ">>"))
		 	att->redir = 1;
		else if (!ft_strcmp(att->commands_arr[*i + 1], "<"))
		 	att->read_from_file= 1;
	}
	if (*i > 1 && is_symbol(att->commands_arr[*i - 1]))
	{
		if (!ft_strcmp(att->commands_arr[*i - 1], "|"))
			att->read_from_pipe = 1;
		if (!ft_strcmp(att->commands_arr[*i - 1], ">") || !ft_strcmp(att->commands_arr[*i - 1], ">>"))
		 	*i = *i + 1;
		else if (!ft_strcmp(att->commands_arr[*i - 1], "<") || !ft_strcmp(att->commands_arr[*i - 1], "<<"))
		 	*i = *i + 1;
	}
	return 0;
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
	t_attr att;
	char *str;

	rl_clear_history();
	set_signals();
	init_params(ac, av, &att, envp);
	while (1)
	{
		att.i = 0;
		str = prompt(&att);
		if (str == NULL)
		{
			rl_clear_history();
			break;
		}
		reinit_attributes(&att);
		if (str)
		{
			add_history(str);
			att.commands_arr = get_tokens2(str, &att);
			init_pipes(&att);
			while (att.commands_arr[att.i] && !verify_readline(str))
			{
				if (is_symbol(att.commands_arr[att.i]))
					att.i++;
				check_next_step(&att, &att.i);
				//if (is_symbol(att.commands_arr[att.i]))
				//	att.i++;
				/* printf("----------------------\n");
				printf("write to pipe: %d\n", att.write_to_pipe);
				printf("read from pipe: %d\n", att.read_from_pipe);
				printf("redir: %d\n", att.redir);
				printf("read from file: %d\n", att.read_from_file);
				printf("----------------------\n"); */
				att.tok_arr = get_tokens(att.commands_arr[att.i], &att);
				command(&att, att.i);
				if (att.read_from_pipe && !att.write_to_pipe)
					att.pipeindex++;
				free_tokens(att.tok_arr, &att);
				free(att.tok_arr);
				att.i++;
			}
			while (waitpid(-1, NULL, 0) > 0)
				continue;
			ft_delete_matrix(att.pipesfd);
			free_arr(att.commands_arr);
			free(str);
		}
	}
	free_g_env(&att);
	free_exp_env(&att);
	return (0);
}