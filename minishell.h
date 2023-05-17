/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/16 22:14:07 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// includes
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <dirent.h>
# include <errno.h>

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
}   			t_commands;
*/

typedef struct  s_env
{
    char    *env_var;
    void    *next;
}       t_env;

typedef struct s_attr
{
    int     nb_tokens;
    int     index;
    char    **s_arr;
}       t_attr;

// functions
void 	command(const char *input, t_attr tok);
char    **get_tokens(char *str, t_attr *attr);
void    free_tokens(char **tokens, t_attr t);
void	ft_print_array(char **array, int nb);

// commands
int pwd();
void    cd(const char *input, t_attr att);
void	echo(const char *input);

// signals
void handle_interrupt(int signal);
void    set_signals(void);

// utilities
char	*trim_back(const char *input);
char    *white_sp_rm(const char *str);

#endif
