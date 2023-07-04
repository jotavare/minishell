/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:38:41 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/03 20:38:43 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	update_g_val_var(t_attr *att)
{
	char	*gval_str;

	gval_str = get_g_value();
	refresh_rmenv(att, check_the_arr(att->g_env, gval_str));
	refresh_addenv(att, gval_str);
	free(gval_str);
}

char	*get_g_value(void)
{
	char	*var_gvalue;
	char	*str_gvalue;

	str_gvalue = ft_itoa(g_value);
	var_gvalue = ft_strjoin("?=", str_gvalue);
	free(str_gvalue);
	return (var_gvalue);
}
