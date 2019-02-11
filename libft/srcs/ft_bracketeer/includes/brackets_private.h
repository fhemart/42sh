/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:47:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/22 18:13:17 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRACKETS_PRIVATE_H
# define BRACKETS_PRIVATE_H

/*
**		CORE common functions
*/

t_brset			*new_brset_oc(char *oc[2], char *expendmatching);
t_escset		*new_escset(char *escape);
void			bracket_addnewset(t_brdata *data, t_brset *set);

t_chrmsk		*brdata_get_firstmsk(t_brdata *data);
t_chrmsk		*update_info(t_brdata *data);

t_bool			is_openbr(t_brdata *data, char *index);
t_bool			is_closedbr(t_brdata *data, char *index);
t_bool			current_is_validescape(t_brdata *data);

void			close_br(t_brdata *data);
void			find_openbr(t_brdata *data);
t_chrmsk		*skip_escape(t_brdata *data);

/*
**		GET_NEXT_QWORD specific functions
*/

t_chrmsk		*check_firstchar(t_brdata *data);

char			*close_escaping(t_brdata *data, char *start);
char			*find_next_closure(t_brdata *data, t_chrmsk *occ, char *start);
char			*find_next_quote(t_brdata *data, char *start);
t_br_return		*try_extend(t_brdata *data, t_br_return *br_ret);

t_br_return		*new_br_return(t_brdata *data);
void			close_br_return(t_br_return *br_ret);

#endif
