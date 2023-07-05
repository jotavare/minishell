/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:55:14 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "minishell.h"

// executer.c
void	check_flags(t_attr *att, int index, t_exec *args);
int		execute_core(t_attr *att, t_exec *args);
int		execute(t_attr *att, int index);
void	execute_builtin(t_attr *att, t_exec *args);
void	exit_child_status(void);

// execve.c
int		exec_commands(t_exec *args, t_attr *att);
int		exec_binaries(t_exec *args, t_attr *att);
int		exec_absolute_path(t_exec *args, t_attr *att);

// heredocs.c
void	heredoc(t_attr *att);
void	handle_heredoc(t_attr *att);

// paths.c
char	**build_path(char **all_paths, int nb, char *command);
int		count_paths(char *s);
char	*get_str_paths(t_attr *att, char *path_str);

// pipes.c
void	write_to_pipe(t_attr *att);
void	read_from_pipe(t_attr *att);
void	close_pipeline(t_attr *att);
void	init_pipes(t_attr *att);

// redirects.c
void	redir_append(t_attr *att, int index);
int		read_from_file(t_attr *att, int index);
void	create_file(t_attr *att);
void	file_create_only(t_attr *att);

#endif