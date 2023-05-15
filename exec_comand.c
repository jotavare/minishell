#include "minishell.h"
/*WORKING HERE - MUST UNDERSTAND HOW TO MAKE EXECVE WORKS*/
void exec_comand(char **tok)
{
    int pid;
    int exe;
    tok[0] = strcat("/bin/", tok[0]);

    pid = fork();
    if (pid == -1)
        exit(1);
    
    if (pid == 0)
    {
        exe = execve(tok[0], tok, NULL);
        if (exe == -1)
            perror("Error executing command");
    }
    else
    {
        wait (NULL);
    }
}