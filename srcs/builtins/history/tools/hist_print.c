/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:27:37 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 19:03:52 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static void	hist_print_entno(int entno, int pad)
{
	char	*n;

	ft_putstr("   ");
	n = ft_static_itoa(entno);
	while (pad != (int)ft_strlen(n))
	{
		ft_putchar(' ');
		pad--;
	}
	ft_putstr(n);
	ft_putstr("  ");
}

static void	recurs_print_nentry(t_histentry *entry, int fromto[2], int pad, \
								char *time_format)
{
	if (!entry || fromto[0] == fromto[1])
		return ;
	fromto[1]--;
	recurs_print_nentry(entry->prev, fromto, pad, time_format);
	fromto[1]++;
	hist_print_entno(fromto[1], pad);
	hist_print_entry(entry, time_format);
}

static void	recurs_print_entry(t_histentry *entry, int entry_count, int pad, \
								char *time_format)
{
	if (!entry)
		return ;
	recurs_print_entry(entry->prev, entry_count - 1, pad, time_format);
	hist_print_entno(entry_count, pad);
	hist_print_entry(entry, time_format);
}

void		hist_print_nentry(t_shhist *hist, int n, char *time_format)
{
	int		pad;
	int		fromto[2];
	int		size;

	pad = 1;
	size = hist->entry_count;
	while ((size /= 10))
		pad++;
	if (n == -1)
		recurs_print_entry(hist->entries, hist->entry_count, pad, time_format);
	else
	{
		if (n > hist->entry_count)
			fromto[0] = hist->entry_count;
		else
			fromto[0] = hist->entry_count - n;
		fromto[1] = hist->entry_count;
		recurs_print_nentry(hist->entries, fromto, \
							pad, time_format);
	}
}

void		hist_print_entry(t_histentry *entry, char *time_format)
{
	char		format[256];
	struct tm	*tinfo;

	if (!entry)
		return ;
	if (time_format)
	{
		tinfo = localtime(&entry->timestamp);
		if (strftime(format, 256, time_format, tinfo))
			ft_putstr(format);
	}
	ft_putendl(entry->string);
}
