/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/21 19:13:15 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "macros.h"
# include "structs.h"
# include "error.h"

// source
char	*prompt(t_attr *att);
void	command(t_attr *att, int index);

// execute
int		execute(t_attr *att, int index);
int		exec_commands(t_exec *args, t_attr *att);
int		exec_binaries(t_exec *args, t_attr *att);
int		exec_absolute_path(t_exec *args, t_attr *att);
int		read_from_file(t_attr *att, int index);
int		count_paths(char *s);
int		execute_write_p(t_attr *att, int index);
int		execute_read_p(t_attr *att, int index);
int		execute_pipeline(t_attr *att, int index);
char	**build_path(char **all_paths, int nb, char *command);
char	*get_str_paths(t_attr *att, char *path_str);
void	redir_append(t_attr *att, int index);

// check
int		check_the_arr(char **search, char *str);
int		check_the_arr_without_equal(char **search, char *str);
int		check_the_arr_with_equal(char **search, char *to_find, int length);
int		check_equal(char *str);

// init
void	init_params(int ac, char **av, t_attr *attr, char **envp);
void	init_attributes(t_attr *att);
void	init_paths(t_attr *att);
void	reinit_attributes(t_attr *att);

// refresh
void	add_quotes(char *s);
void	refresh_addenv(t_attr *att, char *add);
void	refresh_add_exp(t_attr *att, char *add);

// start
void	start_env(char **envp, t_attr *my_env);
void	start_args(t_exec *args, t_attr *att);

// signals
void	handle_interrupt(int signal);
void	set_signals(void);

// commands
int		pwd(void);
void	env(t_attr *att);

// cd
void	cd(t_attr *att);
void	update_oldpwd(t_attr *att, const char *current_path);
void	update_pwd(t_attr *att);

// exit
void	ft_exit(t_attr *attr);
int		exit_two(t_attr att);

// echo
void	echo(t_attr att);
void	echo_n(t_attr att);

// unset
void	unset(t_attr *att);
void	refresh_rmenv(t_attr *att, int rm_index);
void	double_myenv(t_attr *att);
void	refresh_rmexp_env(t_attr *att, int rm_index);
char	*add_equal(char *str);
int		find_index(char **search, char *str);

// export
void	export(t_attr *att);
void	export_sort(t_attr att);
void	export_print(t_attr att);
void	double_exp_env(t_attr *att);
void	start_exp(char **envp, t_attr *att);
void	refresh_addenv(t_attr *att, char *add);
void	refresh_add_exp(t_attr *att, char *add);
char	*search_var_in_g_env(t_attr *att, char *s);
void	export_check_equal(t_attr *att, int j);
void	export_not_equal(t_attr *att, int j);

// utilities
char	*trim_back(const char *input);
char	*white_sp_rm(const char *str);
char	*dequoter(char *str);
char	*trim_back(const char *input);
char	*white_sp_rm(const char *str);
char	*dequoter(char *str);
char	*ft_strcpy(char *destination, const char *source);
int		ft_strcmp(const char *str1, const char *str2);
int		flag_counter(char *str, char c);
int		ft_strcmp(const char *str1, const char *str2);
int		flag_counter(char *str, char c);
int		check_alpha(char *str);

// expander
char	**expand_tokens(char **tokens, t_attr *att);
char	*custom_getenv(const char *variable_name, t_attr *att);

// free
void	free_g_env(t_attr *att);
void	free_d_env(t_attr *att);
void	free_exp_env(t_attr *att);
void	free_d_exp_env(t_attr *att);
void	free_tokens(char **tokens, t_attr *t);
void	free_arr(char **arr);
void	exit_free(t_attr *attr);
void free_start_args(t_exec *args);

// pipes
int		pipework(t_attr *att);
void	init_pipes(t_attr *att);
void	ft_delete_matrix(void *matrix);
void	write_to_pipe(t_attr *att);
void	read_from_pipe(t_attr *att);
void	close_pipeline(t_attr *att);
void	heredoc(char *delimiter, t_attr *att);
void	create_file(t_attr *att);

//parser
int		check_next_step(t_attr *att);
int		is_symbol(char *s);

// tokens
char	**get_tokens(char *str, t_attr *att);
char	**get_tokens2(char *str, t_attr *att);
void	create_array(char *s, t_attr *att);
char	*double_quotes_treat(char *s, t_attr *att);
void	null_token_handle(t_attr *att);

// count_tokens
int		count_tokens(char *s, t_attr *att);
int		check_single_quotes(char *s, int len, t_attr *att);
int		check_double_quotes(char *s, int len, t_attr *att);
int		check_non_space_char(char *s, int len, t_attr *att);
int		check_special_char(char *s, int len, t_attr *att);

// get_tokens
char	*get_token(char *s, t_attr *att);
char	*process_token_two(char *s, t_attr *att);
char	*process_token_three(char *s, t_attr *att);
char	*process_multi_quote(char *s, t_attr *att);
char	*process_default(char *s, t_attr *att);

// debugging
void	print_t_attr(t_attr *att);
void	ft_print_array(char **array);
void	see_flags_and_pipes(t_attr att);

// check readline validation
int		verify_readline(char *str);

#endif
