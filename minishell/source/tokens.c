/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/31 01:28:44 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	count_tokens(char *s, t_attr *att)
{
	int	len;

	len = ft_strlen(s) - 1;
	while (len >= 0)
	{
		if (s[len] != ' ' && s[len] != '|')
		{
			att->nb_tokens++;
			while (len > 0 && (s[len] != ' ' && s[len] != '|'))
				len--;
		}
		if (s[len] == ' ')
			len--;
		else if (s[len] == '|')
		{
			len--;
			att->nb_tokens++;
		}
		else
			len--;
	}
	return (att->nb_tokens);
}

char	*get_token(char *s, t_attr *att)
{
	char	*token;
	int		i;
	int		j;

	i = 0;
	j = 0;
	token = 0;
	if (s[j] != '|')
	{
		while (s[j] != ' ' && s[j] != '|' && s[j] != '\0')
			j++;
		token = malloc(sizeof(char) * (j + 1));
		if (!token)
			return (NULL);
		token[j] = '\0';
		while (i < j)
		{
			token[i] = s[i];
			i++;
		}
	}
	else if (s[j] == '|')
	{
		token = malloc(sizeof(char) * 2);
		if (!token)
			return (NULL);
		token[0] = s[j];
		token[1] = 0;
		att->nb_pipes++;
	}
	return (token);
}

void	create_array(char *s, t_attr *att)
{
	int	count;

	att->index = 0;
	att->tok_arr = malloc((att->nb_tokens + 1) * sizeof(char *));
	att->tok_arr[att->nb_tokens] = NULL; //valgrind
	if (!att->tok_arr)
		return ;
	count = 0;
	while (count < att->nb_tokens)
	{
		while (*s == ' ')
			s++;
		att->tok_arr[count] = get_token(s, att);
		s += ft_strlen(att->tok_arr[count]);
		count++;
	}
	//return (att->tok_arr);
}

char	**get_tokens(char *str, t_attr *att)
{
	if (!str)
		return (NULL);
	count_tokens(str, att);
	create_array(str, att);
	expand_tokens(att->tok_arr, att);
	//ft_print_array(in_str->s_arr, in_str->nb_tokens);
	//printf("p_nbr= %d\n", att->nb_pipes);
	return (att->tok_arr);
}

/*++++++ This part is only for test purposes +++++ */
//void	ft_print_array(char **array, int nb);
/* 
int main(void)
{
    t_attr attr;
	attr.nb_tokens = 0;
	attr.nb_pipes = 0;
    char    *str = "  ola o alexandre e ||o joao";
    int    nb_tok = 1;
    //init_attributes(&attr);
    char **tokens = get_tokens(str, &attr);
    ft_print_array(tokens, attr.nb_tokens);
	printf("nbr_tokens= %d\n", attr.nb_tokens);
    int i = 0;
    while (i < nb_tok)
        free(tokens[i++]);
    free(tokens);
}

void	ft_print_array(char **array, int nb)
{
	int i = 0;

	if (array == NULL)
		printf("Array is NULL\n");
	else
	{
		for(i = 0; i < nb; i++)
        {
        	printf("%d - %s\n", i, array[i]);
        }
	}
}
 */