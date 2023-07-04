/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:20:01 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	prints the string after echo command to the terminal
	with a new line at the end of the string
*/

int	echo(t_attr att)
{
	int	i;
	int	fl_n;
	int	fl_pr;

	i = 1;
	fl_n = 0;
	fl_pr = 0;
	while (i < att.nb_tokens && att.tok_arr[i])
	{
		if (handle_echo_options(att, &fl_n, &fl_pr, i))
		{
			i++;
			continue ;
		}
		if (fl_pr)
			printf(" ");
		printf("%s", att.tok_arr[i]);
		fl_pr = 1;
		i++;
		att.already_dealt = 1;
	}
	if (fl_n == 0)
		printf("\n");
	return (g_value);
}

/*
	checks if the string after echo command is an option
	-n = no new line at the end of the string
	$? = prints the exit status of the last command
*/

int	handle_echo_options(t_attr att, int *fl_n, int *fl_pr, int i)
{
	if (has_n(att.tok_arr[i], 'n') && att.already_dealt == 0)
	{
		*fl_n = 1;
		return (1);
	}
	else if (ft_strnstr(att.tok_arr[i], "-n", ft_strlen(att.tok_arr[i]))
		&& *fl_pr == 0)
	{
		echo_n(att);
		*fl_n = 1;
		return (1);
	}
	if (ft_strnstr(att.tok_arr[i], "$?", ft_strlen(att.tok_arr[i])))
	{
		printf("%d", g_value);
		return (g_value);
	}
	return (0);
}

/*
	prints the string after echo command to the terminal
	with the -n option = no new line at the end of the string
*/

int	echo_n(t_attr att)
{
	int	i;

	i = 1;
	if (ft_strcmp(att.tok_arr[i], "-n") != 0)
	{
		ft_putstr_fd(att.tok_arr[i], 1);
		i++;
	}
	return (0);
}

int	has_n(char *str, char n)
{
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen(str);
	if (str[i] && str[i] == '-')
	{
		i++;
		while (i < len)
		{
			if (str[i] == n)
				while (i < len && str[i] == n)
					i++;
			else
				return (0);
			if (i == len)
				break ;
			if (str[i] != n)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

/*int has_n(char *str, char n)
{
    int i = 0;
    int length = ft_strlen(str);

    if (length > 0 && str[i] == '-')
    {
        i++;
        if (i < length)
        {
            while (i < length)
            {
                if (str[i] == n)
                {
                    while (str[i] == n && i < length)
                        i++;
                }
                else if (str[i] != 0 && str[i] != n)
                    return (0);
                i++;
            }
            return (1);
        }
    }
    return (0);
}*/
