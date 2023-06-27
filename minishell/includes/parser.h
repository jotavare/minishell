/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/24 02:02:52 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

// check.c
int		check_the_arr(char **search, char *str);
int		check_the_arr_without_equal(char **search, char *str);
int		check_the_arr_with_equal(char **search, char *to_find, int length);
int		check_equal(char *str);

// expander.c
char	*custom_getenv(const char *variable_name, t_attr *att);
char	**expand_tokens(char **tokens, t_attr *att);
char	*has_correct_name(char *str);

// lexer.c
void	command(t_attr *att, int index);

// parser.c
int		is_symbol(char *s);
int		check_next_step(t_attr *att);

// signals.c
void	handle_quit(int signal);
void	handle_interrupt(int signal);
void	set_signals(void);
void	handler_exec(int sig);

#endif