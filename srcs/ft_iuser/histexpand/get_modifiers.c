/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_modifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:00:04 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/24 17:32:52 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static int	process_modifier(t_histemark *hem, t_emarkmod *mods)
{
	static int	(*proc[HISTEMARK_MOD_GLOB])() = {pmodh, pmodt, pmodr, pmode, \
												pmodp, pmodq, pmodx, pmods};
	int			i;

	i = -1;
	while (++i < HISTEMARK_MOD_GLOB)
		if ((mods->type & (1 << i)))
			return (i != HISTEMARK_MOD_SUBS ? proc[i](hem) : pmods(hem, mods));
	return (FAILURE);
}

int			get_modifiers(t_histemark *hem, t_emarkmod *mods, t_shdata *data)
{
	t_chrmsk	modmsk;

	(void)data;
	modmsk = new_chrmsk(HISTEMARK_MOD_MSK);
	while ((mods->state = get_next_modtype(hem, mods, \
											&modmsk, data)) == ST_CONTINUE)
	{
		process_modifier(hem, mods);
	}
	return (mods->state == ST_SUCCESS ? SUCCESS : FAILURE);
}
