/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/04 22:12:14 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	verifydollar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

void	command(t_attr *att, int index)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (att->tok_arr[i])
	{
		if (verifydollar(att->tok_arr[i]))
			flag = 1;
		i++;
	}
	if (att->inside_single_quotes == 0 && flag == 1)
		expand_tokens(&att->tok_arr[0], att);
	if (!att->tok_arr[0])
		return ;
	if (ft_strcmp(att->tok_arr[0], "cd") == 0)
		g_value = cd(att);
	if (ft_strcmp(att->tok_arr[0], "unset") == 0)
		g_value = unset(att);
	if ((ft_strcmp(att->tok_arr[0], "exit") == 0))
		return (ft_exit(att));
	if (ft_strcmp(att->tok_arr[0], "export") == 0 && att->tok_arr[1])
		g_value = export(att);
	execute(att, index);
}
