/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/20 11:45:35 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_tokens2(char *s, t_attr *att)
{
	int	len;

	if (!s)
		return (0);
	len = ft_strlen(s) - 1;
	while (len >= 0)
	{
		if (s[len] != ' ' && s[len] != '|' && s[len] != '<' && s[len] != '>')
		{
			att->pars_data.nb_tokenst++;
			while (len > 0 && (s[len] != '|' && s[len] != '<' && s[len] != '>'))
				len--;
		}
		if (s[len] == ' ')
			len--;
		else if (s[len] == '|' && s[len - 1] != '|')
		{
			len--;
			att->pars_data.nb_tokenst++;
		}
		else if (s[len] == '|' && s[len - 1] == '|')
		{
			len--;
			len--;
			att->pars_data.nb_tokenst++;
		}
		else if (s[len] == '>' && s[len - 1] != '>')
		{
			len--;
			att->pars_data.nb_tokenst++;
		}
		else if (s[len] == '>' && s[len - 1] == '>')
		{
			len--;
			len--;
			att->pars_data.nb_tokenst++;
		}
		else if (s[len] == '<' && s[len - 1] != '<')
		{
			len--;
			att->pars_data.nb_tokenst++;
		}
		else if (s[len] == '<' && s[len - 1] == '<')
		{
			len--;
			len--;
			att->pars_data.nb_tokenst++;
		}
		else
			len--;
	}
	return (att->pars_data.nb_tokenst++);
}

char	*get_token2(char *s, t_attr *att)
{
	char	*token;
	int		i;
	int		j;

	i = 0;
	j = 0;
	token = 0;
	if (s[j] != '|' && s[j] != '>' && s[j] != '<')
	{
		while (s[j] != '|' && s[j] != '>' && s[j] != '<' && s[j] != '\0')
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
	else if (s[j] == '|' && s[j + 1] != '|')
	{
		token = malloc(sizeof(char) * 2);
		if (!token)
			return (NULL);
		token[0] = s[j];
		token[1] = 0;
		att->number_of_pipes++;
	}
	else if (s[j] == '|' && s[j + 1] == '|')
	{
		token = malloc(sizeof(char) * 3);
		if (!token)
			return (NULL);
		token[0] = s[j];
		token[1] = s[j + 1];
		token[2] = 0;
	}
	else if (s[j] == '>' && s[j + 1] != '>')
	{
		token = malloc(sizeof(char) * 2);
		if (!token)
			return (NULL);
		token[0] = s[j];
		token[1] = 0;
		att->number_of_redir++;
	}
	else if (s[j] == '>' && s[j + 1] == '>')
	{
		token = malloc(sizeof(char) * 3);
		if (!token)
			return (NULL);
		token[0] = s[j];
		token[1] = s[j + 1];
		token[2] = 0;
		att->number_of_append++;
	}
	else if (s[j] == '<' && s[j + 1] != '<')
	{
		token = malloc(sizeof(char) * 2);
		if (!token)
			return (NULL);
		token[0] = s[j];
		token[1] = 0;
	}
	else if (s[j] == '<' && s[j + 1] == '<')
	{
		token = malloc(sizeof(char) * 3);
		if (!token)
			return (NULL);
		token[0] = s[j];
		token[1] = s[j + 1];
		token[2] = 0;
	}
	return (token);
}

void	create_array2(char *s, t_attr *att)
{
	int	count;

	att->index = 0;
	att->pars_data.pars_arr = malloc((att->pars_data.nb_tokenst + 1)
			* sizeof(char *));
	att->pars_data.pars_arr[att->pars_data.nb_tokenst] = NULL;
	if (!att->pars_data.pars_arr)
		return ;
	count = 0;
	while (count < att->pars_data.nb_tokenst)
	{
		while (*s == ' ')
			s++;
		att->pars_data.pars_arr[count] = get_token2(s, att);
		s += ft_strlen(att->pars_data.pars_arr[count]);
		count++;
	}
}

char	**get_tokens2(char *str, t_attr *att)
{
	if (!str)
		return (NULL);
	att->pars_data.nb_tokenst = 0;
	att->pars_data.pars_arr = NULL;
	count_tokens2(str, att);
	create_array2(str, att);
	return (att->pars_data.pars_arr);
}

/*
	A PRIMEIRA GET_TOKENS, DELETAR QUANDO MINISHELL
	ESTIVE MINIMAMENT FUNCIONAL :D
*/

/* #include "../../includes/minishell.h"

int	count_tokens(char *s, t_attr *att)
{
	int	len;

	len = ft_strlen(s) - 1;
	while (len >= 0)
	{
		if (s[len] != ' ')
		{
			att->nb_tokens++;
			while (len > 0 && s[len] != ' ')
				len--;
		}
		if (s[len] == ' ')
			len--;
		if (len == 0)
			break ;
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

char	*get_token(char *s)
{
	char	*token;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j] != ' ' && s[j] != '\0')
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
		att->tok_arr[count] = get_token(s);
		count++;
		while (*s != ' ' && *s != '\0')
			s++;
	}
}

char	**get_tokens(char *str, t_attr *att)
{
	att->nb_tokens = 0;
	if (!str)
		return (NULL);
	count_tokens(str, att);
	create_array(str, att);
	//ft_print_array(att->s_arr);
	return (att->tok_arr);
}

++++++ This part is only for test purposes +++++ 
 void	ft_print_array(char **array, int nb);

int	main(void)
{
    t_attr attr;
	char	*str;
	int		nb_tok;
	char	**tokens;
	int		i;

	attr.nb_tokens = 0;
    str = "echo a $SHELL b";
    nb_tok = 1;
    //init_attributes(&attr);
    tokens = get_tokens(str, &attr);
    ft_print_array(tokens, attr.nb_tokens);
    i = 0;
    while (i < nb_tok)
        free(tokens[i++]);
    free(tokens);
}

 void	ft_print_array(char **array)
{
	int		i;
	char	*token;
	int		i;

	i = 0;
	while (array[i])
	{
		printf ("%s\n", array[i]);
		i++;
	}
	printf("end of array\n\n");
}
*/
/* PSEUDO CODE
	1 get_tokens build an array untill the first pipe
	2 execute it and redirect the output to the pipe
	3 read again after the pipe and build a new array
	4 execute it and set the input stream from the pipe
		keep doing this until the end of the string
*/
/*
char	*get_token(char *s, t_attr *att)
{
	int		att->tok_arr_i;
	i = 0;
	att->tok_arr_i = 0;
	token = 0;
	if (s[att->tok_arr_i] != '|' && s[att->tok_arr_i] != '>'
		&& s[att->tok_arr_i] != '<' )
	{
		while (s[att->tok_arr_i] != ' ' && s[att->tok_arr_i] != '|'
			&& s[att->tok_arr_i] != '>' && s[att->tok_arr_i] != '<'
			&& s[att->tok_arr_i] != '\0')
			att->tok_arr_i++;
		token = malloc(sizeof(char) * (att->tok_arr_i + 1));
		if (!token)
			return (NULL);
		token[att->tok_arr_i] = '\0';
		while (i < att->tok_arr_i)
		{
			token[i] = s[i];
			i++;
		}
	}
	else if (s[att->tok_arr_i] == '|' && s[att->tok_arr_i + 1] != '|')
	{
		token = malloc(sizeof(char) * 2);
		if (!token)
			return (NULL);
		token[0] = s[att->tok_arr_i];
		token[1] = 0;
	}
	else if (s[att->tok_arr_i] == '|' && s[att->tok_arr_i + 1] == '|' )
	{
		token = malloc(sizeof(char) * 3);
		if (!token)
			return (NULL);
		token[0] = s[att->tok_arr_i];
		token[1] = s[att->tok_arr_i + 1];
		token[2] = 0;
	}
	else if (s[att->tok_arr_i] == '>' && s[att->tok_arr_i + 1] != '>')
	{
		token = malloc(sizeof(char) * 2);
		if (!token)
			return (NULL);
		token[0] = s[att->tok_arr_i];
		token[1] = 0;
	}
	else if (s[att->tok_arr_i] == '>' && s[att->tok_arr_i + 1] == '>' )
	{
		token = malloc(sizeof(char) * 3);
		if (!token)
			return (NULL);
		token[0] = s[att->tok_arr_i];
		token[1] = s[att->tok_arr_i + 1];
		token[2] = 0;
	}
	else if (s[att->tok_arr_i] == '<' && s[att->tok_arr_i + 1] != '<')
	{
		token = malloc(sizeof(char) * 2);
		if (!token)
			return (NULL);
		token[0] = s[att->tok_arr_i];
		token[1] = 0;
	}
	else if (s[att->tok_arr_i] == '<' && s[att->tok_arr_i + 1] == '<')
	{
		token = malloc(sizeof(char) * 3);
		if (!token)
			return (NULL);
		token[0] = s[att->tok_arr_i];
		token[1] = s[att->tok_arr_i + 1];
		token[2] = 0;
	}
	return (token);
}
*/