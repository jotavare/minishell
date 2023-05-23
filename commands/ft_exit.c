/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/22 11:27:13 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exit_two(t_attr attr)
{
	int			return_value;
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
		return_value = ft_atoi(arg);
	else
	{
		printf("minishell: exit: %s: numeric argument required\n", arg);
		return_value = 2;
	}
	return (return_value);
}

void	ft_exit(t_attr attr)
{
	int			return_value;

	return_value = 0;
	printf("exit\n");
	if (attr.nb_tokens == 1)
		return_value = 0;
	else if (attr.nb_tokens == 2)
		return_value = exit_two(attr);
	else
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return_value = 1;
	}
	printf("Exiting minishell with code %d\n", return_value);
	exit(return_value);
}
