/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/06/20 05:47:58 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_last_return_value;

int error_last(char *str, char c)
{
    int len;

    len = ft_strlen(str);
    if (str[len - 1] == c)
    {   
        if (c != '|')
            printf("bash: syntax error near unexpected token 'newline'\n");
        return (1);
    }
    return (0);
}

int error_simple(char *str, char c)
{
    if (str[0] == c && str[1] == c)
    {
        printf("bash: parse error near 'simp%c%c'\n", str[0], str[1]);
        return (1);
    }
    else if (str[0] == c)
    {
        printf("bash: syntax error near unexpected token '%c'\n", str[0]);
        return (1);
    }
    return (0);
}

int especialcase(char *str, int i)
{
    if (str[i] == '>' && str[i + 1] == '|' && str[i + 2] == '\0' && str[i - 1] != '>')
    {
        printf("bash: syntax error near unexpected token 'newline'\n");
        return (1);
    }
    else if (str[i] == '<' && str[i + 1] == '|')
    while ((i + 2) < (int)ft_strlen(str))
    {
        if (str[i + 2] != ' ' && str[i + 2] != '\t')
            return (0);
        i++;
    }
    return (0);
}

int especialcase_two(char *str, int i)
{
    char    c;

    c = str[i];
    if (str[i - 1] == c && str[i] == c && str[i + 1] == '|' && str[i + 2] == '|')
    {
        printf("bash: syntax error near unexpected token '||'\n");
        return (1);
    }
    else if (str [i - 1] == c && str[i] == c && str[i + 1] == '|')
    {
        printf("bash: syntax error near unexpected token '|'\n");
        return (1);
    }
    return (0);
}

int error_onepipe(char *str)
{
    int i;
    int flag;

    flag = 0;    
    i = 0;
    while(str[i])
    {
        if (str[i] == '"')
            break ;
        if ((str[i] == '>' || str[i] == '<') && str[i + 1] == '|')
        {
            if (especialcase(str, i) || especialcase_two(str, i))
                return (1);
            else
                return (0);
        }
        else if ((str[i] == '|' || str[i] == '>' || str[i] == '<') && flag == 0)
            flag = 1;
        else if ((str[i] != '|' && str[i] != ' ') && flag == 1)
            flag = 0;
        else if (str[i] == '|' && flag == 1)
        {
            if (str[i] =='|' && str[i + 1] == '|')
                printf("bash: syntax error near unexpected token '||'\n");
            else
                printf("bash: syntax error near unexpected token '|'\n");
            return (1);
        }
        i++;
    }
    return (0);
}

int error_pipes(char *str)
{
    if (error_simple(str, '|'))
        return (1);
    /*if (error_twopipe(str)) //removed, we dont need this function
        return (1); */
    if (error_onepipe(str))
        return (1);
    if (error_last(str, '|'))
        return (0);
    return (0);
}


int error_simple_dirdoc(char *str, char c)
{
    if (str[0] == c && (str[1] == c || str[1] == '\0') && str[2] == '\0')
    {
        printf("bash: syntax error near unexpected token 'newline'\n");
        return (1);
    }
    return (0);
}

int error_single(char *str, char c)
{
    int i;
    int flag;

    i = 0;
    flag = 0;
    while(str[i])
    {
        if (str[i] == c && str[i + 1] == c && flag == 0)
            return (0);
        if (str[i] == c && flag == 0)
            flag = 1;
        else if (str[i] != c && str[i] != ' ' && flag == 1)
            flag = 0;
        else if (str[i] == c && flag == 1)
        {
            if (str[i] == c && str[i + 1] == c)
                printf("bash: syntax error near unexpected token '%c%c'\n", c, c);
            else
                printf("bash: syntax error near unexpected token '%c'\n", c);
            return (1);
        }
        i++;
    }
    return (0);
}

int error_double(char *str, char c)
{
    int i;
    int flag;

    i = 0;
    flag = 0;
    while(str[i])
    {
        if (str[i] == c && str[i + 1] == c && flag == 0)
            flag = 1;
        else if (str[i] != c && str[i] != ' ' && flag)
            flag = 0;
        else if (str[i] == c && flag == 1)
            flag = 2;
        else if (((str[i] == c && str[i + 1] == c) || str[i] == c) && flag == 2)
        {
            if (str[i] ==  c && str[i + 1] == c)
                printf("bash: syntax error near unexpected token'%c%c'\n", c, c);
            else
                printf("bash: syntax error near unexpected token '%c'\n", c);
            return (1);
        }
        i++;
    }
    return (0);
}

int error_mixed(char *str, char c, char r)
{
    int i;
    int flag;

    i = 0;
    flag = 0;
    while (str[i])
    {
        if (str[i] == '>' && str[i + 1] == '|')
            return (0);
        else if (str[i] == '<' && str[i + 1] == '>' && flag == 0)
            return (0);
        else if (str[i] == c && flag == 0)
            flag = 1;
        else if (str[i] == c && flag == 1)
            flag = 2;
        else if ((str[i] != c && str[i] != ' ' && str[i] != r) && (flag == 1 || flag == 2))
            flag = 0;
        else if (str[i] == r && (flag == 1 || flag == 2))
        {
            if (str[i] == r && str[i + 1] == r)
                printf("bash: syntax error near unexpected token '%c%c'\n", r, r);
            else
                printf("bash: syntax error near unexpected token '%c'\n", r);
            return (1);
        }
        i++;
    }
    return (0);
}

int error_dirdoc(char *str)
{
    if (error_simple_dirdoc(str, '>') || error_simple_dirdoc(str, '<'))
        return (1);
    else if (error_mixed(str, '>', '<') || error_mixed(str, '<', '>') || error_mixed(str, '<', '|') 
        || error_mixed(str, '>', '|'))
        return (1);
    else if (error_double(str, '>') || error_double(str, '<'))
        return (1);
    else if (error_single(str, '>') || error_single(str, '<'))
        return (1);
    else if (error_last(str, '>') || error_last(str, '<'))
        return (1);
    return (0);
}

int double_quote(char *str, char c)
{
    int i;
    int flag;

    flag = 0;
    i = 0;
    while(str[i])
    {
        if (str[i] == c && flag == 0)
            flag = 1;
        else if (str[i] == '\'' && flag == 1)
            flag = 2;
        else if (str[i] == '\'' && flag == 2)
            flag = 1;
        else if (str[i] == c && flag == 1)
            flag = 0;
        i++;
    }
    if (flag)
    {
        printf("bash : syntax error unclosed quotes\n");
        return (1);
    }
    return (0);
}

int single_quote(char *str, char c)
{
    int i;
    int flag;

    flag = 0;
    i = 0;
    while(str[i])
    {
        if (str[i] == c && flag == 0)
            flag = 1;
        else if (str[i] == '\"' && flag == 1)
            flag = 2;
        else if (str[i] == '\"' && flag == 2)
            flag = 1;
        else if (str[i] == c && flag == 1)
            flag = 0;
        i++;
    }
    if (flag)
    {
        printf("bash : syntax error unclosed quotes\n");
        return (1);
    }
    return (0);
}

int error_quotes(char *str)
{
    if (double_quote(str, '\"') || single_quote(str, '\''))
        return (1);
    return (0);
}

int verify_readline(char *str)
{
    if (error_pipes(str))
    {
        g_last_return_value = 2;
        return (1);
    }
    else if (error_dirdoc(str))
    {
        g_last_return_value = 2;
        return (1);
    }
    else if (error_quotes(str))
    {
        g_last_return_value = 2;
        return(1);
    }
    return (0);
}
