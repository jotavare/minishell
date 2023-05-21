/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/18 17:39:110 by alexfern         ###   ########.fr       */
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

// defines
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
/*typedef struct  s_commands
{
    char    *pwd;
    char    *cd;
    char    *echo;
    char    *export;
    char    *unset;
    char    *env;
    char    *exit;
}		t_commands;
*/

/* typedef struct s_path
{
    char    *current_path;
    char    *last_path;
}		t_path;
 */

typedef struct s_attr
{
	int nb_tokens;   // number of tokens
	int index;       // index of the token
	char **tok_arr;  // array of tokens
	char **g_env;    // global environment
	int len_myenv;   // length of my_env
	char *last_path; // last path
    char   **d_env;
}		t_attr;

// source
void	command(const char *input, t_attr *att, char **envp);
char	**get_tokens(char *str, t_attr *attr);
void	free_tokens(char **tokens, t_attr t);
void	ft_print_array(char **array, int nb);

// signals
void	handle_interrupt(int signal);
void	set_signals(void);

// commands
int		pwd(void);
void	cd(t_attr *att);
void	echo(t_attr att);
void	ft_exit(const char *input, t_attr att);
void	env(char **envp, t_attr *my_env);
void	unset(t_attr *att);

// utilities
char	*trim_back(const char *input);
char	*white_sp_rm(const char *str);
int		ft_strcmp(const char *str1, const char *str2);
int		flag_counter(char *str, char c);
char	*dequoter(char *str);
void	start_env(char **envp, t_attr *my_env);
char	*trim_back(const char *input);
char	*white_sp_rm(const char *str);
int		ft_strcmp(const char *str1, const char *str2);
int		flag_counter(char *str, char c);
char	*dequoter(char *str);
void	init_attributes(t_attr *att);
void	init_paths(t_attr *att);

// export
void	export_count(char **envp, t_attr *att);
void	export_memory(t_attr *att);
void	export_copy(char **envp, t_attr *att);
void	export_sort(t_attr *att);
void	export_print(t_attr *att);
void	export(char **envp, t_attr *att);

// env
void	env(char **envp, t_attr *att);

// unset
char	*add_equal(char *str);
int		find_index(char **search, char *str);
void	free_g_env(t_attr *att);
void	refresh_rmenv(t_attr *att, int rm_index);
void	double_myenv(t_attr *att);

#endif
