#include "../../includes/minishell.h"

int is_symbol(char *s)
{
    char *symbols[] = {">", "<", ">>", "<<", "|" };
    int i;

    if (s[0] == '\0')
	{
        return 0;
    }

    i = 0;
    while (i < 5)
    {
        if (!ft_strcmp(s, symbols[i]))
            return 1;
        i++;
    }
    return 0;
}

int check_next_step(t_attr *att, int *i)
{
	att->write_to_pipe = 0;
	att->redir = 0;
	att->read_from_pipe = 0;
	att->read_from_file = 0;
	
	if (att->commands_arr[*i + 1] && is_symbol(att->commands_arr[*i + 1]))
	{
		if (!ft_strcmp(att->commands_arr[*i + 1], "|"))
			att->write_to_pipe = 1;
		else if (!ft_strcmp(att->commands_arr[*i + 1], ">") || !ft_strcmp(att->commands_arr[*i + 1], ">>"))
		 	att->redir = 1;
		else if (!ft_strcmp(att->commands_arr[*i + 1], "<"))
		 	att->read_from_file= 1;
	}
	if (*i > 1 && is_symbol(att->commands_arr[*i - 1]))
	{
		if (!ft_strcmp(att->commands_arr[*i - 1], "|"))
			att->read_from_pipe = 1;
		if (!ft_strcmp(att->commands_arr[*i - 1], ">") || !ft_strcmp(att->commands_arr[*i - 1], ">>"))
		 	*i = *i + 1;
		else if (!ft_strcmp(att->commands_arr[*i - 1], "<") || !ft_strcmp(att->commands_arr[*i - 1], "<<"))
		 	*i = *i + 1;
	}
	return 0;
}