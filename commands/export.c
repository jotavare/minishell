/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/21 14:16:27 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
    main function of the export command
*/
void export(char **envp, t_attr *att)
{
    export_count(envp, att);
    export_memory(att);
    export_copy(envp, att);
    export_sort(att);
    export_print(att);
}

/*
    counts the number of elements in the environment
*/
void export_count(char **envp, t_attr *att)
{
    int count = 0;
    while (envp[count])
    {
        count++;
    }
    att->len_myenv = count;
}

/*
    allocates memory for the environment in the structure t_attr *att
*/
void export_memory(t_attr *att)
{
    att->g_env = malloc(sizeof(char *) * (att->len_myenv + 1));
    if (!att->g_env)
        return;
}

/*
    copies the environment to the allocated memory space
*/
void export_copy(char **envp, t_attr *att)
{
    int i = 0;
    while (envp[i])
    {
        att->g_env[i] = strdup(envp[i]);
        i++;
    }
    att->g_env[i] = NULL;
}

/*
    sorts the environment alphabetically using bubble sort algorithm
*/
void export_sort(t_attr *att)
{
    int sorted = 0;
    while (!sorted)
    {
        sorted = 1;
        int i = 0;
        while (att->g_env[i + 1] != NULL)
        {
            if (strcmp(att->g_env[i], att->g_env[i + 1]) > 0)
            {
                char *temp = att->g_env[i];
                att->g_env[i] = att->g_env[i + 1];
                att->g_env[i + 1] = temp;
                sorted = 0;
            }
            i++;
        }
    }
}

/*
    prints the environment in the format required by the subject of the project
*/
void export_print(t_attr *att)
{
    int i = 0;
    while (att->g_env[i])
    {
        printf("declare -x %s\n", att->g_env[i]);
        i++;
    }
    printf("SIZE: %d\n", att->len_myenv);
}
