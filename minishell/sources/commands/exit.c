/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:19:41 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exit_print_err(const char *arg)
{
	printf("minishell: exit: %s: numeric argument required\n", arg);
	return (g_value = 2);
}

int	ft_exit_args(t_attr att)
{
	int			i;
	int			is_num;
	const char	*arg;

	i = 0;
	arg = att.tok_arr[1];
	is_num = 1;
	if (arg[0] == '#' || arg[0] == '-' || arg[0] == '+')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i++]))
		{
			is_num = 0;
			break ;
		}
	}
	if (is_num)
		g_value = ft_atoi(arg);
	else
		exit_print_err(arg);
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
