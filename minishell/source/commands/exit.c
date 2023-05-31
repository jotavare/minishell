/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/31 03:03:17 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_last_return_value;

int	exit_two(t_attr attr)
{
	int			i;
	int			is_num;
	const char	*arg;

	i = 0;
	arg = attr.tok_arr[1];
	is_num = 1;
	while (arg[i])
	{
		if (!isdigit(arg[i++]))
		{
			is_num = 0;
			break ;
		}
	}
	if (is_num)
		g_last_return_value = ft_atoi(arg);
	else
	{
		printf("minishell: exit: %s: numeric argument required\n", arg);
		g_last_return_value = 2;
	}
	return (g_last_return_value);
}

void	ft_exit(t_attr *attr)
{
	free_g_env(attr);
	free_exp_env(attr);
	g_last_return_value = 0;
	printf("exit\n");
	if (attr->nb_tokens == 1)
		g_last_return_value = 0;
	else if (attr->nb_tokens == 2)
		g_last_return_value = exit_two(*attr);
	else
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		g_last_return_value = 1;
	}
	exit_free(attr);
	printf("Exiting minishell with code %d\n", g_last_return_value);
	exit(g_last_return_value);
}
