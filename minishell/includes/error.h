/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/20 06:31:31 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "macros.h"

// error messages
# define ERROR_CD "minishell: cd: %s: No such file or directory\n"
# define ERROR_EXPORT "minishell: export: '%s': not a valid identifier\n"

// error_1.c
int	error_last(char *str, char c);
int	error_simple(char *str, char c);
int	especialcase(char *str, int i);
int	especialcase_two(char *str, int i);
int	error_onepipe(char *str);

// error_2.c
int	error_pipes(char *str);
int	error_simple_dirdoc(char *str, char c);
int	error_single(char *str, char c);
int	error_double(char *str, char c);
int	error_mixed(char *str, char c, char r);

// error_3.c
int	error_dirdoc(char *str);
int	double_quote(char *str, char c);
int	single_quote(char *str, char c);
int	error_quotes(char *str);
int	verify_readline(char *str);

#endif