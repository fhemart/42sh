/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_stdtable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:59:11 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 21:05:44 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

void	update_stdtable(int *stdio, int fdold, int fdnew)
{
	if (fdold < 3 && fdold >= 0)
		stdio[fdold] = fdnew;
	else if (stdio[0] == fdold)
		stdio[0] = fdnew;
	else if (stdio[1] == fdold)
		stdio[1] = fdnew;
	else if (stdio[2] == fdold)
		stdio[2] = fdnew;
}
