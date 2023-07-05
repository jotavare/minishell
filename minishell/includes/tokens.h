/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/03 11:47:08 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

# include "minishell.h"

// count_tokens.c
int		count_tokens(char *s, t_attr *att);
int		check_single_quotes(char *s, int len, int i, t_attr *att);
int		check_double_quotes(char *s, int len, int i, t_attr *att);
int		check_non_space_char(char *s, int len, int i, t_attr *att);
int		check_special_char(char *s, int len, int i, t_attr *att);

// get_tokens_1.c
char	*get_token(char *s, t_attr *att, t_toki *tok);
char	*processt2_t3(char *s, t_attr *att);
char	*quotentoken(char *s, t_toki *tok);

// get_tokens2.c
int		count_tokens2(char *s, t_attr *att);
char	*get_token2(char *s, t_attr *att);
void	create_array2(char *s, t_attr *att);
char	**get_tokens2(char *str, t_attr *att);

// tokens_utils_1.c
void	count_quotes(char *s, t_attr *att);
int		count_if_pipe(t_attr *att, char *s);
int		count_if_redir(t_attr *att, char *s);
int		count_if_read(t_attr *att, char *s);
int		process_next_token(t_attr *att, char *s);

// tokens_utils_2.c
char	*process_next_check(char *s, t_attr *att);
char	*check_if_pipe(char *s, t_attr *att);
char	*check_if_redir(char *s, t_attr *att);
char	*check_if_read(char *s, t_attr *att);
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
void	backup_in_quotes(char *s, char c, t_attr *att);
void	advance_in_quotes(char *s, char c, t_attr *att);

// tokens_utils_5.c
void	reinit_gt_var(t_attr *att, t_toki *tok);
char	*give_token(char *s, t_attr *att, t_toki *tok);
int		to_quote(char *s, t_attr *att, t_toki *tok);
int		to_dquote(char *s, t_attr *att, t_toki *tok);

void	deal_with_it(char *s, t_toki *tok);
void	deal_aux(char *s, t_toki *tok);

// tokens.c
void	create_array(char *s, t_attr *att, t_toki *tok);
char	**get_tokens(char *str, t_attr *att, t_toki *tok);
int		count_true_chars(char *str, t_toki *tok);
void	dif_from_c(char *str, char c, t_toki *tok);

#endif