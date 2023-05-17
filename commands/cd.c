/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/16 22:35:13 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
    change directory to path given in input string
    > format: "cd <path>"
    > status: not working
*/

void cd(const char *input, t_attr attr)
{
    char *current_path;
    char *destiny_path;

    (void)input;
    destiny_path = attr.s_arr[1];
    if (!destiny_path)
        destiny_path = "/home/joaoalme"; //IDEA: here we must define a variable in the header file 
    current_path = getcwd(NULL, 0);
    if (!current_path)
        return;

    printf("%s\n", current_path);

    if (chdir(destiny_path)) // Change directory to path given in input
        printf("Failed to change directory.\n");
    else
        printf("Directory changed to: %s\n", getcwd(NULL, 0));
    free(current_path);
}
