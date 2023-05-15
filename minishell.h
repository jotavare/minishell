#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_attr
{
    int     nb_tokens;
    int     index;
    char    **s_arr;

}       t_attr;

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

char    **get_tokens(char *str);
void    free_tokens(char **tokens, t_attr   t);

#endif