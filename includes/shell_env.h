/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_env.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 11:25:53 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/09 18:09:34 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_ENV_H
# define SHELL_ENV_H

# include "libft.h"
# include "ft_hashtable.h"

typedef struct s_varkey			t_varkey;
typedef struct s_setenvsave		t_setenvsave;
typedef struct s_envsave		t_envsave;

struct		s_setenvsave
{
	char *path;
	char *cdpath;
};

struct		s_varkey
{
	t_varkey	*next;
	char		*key;
	char		*value;
};

t_list		*lst_from_var(char *var);

t_varkey	*varkey_new(char *vksrc);
t_varkey	*varkey2_new(char *key, char *name);
void		varkey_del(t_varkey **vk);
int			varkey_print(t_varkey *vk);
void		varkey_isort(t_varkey **head, t_varkey *toadd);
t_varkey	*varkey_find(char *name, t_varkey *vklist);
t_varkey	*varkey_find2(char *name, size_t nsize, t_varkey *vklist);

typedef struct s_sh_evar		t_sh_evar;

struct		s_sh_evar
{
	t_sh_evar	*next;
	char		*key;
	char		*value;
	t_bool		isexport;
};

struct		s_envsave
{
	char			**old_argv;
	t_hashtable		*ht;
	t_sh_evar		*vklist;
	char			*home;
	int				old_argc;
};

void		sh_evar_print_debug(t_sh_evar *varlist);

t_sh_evar	*sh_evar_new(char *key, char *value);
void		sh_evar_delone(t_sh_evar **var);
void		sh_evar_delvar(t_sh_evar **varlist, t_sh_evar *var);
void		sh_evar_recdel(t_sh_evar *var);
void		sh_evar_addkey(t_sh_evar **head, t_sh_evar *toadd);
t_sh_evar	*sh_evar_getkey(t_sh_evar *varlist, char *key, size_t keylen);
int			sh_evar_delkey(t_sh_evar **varlist, char *key, size_t keylen);
char		*sh_evar_tostring(t_sh_evar *model);
t_sh_evar	*sh_evar_fromstring(char *str);
char		**sh_evar_toarraystring(t_sh_evar *varlist);
t_sh_evar	*sh_evar_lstdup(t_sh_evar *headsrc);
t_sh_evar	*sh_evar_dup(t_sh_evar *src);

typedef struct s_sh_env		t_sh_env;

struct		s_sh_env
{
	t_sh_evar	*var;
};

t_sh_env	*sh_env_new(char **model);
t_sh_evar	*sh_env_update(t_sh_env *env, char *keyvalue);
int			sh_env_update2(t_sh_env *env, char *key, char *value);
char		*sh_env_getvalue(t_sh_env *env, char *key);
char		*sh_env_getvalue2(t_sh_env *env, char *key, size_t klen);
char		*sh_env_getvalue3(t_sh_evar *vklist, char *key);
void		sh_env_destroy(t_sh_env **env);

t_bool		is_valid_firstchr(char c);
t_bool		is_valid_chr(char c);
t_bool		is_valid_varname(char *name);
t_bool		is_valid_varname2(char *name, size_t nlen);

int			init_shell_env(t_sh_env **st_env, char **ar_env);
int			update_pwd(t_sh_env *st_env);

char		*sh_env_getnext_spval(char *current, int *len);

#endif
