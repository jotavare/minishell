/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/24 02:31:38 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

# include "minishell.h"

// count_tokens.c
int			count_tokens(char *s, t_attr *att);
int			check_single_quotes(char *s, int len, t_attr *att);
int			check_double_quotes(char *s, int len, t_attr *att);
int			check_non_space_char(char *s, int len, t_attr *att);
int			check_special_char(char *s, int len, t_attr *att);

// get_tokens.c
char		*get_token(char *s, t_attr *att);
char		*process_token_two(char *s, t_attr *att);
char		*process_token_three(char *s, t_attr *att);
char		*process_multi_quote(char *s, t_attr *att);
char		*process_default(char *s, t_attr *att);
char		*quotentoken(char *s, t_attr *att, int flag, int pos);

// get_tokens2.c
int			count_tokens2(char *s, t_attr *att);
char		*get_token2(char *s, t_attr *att);
void		create_array2(char *s, t_attr *att);
char		**get_tokens2(char *str, t_attr *att);

// tokens.c
void		create_array(char *s, t_attr *att);
char		**get_tokens(char *str, t_attr *att);
void		null_token_handle(t_attr *att);

// tokens_utils.c
void		count_quotes(char *s, t_attr *att);

#endif