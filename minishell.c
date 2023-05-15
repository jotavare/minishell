#include "minishell.h"

int main(void)
{
    char *str;
    while (1)
    {
		// 
        str = readline("\033[0;32mminishell$\033[0m ");
        if (str == NULL)
            break;

        // Add the command to the history
        add_history(str);

        // Save the command history to a file
		write_history("minishell_history.txt");
        free(str);
    }
    return 0;
}
