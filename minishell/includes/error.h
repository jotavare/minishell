/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/04 23:18:39 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "macros.h"

// error messages
# define ERROR_CD "Quack! cd: %s: No such file or directory\n"
# define ERROR_EXPORT "Quack! export: '%s': not a valid identifier\n"
# define ERROR_NLINE "Quack! syntax error near unexpected token 'newline'\n"
# define ERROR_SIMPLE_2 "Quack! parse error near '%c%c'\n"
# define ERROR_SIMPLE_1 "Quack! parse error near '%c'\n"
# define ERROR_PIPE2 "Quack! syntax error near unexpected token `||'\n"
# define ERROR_PIPE1 "Quack! syntax error near unexpected token `|'\n"
# define ERROR_TWO "Quack! syntax error near unexpected token `%c%c'\n"
# define ERROR_ONE "Quack! syntax error near unexpected token `%c'\n"
# define ERROR_UNCLOSED "Quack! syntax error unclosed quotes\n"

// error_1.c
int		error_last(char *str, char c);
int		error_simple(char *str, char c);
int		especialcase(char *str, int i);
int		especialcase_two(char *str, int i);

// error_2.c
int		error_pipes(char *str);
int		error_simple_dirdoc(char *str, char c);
int		error_single(char *str, char c);
int		error_double(char *str, char c);
int		error_mixed(char *str, char c, char r);

// error_3.c
int		error_dirdoc(char *str);
int		error_quotes(char *str);
int		verify_readline(char *str);
int		unclosed_quotes(char *str, t_err *error);

// error_4.c
int		print_error_pipe(char *str, int i);
int		error_onepipe(char *str);
int		print_mixed_error(char *str, char r, int i);
int		error_mixed(char *str, char c, char r);
int		start_args_error(t_attr *att, t_exec *args, int *g_value);

// error_5.c
int		vrl_skip_quotes(char *str, int i);

#endif