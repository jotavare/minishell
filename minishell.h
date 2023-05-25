/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/25 16:27:16 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// includes
# include "libft/libft.h"
# include <dirent.h>
# include <errno.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdbool.h>

// macros
# define PATH_MAX 4096

// colors
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define CYAN "\033[0;36m"
# define GREEN_BOLD "\033[1;32m"
# define RED_BOLD "\033[1;31m"
# define YELLOW_BOLD "\033[1;33m"
# define CYAN_BOLD "\033[1;36m"
# define RESET "\033[0m"

// structures
typedef struct s_attr
{
	int		nb_tokens;  // number of tokens
	int		index;      // index of the token
	int		len_d_env;  // length of d_env
	int		len_myenv;  // length of my_env
	char	**tok_arr;  // array of tokens
	char	**g_env;    // global environment
	char	*last_path; // last path
	char	**d_env;    // duplicate environment
}		t_attr;

typedef struct	s_exec
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
}		t_exec;

// source
void	command(t_attr *att);
int     execute(t_attr *att);
char	**get_tokens(char *str, t_attr *attr);
void	free_tokens(char **tokens, t_attr t);
void	ft_print_array(char **array, int nb);

// signals
void	handle_interrupt(int signal);
void	set_signals(void);

// commands
int		pwd(void);
void	cd(t_attr *att);
void	ft_exit(t_attr att);
void	env(t_attr *att);

// echo
void	echo(t_attr att);
void	echo_n(t_attr att);
void	echo_dollar(t_attr att);

// export
void	export(t_attr *att);
void	export_sort(t_attr *att);
void	export_print(t_attr *att);

// unset
void	unset(t_attr *att);
char	*add_equal(char *str);
int		find_index(char **search, char *str);
void	free_g_env(t_attr *att);
void	free_d_env(t_attr *att);
void	refresh_rmenv(t_attr *att, int rm_index);
void	double_myenv(t_attr *att);

// utilities
char	*trim_back(const char *input);
char	*white_sp_rm(const char *str);
char	*dequoter(char *str);
char	*trim_back(const char *input);
char	*white_sp_rm(const char *str);
char	*dequoter(char *str);
int		ft_strcmp(const char *str1, const char *str2);
int		flag_counter(char *str, char c);
int		ft_strcmp(const char *str1, const char *str2);
int		flag_counter(char *str, char c);
int		exit_two(t_attr att);
int     check_alpha(char *str);
void	start_env(char **envp, t_attr *my_env);
void	init_attributes(t_attr *att);
void	init_paths(t_attr *att);

// pipes
int	piprectise(int ac, char **av);

#endif
