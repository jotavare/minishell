/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/16 22:00:34 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    free_tokens(char **tokens, t_attr   t)
{
    int i = 0;
    while (i < t.nb_tokens)
        free(tokens[i++]);
}

void    init_attributes(t_attr *att)
{
    att->nb_tokens = 0;
    att->index = 0;
    att->s_arr = NULL;
}

int     count_tokens(char *s, t_attr *att)
{
    int len;
    
    len = ft_strlen(s) - 1;
    while(len >= 0)
    {
        if (s[len] != ' ')
        {
            att->nb_tokens++;
            while (s[len] != ' ')
                len--;
        }
        if (s[len] == ' ')
            len--;
    }
    return(att->nb_tokens);
    
    
    
    if (!s)
        return(1);
    else
        att->nb_tokens++;
    while (s[att->index++] && (att->index < len))
    {
        if (s[att->index] == ' ')
            att->nb_tokens++;
    }
    return(0);
}

char    *get_token(char *s)
{
    char    *token;
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (s[j] != ' ' && s[j] != '\0')
        j++;
    token = malloc(sizeof(char) * j + 1);
    if (!token)
        return (NULL);
    token[j] = '\0';
    while(i < j)
    {
        token[i] = s[i];
        i++;
    }
    return (token);
}

char    **create_array(char *s, t_attr *att)
{
    int count;
    
    att->index = 0;
    att->s_arr = malloc((att->nb_tokens + 1) * sizeof(char *));
    att->s_arr[att->nb_tokens] = NULL;//valgrind
    if (!att->s_arr)
        return (0);
    count = 0;
    while (count < att->nb_tokens)
    {
        while (*s == ' ')
            s++;
        att->s_arr[count] = get_token(s);
        count++;
        while (*s != ' ' && *s != '\0')
            s++;
    }
    return(att->s_arr);
}

char    **get_tokens(char * str, t_attr *in_str)
{
    init_attributes(in_str);
    count_tokens(str, in_str); 
    create_array(str, in_str);
    //ft_print_array(in_str->s_arr, in_str->nb_tokens);
    return (in_str->s_arr);
}



/*This part is only for test purposes*/
// void	ft_print_array(char **array, int nb);

// int main(void)
// {
//     t_attr attr;
//     char    *str = "   cd    /source";
//     int    nb_tok = 1;
//     init_attributes(&attr);
//     char **tokens = get_tokens(str, &attr);
//     ft_print_array(tokens, attr.nb_tokens);
//     int i = 0;
//     while (i < nb_tok)
//         free(tokens[i++]);
//     free(tokens);
// }

// void	ft_print_array(char **array, int nb)
// {
// 	int i = 0;

// 	if (array == NULL)
// 		printf("Array is NULL\n");
// 	else
// 	{
// 		for(i = 0; i < nb; i++)
//         {
//         	printf("%d - %s\n", i, array[i]);
//         }
// 	}
// }