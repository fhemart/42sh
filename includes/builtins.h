/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:20:05 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 19:05:42 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "shell_env.h"

typedef struct s_builtin	t_builtin;
typedef struct s_cookedcmd	t_cookedcmd;
typedef struct s_shdata		t_shdata;

# define NOT_BUILTIN		-1

int			load_builtins(t_builtin **target);
int			get_builtin(t_builtin *builtins, char *name);

int			is_directory(char *dir);

#endif
