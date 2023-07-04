/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:38:30 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:25:06 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
    get the current user and pwd variables at g_env
    and print a custom prompt.
*/

char	*prompt(t_attr *att)
{
	char	*str;
	char	*user;
	char	*pwd;

	user = custom_getenv("USER", att);
	pwd = custom_getenv("PWD", att);
	if (pwd != NULL && user != NULL)
	{
		printf("┏━" GREEN_BOLD " %s@:" GREEN_BOLD, user);
		printf(CYAN_BOLD "%s\n" CYAN_BOLD, pwd);
	}
	str = readline(RESET "┗━" RESET" miniSHELL🦆" RESET " " RESET "");
	return (str);
}
