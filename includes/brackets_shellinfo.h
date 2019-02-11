/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets_shellinfo.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 05:21:45 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/13 21:50:13 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRACKETS_SHELLINFO_H
# define BRACKETS_SHELLINFO_H

# include "brackets.h"
# include "brackets_proto.h"

# define DOLLAR_PAR			"$(", ")"
# define DOLLAR_BRACES		"${", "}"

# define SHBRINF_1		DOLLAR_PAR, "$`('\\\""
# define SHBRINF_1S		"cmdsubst"
# define SHBRINF_2		DOLLAR_BRACES, "$`'\\\""
# define SHBRINF_2S		"braceparam"
# define SHBRINF_3		PROTO_PARENTHESES, EXPMATCH_ALL "\\$"
# define SHBRINF_3S		"subsh"
# define SHBRINF_4		PROTO_BRACES, "$`'\\\""
# define SHBRINF_4S		"cursh"
# define SHBRINF_5		PROTO_SQRBRACKETS, "$`'\\\""
# define SHBRINF_5S		""
# define SHBRINF_6		PROTO_DQUOTES, "$\\`"
# define SHBRINF_6S		"dquote"
# define SHBRINF_7		PROTO_BQUOTES, "\\`"
# define SHBRINF_7S		"bquote"
# define SHBRINF_8		PROTO_QUOTES, ""
# define SHBRINF_8S		"quote"

# define SHBRINF_T1		SHBRINF_1, SHBRINF_2, SHBRINF_3, SHBRINF_4, SHBRINF_5
# define SHBRINF_T2		SHBRINF_6, SHBRINF_7, SHBRINF_8
# define SHBRINF_T3
# define ALL_SHBRINF	SHBRINF_T1, SHBRINF_T2

# define SHBRINF_S1		SHBRINF_1S, SHBRINF_2S, SHBRINF_3S, SHBRINF_4S
# define SHBRINF_S2		SHBRINF_5S, SHBRINF_6S, SHBRINF_7S, SHBRINF_8S
# define SHBRINF_S3
# define SHBRINFNAMES	SHBRINF_S1, SHBRINF_S2, SHBRINF_S3

# define SH_BRINFO_COUNT		8

#endif
