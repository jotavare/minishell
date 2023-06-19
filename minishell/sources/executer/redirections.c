#include "../../includes/minishell.h"

void    write_to_pipe(t_attr *att)
{
	if (att->pipeindex >= att->number_of_pipes)
		return ;
	close(att->pipesfd[att->pipeindex][0]);
    if (dup2(att->pipesfd[att->pipeindex][WRITE_END], STDOUT_FILENO) < 0)
		perror("dup2 :[WRITE_END] ");
	close(att->pipesfd[att->pipeindex][1]);
	
}

void    read_from_pipe(t_attr *att)
{
	close(att->pipesfd[att->pipeindex][1]);
    if (dup2(att->pipesfd[att->pipeindex][READ_END], STDIN_FILENO) < 0)
		perror("dup2 [READ_END]: ");
	close(att->pipesfd[att->pipeindex][0]);
}

void	redir_append(t_attr *att, int index)
{
	char	*file_name;
	
	file_name = ft_strtrim(att->commands_arr[index + 2], " ");	

	if (strcmp(att->commands_arr[index + 1], ">") == 0)
	{
		att->redir_fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		free(file_name);
		dup2(att->redir_fd, STDOUT_FILENO);
		close(att->redir_fd);
		att->redir = 0;
		att->number_of_redir--;

	}
	else if (strcmp(att->commands_arr[index + 1], ">>") == 0)
	{
		att->redir_fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
		dup2(att->redir_fd, STDOUT_FILENO);
		close(att->redir_fd);
		att->redir = 0;
	}
}

void	read_from_file(t_attr *att, int index)
{
        char	*file_name;
		int		filefd;

		file_name = ft_strtrim(att->commands_arr[index + 2], " ");
		if ((filefd = open(file_name, O_RDONLY)) < 0)
			perror("Minishell");
		free(file_name);
        dup2(filefd, 0);
		close(filefd);
		att->read_from_file = 0;
}