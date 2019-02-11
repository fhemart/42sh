/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_are_compatible.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:46:27 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/06 11:38:32 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tlex.h"

static t_bool	token_compatibility1(int rhcat)
{
	if (rhcat != -1 && rhcat & TT_OPERATOR_LEFTHANDED)
		return (FALSE);
	return (TRUE);
}

static t_bool	token_compatibility2(int lhcat)
{
	if (lhcat & TT_OPERATOR_RIGHTHANDED)
		return (FALSE);
	return (TRUE);
}

static t_bool	token_compatibility3(int lhcat, int rhcat)
{
	if ((lhcat & TT_OPERATOR_RIGHTHANDED && rhcat & TT_OPERATOR_RIGHTHANDED)
	|| (lhcat & TT_OPERATOR_LEFTHANDED && rhcat & TT_OPERATOR_LEFTHANDED))
		return (FALSE);
	return (TRUE);
}

t_bool			token_are_compatible(t_token *lh, t_token *rh, \
									t_tkn_template *templates)
{
	int		lhcat;
	int		rhcat;

	lhcat = get_token_cat(lh, templates);
	rhcat = get_token_cat(rh, templates);
	if (lhcat == -1)
		return (token_compatibility1(rhcat));
	else if (rhcat == -1)
		return (token_compatibility2(lhcat));
	return (token_compatibility3(lhcat, rhcat));
}
