/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:25:07 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include "minishell.h"

// debugg.c
void	see_flags_and_pipes(t_attr att);
void	ft_print_array(char **array);

// prompt.c
char	*prompt(t_attr *att);

// utils_1.c
char	*trim_back(const char *input);
char	*white_sp_rm(const char *str);
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strcpy(char *destination, const char *source);
int		flag_counter(char *str, char c);

// utils_2.c
int		check_firstchar(char *str);
int		check_alpha(char *str);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t n);
int		str_empty(char *str);

// minishell_utils.c
void	first_step(char **envp, t_attr *att, t_toki *tok);
void	void_params(int ac, char **av);
void	del_stuff(t_attr *att, char *str);
void	chkstep_gettok(t_attr *att, t_toki *tok);
void	str_is_true(char *str, t_attr *att, t_toki *tok);

#endif