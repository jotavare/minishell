#include "minishell.h"

void handle_interrupt(int signal)
{
    if (signal == SIGINT)
    {
        printf("\n");           // Print a newline to start a new line after the prompt
        rl_replace_line("", 0); // Clear the current input line
        rl_on_new_line();       // Move to a new line
        rl_redisplay();         // Redisplay the prompt
    }
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    // Set up signal handlers
    signal(SIGINT, handle_interrupt);   // Handle Ctrl+C
    signal(SIGQUIT, SIG_IGN);           // Ignore Ctrl+"\"
    signal(SIGTSTP, SIG_IGN);           // Ignore Ctrl+Z

    // Load the command history from a file
    read_history("minishell_history.txt");

    char *str;
    char    **tokens;
    while (1)
    {
        // Read the command from the user
        str = readline("\033[0;32mminishell$\033[0m ");
        if (str == NULL)
        {
            break;
        }

        // Add the command to the history
        add_history(str);

        // Check if the command is "exit"
        if (strcmp(str, "exit") == 0)
            break;

        // Save the command history to a file
        write_history("minishell_history.txt");
        
        tokens = get_tokens(str);

        exec_comand(tokens);

        free(str);
    }

    return 0;
}