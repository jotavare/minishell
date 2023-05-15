#include "minishell.h"

void	ft_print_array(char **array, int nb);

void    init_attributes(t_attr *att)
{
    att->nb_tokens = 0;
    att->index = 0;
    att->s_arr = NULL;
}
int     count_tokens(char *s, t_attr *att)
{

    if (!s)
        return(1);
    else
        att->nb_tokens++;
    while (s[att->index++])
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
    //i = j;
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
    att->s_arr[att->nb_tokens + 1] = NULL;
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

char    **get_tokens(char * str)
{
    t_attr  in_str;
    
    init_attributes(&in_str);
    count_tokens(str, &in_str); 
    create_array(str, &in_str);
    ft_print_array(in_str.s_arr, in_str.nb_tokens);
    return (in_str.s_arr);
}

void    free_tokens(char **tokens, t_attr   t)
{
    int i = 0;
    while (i < t.nb_tokens)
        free(tokens[i++]);
}

/*This part is only for test purposes*/
// void	ft_print_array(char **array, int nb);

// int main(void)
// {
//     char    *str = "ls -l | grep txt test | lala";
//     int    nb_tok = 1;
//     char **tokens = get_tokens(str);
//     while (*str++)
//     {
//         if (*str == ' ')
//             nb_tok++;
//     }
//     ft_print_array(tokens, nb_tok);
//     int i = 0;
//     while (i < nb_tok)
//         free(tokens[i++]);
//     free(tokens);
// }

void	ft_print_array(char **array, int nb)
{
	int i = 0;

	if (array == NULL)
		printf("Array is NULL\n");
	else
	{
		for(i = 0; i < nb + 1; i++)
        {
        	printf("%d - %s\n", i, array[i]);
        }
	}
}