/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/06/23 22:32:54 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_value;

int	ft_exit_args(t_attr attr)
{
	int			i;
	int			is_num;
	const char	*arg;

	i = 0;
	arg = attr.tok_arr[1];
	is_num = 1;

	if (arg[i] == '-')
		i++;
	
	while (arg[i])
	{
		if (!isdigit(arg[i++]))
		{
			is_num = 0;
			break ;
		}
	}
	if (is_num)
		g_value = ft_atoi(arg);
	else
	{
		printf("minishell: exit: %s: numeric argument required\n", arg);
		g_value = 2;
	}
	return (g_value);
}

void	ft_exit(t_attr *att)
{
	g_value = 0;
	printf("exit\n");
	if (att->nb_tokens == 1)
		g_value = 0;
	else if (att->nb_tokens == 2)
		g_value = ft_exit_args(*att);
	else
	{
		if (ft_isdigit(att->tok_arr[1][0]))
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			g_value = 1;
			return ;
		}
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		g_value = 1;
	}
	
	exit_free(att);
	exit(g_value);
}
