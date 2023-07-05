/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:25:07 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INICIALIZE_H
# define INICIALIZE_H

# include "minishell.h"

void	init_params(t_attr *attr, char **envp);
void	init_attributes_one(t_attr *att);
void	init_attributes_two(t_attr *att);
void	init_toki(t_toki *tok);
void	reinit_attributes(t_attr *att);

void	refresh_addenv(t_attr *att, char *add);
void	refresh_add_exp(t_attr *att, char *add);
void	refresh_rmexp_env(t_attr *att, int rm_index);
void	refresh_rmenv(t_attr *att, int rm_index);
void	add_quotes(char *s);

int		start_args(t_exec *args, t_attr *att);
void	start_env(char **envp, t_attr *att);
void	start_exp(char **envp, t_attr *att);

char	*get_g_value(void);
void	update_g_val_var(t_attr *att);

#endif