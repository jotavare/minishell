/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/04 23:18:08 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		g_value = 0;

int	main(int ac, char **av, char **envp)
{
	t_attr	att;
	t_toki	tok;
	char	*str;

	void_params(ac, av);
	first_step(envp, &att, &tok);
	while (1)
	{
		att.i = 0;
		str = prompt(&att);
		if (str_empty(str))
			break ;
		reinit_attributes(&att);
		if (str)
		{
			if (verify_readline(str) == 0)
				str_is_true(str, &att, &tok);
		}
	}
	free_g_env(&att);
	free_exp_env(&att);
	return (0);
}
