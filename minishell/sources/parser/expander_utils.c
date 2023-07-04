/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:10:54 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:17:08 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	find_it(char *str, t_exp *info)
{
	info->full = 1;
	info->x = 0;
	info->len = 0;
	info->correct = NULL;
	if (!str)
		return ;
	while (str[info->x])
		find_it_aux1(str, info);
	info->x = 0;
	info->y = 0;
	if (info->len < 1)
	{
		info->var_name = str;
		return ;
	}
	info->correct = malloc(sizeof(char) * (info->len + 1));
	info->correct[info->len] = 0;
	info->x = 0;
	while (info->y < info->len)
		find_it_aux2(str, info);
	countj(str, info);
	info->var_name = info->correct;
}

void	find_it_aux1(char *str, t_exp *info)
{
	while (str[info->x] != '$' && str[info->x])
		info->x++;
	if (str[info->x] == '$' && str[info->x + 1])
	{
		info->x++;
		while (str[info->x] != ' ' && str[info->x] != '\'' && str[info->x])
		{
			info->x++;
			info->len++;
		}
	}
	if (str[info->x] != ' ' && str[info->x] != '\'' && str[info->x])
		info->x++;
}

void	find_it_aux2(char *str, t_exp *info)
{
	while (str[info->x] != '$' && str[info->x])
		info->x++;
	if (str[info->x] == '$' && str[info->x + 1])
	{
		info->x++;
		while (str[info->x] != ' ' && str[info->x] != '\'' && str[info->x])
		{
			info->correct[info->y] = str[info->x];
			info->x++;
			info->y++;
		}
	}
	info->x++;
}
