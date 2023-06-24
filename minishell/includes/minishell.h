/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/24 01:44:44 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "structs.h"
# include "macros.h"
# include "inicialize.h"
# include "executer.h"
# include "commands.h"
# include "error.h"

extern int	g_value;

// source
char		*prompt(t_attr *att);
void		command(t_attr *att, int index);

// check
int			check_the_arr(char **search, char *str);
int			check_the_arr_without_equal(char **search, char *str);
int			check_the_arr_with_equal(char **search, char *to_find, int length);
int			check_equal(char *str);

// signals
void		handle_interrupt(int signal);
void		set_signals(void);

// utilities
char		*trim_back(const char *input);
char		*white_sp_rm(const char *str);
char		*dequoter(char *str);
char		*trim_back(const char *input);
char		*white_sp_rm(const char *str);
char		*dequoter(char *str);
char		*ft_strcpy(char *destination, const char *source);
int			ft_strcmp(const char *str1, const char *str2);
int			flag_counter(char *str, char c);
int			ft_strcmp(const char *str1, const char *str2);
int			flag_counter(char *str, char c);
int			check_alpha(char *str);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strncpy(char *dest, const char *src, size_t n);

// expander
char		**expand_tokens(char **tokens, t_attr *att);
char		*expand_token(const char *token, t_attr *att);
char		*custom_getenv(const char *variable_name, t_attr *att);

// free
void		free_g_env(t_attr *att);
void		free_d_env(t_attr *att);
void		free_exp_env(t_attr *att);
void		free_d_exp_env(t_attr *att);
void		free_tokens(char **tokens, t_attr *t);
void		free_arr(char **arr);
void		exit_free(t_attr *attr);
void		free_start_args(t_exec *args);
void		ft_delete_matrix(void *matrix);

// parser
int			check_next_step(t_attr *att);
int			is_symbol(char *s);

// tokens
char		**get_tokens(char *str, t_attr *att);
char		**get_tokens2(char *str, t_attr *att);
void		create_array(char *s, t_attr *att);
void		null_token_handle(t_attr *att);
char		*quotentoken(char *s, t_attr *att, int flag, int pos);

// count_tokens
int			count_tokens(char *s, t_attr *att);
int			check_single_quotes(char *s, int len, t_attr *att);
int			check_double_quotes(char *s, int len, t_attr *att);
int			check_non_space_char(char *s, int len, t_attr *att);
int			check_special_char(char *s, int len, t_attr *att);

// get_tokens
char		*get_token(char *s, t_attr *att);
char		*process_token_two(char *s, t_attr *att);
char		*process_token_three(char *s, t_attr *att);
char		*process_multi_quote(char *s, t_attr *att);
char		*process_default(char *s, t_attr *att);

// debugging
void		ft_print_array(char **array);
void		see_flags_and_pipes(t_attr att);

// check readline validation
int			verify_readline(char *str);

#endif