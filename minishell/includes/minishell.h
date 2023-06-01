/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/31 21:14:09 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "macros.h"
# include "structs.h"

// source
char	*prompt(t_attr *att);
void	command(t_attr *att);
int		execute(t_attr *att);
char	**get_tokens(char *str, t_attr *attr);
void	ft_print_array(char **array, int nb);
void	create_array(char *s, t_attr *att);

// execute
int		execute(t_attr *att);
int		exec_commands(t_exec *args, t_attr *att);
int		exec_binaries(t_exec *args, t_attr *att);
int		exec_absolute_path(t_exec *args, t_attr *att);
char	**build_path(char **all_paths, int nb, char *command);
char	*get_str_paths(t_attr *att, char *path_str);
int		count_paths(char *s);

// init
void	init_params(int ac, char **av, t_attr *attr, char **envp);
void	init_attributes(t_attr *att); //27 maio alterado
void	init_paths(t_attr *att);
void	reinit_attributes(t_attr *att);

// start
void	start_env(char **envp, t_attr *my_env);
void	start_args(t_exec *args, t_attr *att);

// signals
void	handle_interrupt(int signal);
void	set_signals(void);

// commands
int		pwd(void);
void	cd(t_attr *att);
void	env(t_attr *att);

// exit
void	ft_exit(t_attr *att);
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
int		check_the_arr(char **search, char *str);
int     check_equal(char *str);

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

// pipes
int	pipework(t_attr *att);

//Redirects && Heredocs
void    count_dirdoc(t_attr *att);
void    heredocs(t_attr *att);
int     valid_dirdoc(t_attr *att);

#endif
