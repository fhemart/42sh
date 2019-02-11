/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets_proto.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:58:43 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/23 16:59:05 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRACKETS_PROTO_H
# define BRACKETS_PROTO_H

# define PROTO_PARENTHESES	"(", ")"
# define PROTO_BRACES		"{", "}"
# define PROTO_SQRBRACKETS	"[", "]"
# define PROTO_DQUOTES		"\"", "\""
# define PROTO_BQUOTES		"`", "`"
# define PROTO_QUOTES		"'", "'"

# define EXPMATCH_ALLBRACKETS	"({["
# define EXPMATCH_ALLQUOTES		"\"'`"
# define EXPMATCH_ALL			EXPMATCH_ALLBRACKETS EXPMATCH_ALLQUOTES

# define ALL_BP1	PROTO_PARENTHESES, EXPMATCH_ALL, PROTO_BRACES, EXPMATCH_ALL
# define ALL_BP2	PROTO_SQRBRACKETS, EXPMATCH_ALL
# define ALL_BRACKPROTO		ALL_BP1, ALL_BP2

# define ALL_QP1	PROTO_DQUOTES, EXPMATCH_ALL, PROTO_BQUOTES, EXPMATCH_ALL
# define ALL_QP2	PROTO_QUOTES, EXPMATCH_ALL
# define ALL_QUOTESPROTO	ALL_QP1, ALL_QP2

# define ALL_PROTO			ALL_BRACKPROTO, ALL_QUOTESPROTO

# define PROTO_COUNT		6

#endif
