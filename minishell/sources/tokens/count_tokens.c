/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/27 18:51:56 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

void	count_dquotes_quotes(char *s, t_attr *att)
{
	int i;

	i = 0;
	//if (!s)
	//	return ;
	while(s[i])
	{
		if (s[i] == '"')
			att->o_dquotes++;
		else if (s[i] == '\'')
			att->o_quotes++;
		i++;
	}
}
int	check_single_quotes(char *s, int i, t_attr *att)
{
	int flag;
	
	flag = 0;
	while(s[i])
	{
		if(s[i] == '\'' && !flag)
			flag == 1;
	
		i++;
	}
}


int	count_tokens(char *s, t__attr *att)
{
	int i;

	i = 0;
	count_dquotes_quotes(s, att);
	att->nb_tokens = 0;
	while(s[i])
	{
		if(s[i] == '\'')
			i = check_single_quotes(s, i, att);
		i++;
	}
}
*/

int	count_tokens(char *s, t_attr *att)
{
	int	len;
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '"')
			att->o_dquotes++;
		else if (s[i] == '\'')
			att->o_quotes++;
		i++;
		
	}
	printf("dquotes= %d\n", att->o_dquotes);
	printf("squotes= %d\n", att->o_quotes);
	att->nb_tokens = 0;
	len = ft_strlen(s) - 1;
	while (len >= 0)
	{
		if (s[len] == '\'')
			len = check_single_quotes(s, len, att);
		else if (s[len] == '"')
			len = check_double_quotes(s, len, att);
		else if (s[len] != ' ')
			len = check_non_space_char(s, len, att);
		else if (s[len] != ' ' && s[len] != '|' && s[len] != '<'
			&& s[len] != '>')
			len = check_special_char(s, len, att);
		else if (s[len] == ' ')
			len--;
		else
			len--;
	}
	return (att->nb_tokens);
}

int	check_single_quotes(char *s, int len, t_attr *att)
{
	int	quotes;
	int	flag;

	flag = 0;
	quotes = 0;
	while (len >= 0 && quotes <= att->o_quotes)
	{
		if (s[len] == '\'')
		{
			quotes++;
			if (s[len + 1] && flag == 0)
			{
				if (s[len + 1] == ' ')
					flag = 1;
			}
			else if (!s[len + 1])
				flag = 1;
		}
		if (quotes % 2 == 0 && flag == 1)
		{
			att->nb_tokens++;
			len--;
			return (len);
		}
		len--;
	}
	return (len);
}

int	check_double_quotes(char *s, int len, t_attr *att)
{
	int	quotes;
	int	flag;

	flag = 0;
	quotes = 0;
	while (len >= 0 && quotes <= att->o_dquotes)
	{
		if (s[len] == '"')
		{
			quotes++;
			if (s[len + 1] && flag == 0)
			{
				if (s[len + 1] == ' ')
					flag = 1;
			}
			else if (!s[len + 1])
				flag = 1;
		}
		if (quotes % 2 == 0 && flag == 1)
		{
			att->nb_tokens++;
			len--;
			return (len);
		}
		len--;
	}
	return (len);
}

int	check_non_space_char(char *s, int len, t_attr *att)
{
	att->nb_tokens++;
	while (len >= 0 && s[len] != ' ')
	{
		len--;
	}
	return (len);
}

int	check_special_char(char *s, int len, t_attr *att)
{
	att->nb_tokens++;
	while (len >= 0 && (s[len] != ' ' && s[len] != '|' && s[len] != '<'
			&& s[len] != '>'))
	{
		len--;
	}
	return (len);
}
