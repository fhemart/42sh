/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_new_p1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:27:37 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 19:30:30 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

static char	*file2str(char *filename)
{
	struct stat		st_stat;
	char			*ret;
	int				fd;

	if (lstat(filename, &st_stat) == -1
	|| st_stat.st_size == 0
	|| !(ret = malloc(st_stat.st_size + 1)))
		return (NULL);
	if ((fd = open(filename, O_RDONLY)) != -1)
	{
		read(fd, ret, st_stat.st_size);
		ret[st_stat.st_size] = '\0';
		close(fd);
	}
	else
		ft_strdel(&ret);
	return (ret);
}

void		hist_load_entries(t_shhist *hist, char *histfile)
{
	char		*filestr;
	int			entry_added;
	int			old_entrycount;

	filestr = file2str(histfile);
	old_entrycount = hist->entry_count;
	hist->entries = convert_file2entries(hist->entries, filestr, \
										&hist->entry_count);
	entry_added = hist->entry_count - old_entrycount;
	hist_update_books(hist, histfile, entry_added);
	ft_strdel(&filestr);
}

void		hist_load_entries_nd(t_shhist *hist, char *histfile)
{
	char		*filestr;
	t_histbook	*book;
	int			old_entrycount;

	if (!(book = hist_find_book(hist->files, histfile)))
		return ;
	filestr = file2str(histfile);
	old_entrycount = hist->entry_count;
	hist->entries = convert_file2entries_nd(hist->entries, filestr, \
										&hist->entry_count, book);
	book->line_read += (hist->entry_count - old_entrycount);
	ft_strdel(&filestr);
}

t_shhist	*hist_new(char *histfile)
{
	t_shhist	*ret;
	char		*filestr;

	if (!(ret = (t_shhist*)ft_memalloc(sizeof(*ret))))
		return (NULL);
	filestr = file2str(histfile);
	ret->entries = convert_file2entries(NULL, filestr, &ret->entry_count);
	hist_update_books(ret, histfile, ret->entry_count);
	ft_strdel(&filestr);
	return (ret);
}
