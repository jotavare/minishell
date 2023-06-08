/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:51:22 by alexfern          #+#    #+#             */
/*   Updated: 2023/05/31 03:03:25 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
    prints the current working directory to the terminal
	'getcwd(pwd, PATH_MAX)' copy the entire path to pwd
	use 'getcwd(pwd, 0)' to allocate memory automatically
*/

int	pwd(void)
{
	char	pwd[PATH_MAX];

	if (getcwd(pwd, PATH_MAX) == NULL)
		return (EXIT_FAILURE);
	printf("%s\n", pwd);
	return (EXIT_SUCCESS);
	// if (getcwd(pwd, 0) == NULL)
	// 	return (EXIT_FAILURE);
}
