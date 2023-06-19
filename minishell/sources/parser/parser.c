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
	att->heredoc = 0;
	
	int previous = *i - 1;
	int next = *i + 1;

	if (att->commands_arr[next] && is_symbol(att->commands_arr[next]))
	{
		if (!ft_strcmp(att->commands_arr[next], "|"))
			att->write_to_pipe = 1;
		else if (!ft_strcmp(att->commands_arr[next], ">") || !ft_strcmp(att->commands_arr[next], ">>"))
		 	att->redir = 1;
		else if (!ft_strcmp(att->commands_arr[next], "<"))
		 	att->read_from_file = 1;
		else if (!ft_strcmp(att->commands_arr[next], "<<"))
			att->heredoc = 1;
	}
	if (*i > 1 && is_symbol(att->commands_arr[previous]))
	{
		if (!ft_strcmp(att->commands_arr[previous], "|"))
			att->read_from_pipe = 1;
		if (!ft_strcmp(att->commands_arr[previous], ">") || !ft_strcmp(att->commands_arr[previous], ">>"))
		 	*i = next;
		else if (!ft_strcmp(att->commands_arr[previous], "<")) 
		 	*i = next;
		else if( !ft_strcmp(att->commands_arr[previous], "<<"))
			*i = previous - 1;
	}
	return 0;
}

