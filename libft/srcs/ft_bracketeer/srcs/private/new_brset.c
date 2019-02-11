/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_brset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:40:00 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 18:55:46 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"

static void	debug_nbrset(t_brinfo *sinfo, char *expendmatching)
{
	ft_putstr("[new brset]:\n  open  (");
	ft_putnbr(sinfo->size[BRACK_OPEN]);
	ft_putstr("): \"");
	ft_putstr(sinfo->op);
	ft_putstr("\"\n  close (");
	ft_putnbr(sinfo->size[BRACK_CLOSE]);
	ft_putstr("): \"");
	ft_putstr(sinfo->cl);
	ft_putstr("\"\n  chrmsk    : \"");
	ft_putstr(expendmatching);
	ft_putstr("\"\n");
}

t_brset		*new_brset_oc(char *oc[2], char *expendmatching)
{
	t_brset		*new;
	t_brinfo	*sinfo;
	char		c[2];

	if (!(new = (t_brset*)ft_memalloc(sizeof(t_brset))))
		return (NULL);
	sinfo = &new->info;
	sinfo->type = BR_QUOTE;
	sinfo->op = oc[BRACK_OPEN];
	sinfo->size[BRACK_OPEN] = ft_strlen(oc[BRACK_OPEN]);
	sinfo->cl = oc[BRACK_CLOSE];
	sinfo->size[BRACK_CLOSE] = ft_strlen(oc[BRACK_CLOSE]);
	sinfo->expmatch = new_chrmsk(expendmatching);
	c[0] = *sinfo->cl;
	c[1] = '\0';
	ft_chrmskadd(&sinfo->expmatch, c);
	if (BRACK_DEBUGPRINT)
		debug_nbrset(sinfo, expendmatching);
	return (new);
}

static void	debug_nescset(t_escinfo *esc)
{
	ft_putstr("[new escset]:\n  (");
	ft_putnbr(esc->size);
	ft_putstr("): \"");
	ft_putstr(esc->escape);
	ft_putstr("\"\n");
}

t_escset	*new_escset(char *escape)
{
	t_escset	*new;
	t_escinfo	*sinfo;

	if (!escape || !(new = (t_escset*)ft_memalloc(sizeof(t_escset))))
		return (NULL);
	sinfo = &new->info;
	sinfo->type = BR_ESCAPE;
	sinfo->escape = escape;
	sinfo->size = ft_strlen(escape);
	if (BRACK_DEBUGPRINT)
		debug_nescset(sinfo);
	return (new);
}
