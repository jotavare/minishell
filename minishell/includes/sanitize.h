/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:13 by jotavare          #+#    #+#             */
/*   Updated: 2023/06/30 23:45:32 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SANITIZE_H
# define SANITIZE_H

# include "minishell.h"

// free_one.c
void	free_arr(char **arr);
void	free_in_arr(char **arr);
void	free_tokens(char **tokens, t_attr *att);
void	free_g_env(t_attr *att);
void	free_d_env(t_attr *att);
void	free_exp_env(t_attr *att);

// free_two.c
void	free_d_exp_env(t_attr *att);
void	exit_free(t_attr *att);
void	ft_delete_matrix(void *matrix);
void	free_start_args(t_exec *args, t_attr *att);
void	free_child(t_attr *att, t_exec *args);

#endif