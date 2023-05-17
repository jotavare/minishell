/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/16 19:31:52 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int ac, char **av, char **envp)
{
    (void)ac;
	(void)av; 
	(void)envp;
	char	*str;
    t_attr  attr;

	str = av[1];

	rl_clear_history();
    // Load the command history from a file
    set_signals();
    //read_history("minishell_history.txt");
	while (1)
	{
		// Read the command from the user
        str = readline("\033[0;32mminishell$\033[0m ");
        if (str == NULL)
        {
			rl_clear_history();
            break;
        }
        // Add the command to the history
        add_history(str);
        
        attr.s_arr = get_tokens(str, &attr);
        
		command(str, attr);
        
        // Check if the comsmand is "exit"
        if (strcmp(str, "exit") == 0)
            break;
        
        // Save the command history to a file
        free(str);
	}
	return (0);
}