/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/08 01:36:44 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "macros.h"

typedef struct s_attr
{
	char	**beforet;
	int		tok_arr_i;
	int		nb_tokenst;
	int		pipeindex;
	int		rediindex;
	int		appendindex;
	int		index;
	int		len_d_env;
	int		len_g_env;
	char	**tok_arr;
	char	**g_env;
	char	*last_path;
	char	**d_env;
	char	**exp_env;
	int		len_exp_env;
	char	**d_exp_env;
	int		len_d_exp_env;
	char	**commands_arr;
}			t_attr;

typedef struct s_exec
{
	int		i;
	int		nb_of_paths;
	char	*command;
	char	*path_srt;
	char	**all_paths;
	char	**path_command;
	char	curr_path[PATH_MAX];
	int		ret;
	pid_t	pid;
}			t_exec;

#endif