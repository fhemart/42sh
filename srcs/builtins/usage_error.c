/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:45:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/15 12:45:48 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

int			usage_error(char *usage)
{
	ft_putendl(usage);
	return (EXIT_FAILURE);
}
