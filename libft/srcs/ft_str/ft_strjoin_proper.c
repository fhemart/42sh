/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_proper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:42:20 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/17 02:56:24 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_proper(char **s1, char *s2)
{
	char	*tmp;
	char	*dummy;

	dummy = *s1;
	tmp = ft_strjoin(dummy, s2);
	if (dummy)
		free(dummy);
	*s1 = tmp;
	return (tmp);
}
