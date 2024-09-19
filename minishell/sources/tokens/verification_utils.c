/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 22:42:08 by rpambo            #+#    #+#             */
/*   Updated: 2024/09/15 22:44:47 by rpambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*select_processing_strategy(int quotes, t_attr *att, char *s, t_toki tok)
{
	if (quotes >= 2)
		return (process_multi_quote(s, att, &tok));
	else
		return (process_default(s, att));
}
