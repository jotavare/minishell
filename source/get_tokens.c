/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/22 21:12:07 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_tokens(char **tokens, t_attr t)
{
	int	i;

	i = 0;
	while (i < t.nb_tokens)
		free(tokens[i++]);
}

int	count_tokens(char *s, t_attr *att)
{
	int	len;

	len = ft_strlen(s) - 1;
	while (len >= 0)
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
	return (att->nb_tokens);
	if (!s)
		return (1);
	else
		att->nb_tokens++;
	while (s[att->index++] && (att->index < len))
	{
		if (s[att->index] == ' ')
			att->nb_tokens++;
	}
	return (0);
}

/* int	count_tokens(char *s, t_attr *att)
{
	int	len;
	
	len = ft_strlen(s) - 1;
	while (len >= 0)
	{
		if (s[len] != ' ')
		{
			att->nb_tokens++;
			while (s[len] != ' ')
			{
				if (s[len] == '$')
				{
					att->nb_tokens++;		
				}
				len--;
			}
		}
		if (s[len] == ' ')
			len--;
	}
	return (att->nb_tokens);
	if (!s)
		return (1);
	else
		att->nb_tokens++;
	while (s[att->index++] && (att->index < len))
	{
		if (s[att->index] == ' ')
			att->nb_tokens++;
	}
	return (0);
	if (s[len] == ' ')
			len--;
} */

char	*get_token(char *s)
{
	char	*token;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j] != ' ' && s[j] != '\0')
		j++;
	token = malloc(sizeof(char) * j + 1);
	if (!token)
		return (NULL);
	token[j] = '\0';
	while (i < j)
	{
		token[i] = s[i];
		i++;
	}
	return (token);
}

/* char	*get_token(char *s)
{
	char	*token;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j] != ' ' && s[j] != '\0')
		j++;
	if (s[i] == '$')
	{
		token = malloc(sizeof(char) + 1);
		if (!token)
			return (NULL);
		token[0] = '$';
		token[1] = '\0';
		j++;
		return (token);
	}
	token = malloc(sizeof(char) * j + 1);
	if (!token)
		return (NULL);
	token[j] = '\0';
	while (i < j)
	{
		token[i] = s[i];
		i++;
	}
	return (token);
} */

char	**create_array(char *s, t_attr *att)
{
	int	count;

	att->index = 0;
	att->tok_arr = malloc((att->nb_tokens + 1) * sizeof(char *));
	att->tok_arr[att->nb_tokens] = NULL; //valgrind
	if (!att->tok_arr)
		return (0);
	count = 0;
	while (count < att->nb_tokens)
	{
		while (*s == ' ')
			s++;
		att->tok_arr[count] = get_token(s);
		count++;
		while (*s != ' ' && *s != '\0')
			s++;
	}
	return (att->tok_arr);
}

/* char	**create_array(char *s, t_attr *att)
{
	int	count;

	att->index = 0;
	att->tok_arr = malloc((att->nb_tokens + 1) * sizeof(char *));
	att->tok_arr[att->nb_tokens] = NULL; //valgrind
	if (!att->tok_arr)
		return (0);
	count = 0;
	while (count < att->nb_tokens)
	{
		while (*s == ' ')
			s++;
		if (*s != '$')
		{	
			att->tok_arr[count] = get_token(s);
			count++;
		}
		while (*s != ' ' && *s != '\0')
		{
			if (*s == '$')
			{
				att->tok_arr[count] = get_token(s);	
				count++;
				s++;
				break;
			}
			
			s++;
		}
	}
	return (att->tok_arr);
} */

char	**get_tokens(char *str, t_attr *in_str)
{
	if (!str)
		return (NULL);
	count_tokens(str, in_str);
	create_array(str, in_str);
	//ft_print_array(in_str->s_arr, in_str->nb_tokens);
	return (in_str->tok_arr);
}

/*++++++ This part is only for test purposes +++++ */
/* void	ft_print_array(char **array, int nb);

int main(void)
{
    t_attr attr;
	attr.nb_tokens = 0;
    char    *str = "echo a $SHELL b";
    int    nb_tok = 1;
    //init_attributes(&attr);
    char **tokens = get_tokens(str, &attr);
    ft_print_array(tokens, attr.nb_tokens);
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