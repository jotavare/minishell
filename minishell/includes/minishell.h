/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:28:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:25:06 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "structs.h"
# include "macros.h"
# include "inicialize.h"
# include "tokens.h"
# include "parser.h"
# include "commands.h"
# include "executer.h"
# include "error.h"
# include "sanitize.h"
# include "utilities.h"

extern int	g_value;

//	minishell_utils.c
void	chkstep_gettok(t_attr *att, t_toki *tok);
void	del_stuff(t_attr *att, char *str);
void	void_params(int ac, char **av);
void	first_step(char **envp, t_attr *att, t_toki *tok);
void	str_is_true(char *str, t_attr *att, t_toki *tok);

#endif