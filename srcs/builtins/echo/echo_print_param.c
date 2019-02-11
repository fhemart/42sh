/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_print_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:45:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 17:01:33 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

static char	*copy_last(char *last, t_awstr *awstr)
{
	size_t		len;

	len = ft_strlen(last);
	ft_awstrncat(awstr, last, len);
	return (last + len);
}

int			print_param_bs(char **args)
{
	t_awstr		awstr;
	char		*last;
	char		*curr;
	int			cut;

	awstr.size = 0;
	cut = 0;
	while ((last = *args))
	{
		while (cut == 0 && *last)
		{
			if ((curr = ft_strchr(last, '\\')))
				last = parse_bs(last, curr, &awstr, &cut);
			else
				last = copy_last(last, &awstr);
		}
		if (cut == 1)
			break ;
		args++;
		if (*args)
			ft_awstrset(&awstr, ' ', 1);
	}
	ft_putawstr(&awstr);
	return (SUCCESS);
}

int			print_param(char **args)
{
	while (*args)
	{
		if (ft_putstr(*args) == FAILURE
		|| (args[1] && ft_putchar(' ') == FAILURE))
			return (FAILURE);
		args++;
	}
	return (SUCCESS);
}
