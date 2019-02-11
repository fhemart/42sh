/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errormsg.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 15:45:32 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/17 16:39:26 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORMSG_H
# define ERRORMSG_H

# include <sys/stat.h>
# include "ftsh.h"
# include "libft.h"

# define FT_EIOPT			"invalid option"
# define FT_ENOMEM			"Out of memory"
# define FT_ENAMETOOLONG	"File name too long"
# define FT_ENOENT			"No such file or directory"
# define FT_EISDIR			"Is a directory"
# define FT_ENOTDIR			"Not a directory"
# define FT_EACCES			"Permission denied"
# define FT_EBADF			"Bad file descriptor"
# define FT_EPIPE			"Broken pipe"
# define FT_ELOOP			"Too many levels of symbolic links"
# define FT_EAMBR			"ambiguous redirect"
# define FT_EAGAIN			"resource temporary unavailable"
# define EARGREQ			"option requires an argument"
# define EXIT_ENONUM		": numeric argument required"

void		p_enotdir(char *file, char *head);
int			p_enonum(char *head, char *nonum);
int			p_eagain(char *head);
void		p_ename2long(char *head);
void		p_enoent(char *file, char *head);
void		p_enotf(char *head, char *name);
void		p_eisdir(char *file, char *head);
void		p_eacces(char *file, char *head);
void		p_eloop(char *file, char *head);
int			p_eambr(char *head, char *str);
int			p_ebadf(char *head, char *str);
int			p_eargreq(char *head, char *usage, int opt);
int			print_dir_error(char *arg, int ret);
void		p_ename2long(char *head);
int			ft_write_error(char *head);
int			open_error(char *file, int flag);

# define SIG_MSG0	""
# define SIG_MSG1	"Hangup\n"
# define SIG_MSG2	"\n"
# define SIG_MSG3	"Quit (core dumped)\n"
# define SIG_MSG4	"Illegal instruction (core dumped)\n"
# define SIG_MSG5	"Trace/breakpoint trap (core dumped)\n"
# define SIG_MSG6	"Aborted (core dumped)\n"
# define SIG_MSG7	"Bus error (core dumped)\n"
# define SIG_MSG8	"Floating point exception (core dumped)\n"
# define SIG_MSG9	"Killed\n"
# define SIG_MSG10	"User defined signal 1\n"
# define SIG_MSG11	"Segmentation fault (core dumped)\n"
# define SIG_MSG12	"User defined signal 2\n"
# define SIG_MSG13	"Broken pipe\n"
# define SIG_MSG14	"Alarm clock\n"
# define SIG_MSG15	"Terminated\n"
# define SIG_MSG16	"Stack fault\n"
# define SIG_MSG17	""
# define SIG_MSG18	""
# define SIG_MSG19	"[%d]+  Stopped                 %s\n"
# define SIG_MSG20	"[%d]+  Stopped                 %s\n"
# define SIG_MSG21	"[%d]+  Stopped                 %s\n"
# define SIG_MSG22	"[%d]+  Stopped                 %s\n"
# define SIG_MSG23	""
# define SIG_MSG24	"CPU time limit exceeded (core dumped)\n"
# define SIG_MSG25	""
# define SIG_MSG26	"Virtual timer expired\n"
# define SIG_MSG27	"Profiling timer expired\n"
# define SIG_MSG28	""
# define SIG_MSG29	"I/O possible\n"
# define SIG_MSG30	"Power failure\n"
# define SIG_MSG31	"Bad system call (core dumped)\n"
# define SIG_UNKNOWN	"Unknown signal "
# define SIG_RTN		"Real-time signal "

# define SIGMSG_PACK1	SIG_MSG0, SIG_MSG1, SIG_MSG2, SIG_MSG3, SIG_MSG4
# define SIGMSG_PACK2	SIG_MSG5, SIG_MSG6, SIG_MSG7, SIG_MSG8, SIG_MSG9
# define SIGMSG_PACK3	SIG_MSG10, SIG_MSG11, SIG_MSG12, SIG_MSG13, SIG_MSG14
# define SIGMSG_PACK4	SIG_MSG15, SIG_MSG16, SIG_MSG17, SIG_MSG18, SIG_MSG19
# define SIGMSG_PACK5	SIG_MSG20, SIG_MSG21, SIG_MSG22, SIG_MSG23, SIG_MSG24
# define SIGMSG_PACK6	SIG_MSG25, SIG_MSG26, SIG_MSG27, SIG_MSG28, SIG_MSG29
# define SIGMSG_PACK7	SIG_MSG30, SIG_MSG31

# define SIGMSG_REPACK1	SIGMSG_PACK1, SIGMSG_PACK2, SIGMSG_PACK3
# define SIGMSG_REPACK2	SIGMSG_PACK4, SIGMSG_PACK5, SIGMSG_PACK6
# define SIGMSG_REPACK3	SIGMSG_PACK7

# define SIGMSG_COUNT	32
# define SIGMSG_REPACK	SIGMSG_REPACK1, SIGMSG_REPACK2, SIGMSG_REPACK3

#endif
