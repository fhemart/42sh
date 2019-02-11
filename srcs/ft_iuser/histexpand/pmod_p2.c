/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmod_p2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:00:04 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 17:33:27 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static int		count_quote(char *str)
{
	int		i;

	i = 0;
	while ((str = ft_strchr(str, '\'')))
	{
		str++;
		i++;
	}
	return (i);
}

static void		copy_with_escapequ(char *buff, char *copy)
{
	size_t		len;
	char		*dummy;

	dummy = copy;
	while ((dummy = ft_strchr(copy, '\'')))
	{
		len = (size_t)(dummy - copy);
		ft_strncpy(buff, copy, len);
		ft_strcpy(buff + len, "'\\''");
		buff += (len + 4);
		copy = dummy + 1;
	}
	ft_strcpy(buff, copy);
}

static char		*pmodx_create_word(char *find, char *lastfound, int f)
{
	char		*word;
	char		c;
	size_t		wlen;
	size_t		qu_cnt;

	wlen = find ? (size_t)(find - lastfound) : ft_strlen(lastfound);
	c = lastfound[wlen];
	lastfound[wlen] = '\0';
	qu_cnt = count_quote(lastfound) * 3;
	if (!(word = ft_strnew(wlen + qu_cnt + (3 - f))))
		return (NULL);
	*word = '\'';
	copy_with_escapequ(word + 1, lastfound);
	lastfound[wlen] = c;
	word[wlen + qu_cnt + 1] = '\'';
	if (find)
		word[wlen + qu_cnt + 2] = *find;
	word[wlen + qu_cnt + (3 - f)] = '\0';
	return (word);
}

int				pmodq(t_histemark *hem)
{
	char	*new_replace;
	size_t	len;

	len = ft_strlen(hem->replace) + (count_quote(hem->replace) * 3) + 2;
	if (!(new_replace = ft_strnew(len)))
		return (FAILURE);
	*new_replace = '\'';
	copy_with_escapequ(new_replace + 1, hem->replace);
	new_replace[len - 1] = '\'';
	new_replace[len] = '\0';
	ft_strdel(&hem->replace);
	hem->replace = new_replace;
	return (SUCCESS);
}

int				pmodx(t_histemark *hem)
{
	char		*word;
	t_chrmsk	endmsk;
	t_lstr		*lstr;
	char		*find;
	char		*lastfound;

	lstr = NULL;
	endmsk = new_chrmsk(" \t\n");
	lastfound = hem->replace;
	while ((find = chrmsk_getnext_match(lastfound, &endmsk)))
	{
		word = pmodx_create_word(find, lastfound, 0);
		lstr = ft__strcat(&lstr, word);
		free(word);
		lastfound = find + 1;
	}
	word = pmodx_create_word(find, lastfound, 1);
	lstr = ft__strcat(&lstr, word);
	free(word);
	ft_strdel(&hem->replace);
	hem->replace = ft_lstr_tostring(lstr);
	ft_lstrdel(&lstr);
	return (SUCCESS);
}
