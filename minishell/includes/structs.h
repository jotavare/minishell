/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/21 15:09:12 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "macros.h"

typedef struct s_pars
{
	char	**pars_arr;
	int		nb_tokenst;
}			t_pars;

typedef struct s_attr
{
	int		i;
	char	**beforet;
	char	**aftert;
	int		o_dquotes;
	int		o_quotes;
	int		tok_arr_i;
	int		nb_tokens;
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
	int		write_to_pipe;
	int		read_from_pipe;
	int		read_from_file;
	int		redir;
	int		create_file;
	int		heredoc;
	int		skip;
	int		number_of_pipes;
	int		number_of_redir;
	int		number_of_append;
	int		**pipesfd;
	int		redir_fd;
	int		out_fd;
	t_pars	pars_data;
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