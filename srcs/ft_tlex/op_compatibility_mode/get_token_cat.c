/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_cat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:46:27 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/06 19:05:08 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tlex.h"

int			get_token_cat(t_token *token, t_tkn_template *templates)
{
	if (!token)
		return (-1);
	return (templates[token->type].cat);
}
