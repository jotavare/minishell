/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/28 22:12:26 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

# include "minishell.h"

char	*select_processing_strategy(int quotes, t_attr *att, char *s, t_toki tok);

// count_tokens.c
int		count_tokens(char *s, t_attr *att);
int		check_single_quotes(char *s, int len, int i, t_attr *att);
int		check_double_quotes(char *s, int len, int i, t_attr *att);
int		check_non_space_char(char *s, int len, int i, t_attr *att);
int		check_special_char(char *s, int len, int i, t_attr *att);

// get_tokens_1.c
char	*get_token(char *s, t_attr *att, t_toki tok);
char	*quotentoken(char *s, t_attr *att, t_toki *tok);

// get_tokens2.c
int		count_tokens2(char *s, t_attr *att);
char	*get_token2(char *s, t_attr *att);
void	create_array2(char *s, t_attr *att);
char	**get_tokens2(char *str, t_attr *att);

// tokens_utils_1.c
void	count_quotes(char *s, t_attr *att);
int		count_if_pipe(t_attr *att, int *len, char *s);
int		count_if_redir(t_attr *att, int *len, char *s);
int		count_if_read(t_attr *att, int *len, char *s);
int		process_next_token(t_attr *att, char *s, int len);

// tokens_utils_2.c
void	process_next_check(char *s, int j, t_attr *att, char **token);
int		check_if_pipe(char **token, int j, char *s);
int		check_if_redir(char **token, int j, char *s);
int		check_if_read(char **token, int j, char *s);
void	count_d_s_quotes(char *s, t_attr *att);

// tokens_utils_3.c
char	*process_default(char *s, t_attr *att);
char	*process_token_two(char *s, t_attr *att);
char	*process_token_three(char *s, t_attr *att);
void	reinit_toki(t_toki *tok);
char	*process_special_char(char *s, t_attr *att);

// tokens_utils_4.c
char	*process_multi_quote(char *s, t_attr *att, t_toki *tok);
void	flag2up(char *s, t_attr *att, t_toki *tok);
void	flag1up(char *s, t_attr *att, t_toki *tok);
char	*process_single_quotes(char *s, t_attr *att, t_toki *tok);
char	*process_double_quotes(char *s, t_attr *att, t_toki *tok);

// tokens.c
void	create_array(char *s, t_attr *att, t_toki tok);
char	**get_tokens(char *str, t_attr *att, t_toki tok);

#endif
