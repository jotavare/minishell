/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/16 02:19:32 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "macros.h"
# include "structs.h"

// [COMMANDS]
// cd.c
char	*search_var_in_g_env(t_attr *att, char *s);
void	cd_rm_add_path(t_attr *att, char *to_remove, char *s);
void	cd(t_attr *att);

// echo.c
void	echo(t_attr att);
void	echo_n(t_attr att);
void	echo_doll_ques(t_attr att);

// env.c
void	env(t_attr *att);

// exit.c
int		exit_two(t_attr attr);
void	ft_exit(t_attr *attr);

// export.c
int		check_equal(char *str);
void	refresh_addenv(t_attr *att, char *add);
void	refresh_add_exp(t_attr *att, char *add);
int		check_the_arr(char **search, char *str);
void	export(t_attr *att);
void	export_sort(t_attr att);
void	add_quotes(char *s);
void	export_print(t_attr att);

// pwd.c
int		pwd(void);

// unset.c
char	*add_equal(char *str);
int		find_index(char **search, char *str);
void	double_myenv(t_attr *att);
void	double_exp_env(t_attr *att);
void	refresh_rmenv(t_attr *att, int rm_index);
void	refresh_rmexp_env(t_attr *att, int rm_index);
void	unset(t_attr *att);

// [EXECUTER]
// executer.c
char	**build_path(char **all_paths, int nb, char *command);
int		count_paths(char *s);
char	*get_str_paths(t_attr *att, char *path_str);
int		exec_commands(t_exec *args, t_attr *att);
int		exec_binaries(t_exec *args, t_attr *att);
int		exec_absolute_path(t_exec *args, t_attr *att);
void	execute_core(t_attr *att, t_exec *args);
int     execute(t_attr *att,int index);

// pipes.c
int		execute_pipeline(t_attr *att, int index);
void	pipe_in(t_attr *att, int index);
void	pipe_out(t_attr *att, int index);
void	close_pipeline(t_attr *att, int index);
void	init_pipes(t_attr *att);

// [INITIALIZE]
// init.c
void    init_params(int ac, char **av, t_attr *attr, char **envp);
void	init_attributes(t_attr *att);
void	init_paths(t_attr *att);
int		count_commands(char *s);
void	reinit_attributes(t_attr *att);

// start.c
void	start_args(t_exec *args, t_attr *att);
void	start_env(char **envp, t_attr *att);
void	start_exp(char **envp, t_attr *att);

// [PARSER]
// expander.c
char	**expand_tokens(char **tokens, t_attr *att);
char	*custom_getenv(const char *variable_name, t_attr *att);

// lexer.c
void	command(t_attr *att, int index);

// redirect.c
void	redir_append(t_attr *att, int index);

// [SANITIZE]
// free.c
void	free_arr(char **arr);
void	free_tokens(char **tokens, t_attr *t);
void	free_g_env(t_attr *att);
void	free_d_env(t_attr *att);
void	free_exp_env(t_attr *att);
void	free_d_exp_env(t_attr *att);
void	exit_free(t_attr *attr);
void	ft_delete_matrix(void *matrix);

// signals.c
void	handle_interrupt(int signal);
void	set_signals(void);

// [TOKENS]
// count_tokens.c
int		count_tokens(char *s, t_attr *att);
int		check_single_quotes(char *s, int len, t_attr *att);
int		check_double_quotes(char *s, int len, t_attr *att);
int		check_non_space_char(char *s, int len, t_attr *att);
int		check_special_char(char *s, int len, t_attr *att);

// get_tokens.c
char	*get_token(char *s, t_attr *att);
char	*process_token_two(char *s, t_attr *att);
char	*process_token_three(char *s, t_attr *att);
char	*process_multi_quote(char *s, t_attr *att);
char	*process_default(char *s, t_attr *att);

// get_tokens2.c
int		count_tokens2(char *s, t_attr *att);
char	*get_token2(char *s, t_attr *att);
void	create_array2(char *s, t_attr *att);
char	**get_tokens2(char *str, t_attr *att);

// tokens.c
void	create_array(char *s, t_attr *att);
char	**get_tokens(char *str, t_attr *att);

// [UTILITIES]
// prompt.c
char	*prompt(t_attr *att);

// utilities.c
int     check_alpha(char *str);
int		flag_counter(char *str, char c);
int		ft_strcmp(const char *str1, const char *str2);
char	*trim_back(const char *input);
char	*white_sp_rm(const char *str);
char	*ft_strcpy(char *destination, const char *source);
int		is_symbol(char *s);
int		check_next_step(t_attr *att, int *i);

#endif
