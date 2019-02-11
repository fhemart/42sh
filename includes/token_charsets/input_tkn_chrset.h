/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_tkn_chrset.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 05:59:13 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 19:36:09 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_TKN_CHRSET_H
# define INPUT_TKN_CHRSET_H

# include "ft_tkn_type.h"

# define IUSER_TOKEN_LIST	T_TEMPLATES(IU_TOTAL)

/*
**	|-************************************************************************-|
**	|-*					    IUSER GRAMMAR TOKENS							 *-|
**	|-************************************************************************-|
**	|-*   IU_[x]   * *	the complete token structure						 *-|
**	|-************************************************************************-|
**	|-*  IU_[x]_0  * *	value												 *-|
**	|-*  IU_[x]_1  * *	symbol												 *-|
**	|-*  IU_[x]_2  * *	symbol size											 *-|
**	|-*  IU_[x]_3  * *	the instruction given with the token				 *-|
**	|-************************************************************************-|
*/

# define IU_1		{IU_1_0, IU_1_1, IU_1_2, IU_1_3}
# define IU_1S		" "
# define TSPACE					0
# define IU_1_0		TLPAR
# define IU_1_1		" "
# define IU_1_2		1
# define IU_1_3		TT_OPERATOR_RIGHTHANDED

# define IU_2		{IU_2_0, IU_2_1, IU_2_2, IU_2_3}
# define IU_2S		"\t"
# define TTAB					1
# define IU_2_0		TRPAR
# define IU_2_1		"\t"
# define IU_2_2		1
# define IU_2_3		TT_OPERATOR_LEFTHANDED

# define IU_3		{IU_3_0, IU_3_1, IU_3_2, IU_3_3}
# define IU_3S		"newline"
# define TNEWLINE				2
# define IU_3_0		TNEWLINE
# define IU_3_1		"\n"
# define IU_3_2		1
# define IU_3_3		TT_COMMON

# define IU_4		{IU_4_0, IU_4_1, IU_4_2, IU_4_3}
# define IU_4S		";"
# define TSEMICOLON				3
# define IU_4_0		TSEMICOLON
# define IU_4_1		";"
# define IU_4_2		1
# define IU_4_3		TT_OPERATOR_LEFTHANDED

# define IU_5		{IU_5_0, IU_5_1, IU_5_2, IU_5_3}
# define IU_5S		"&&"
# define TAND_IF				4
# define IU_5_0		TAND_IF
# define IU_5_1		"&&"
# define IU_5_2		2
# define IU_5_3		TT_OPERATOR_TWOSIDED

# define IU_6		{IU_6_0, IU_6_1, IU_6_2, IU_6_3}
# define IU_6S		">>"
# define TDGREAT				5
# define IU_6_0		TDGREAT
# define IU_6_1		">>"
# define IU_6_2		2
# define IU_6_3		TT_OPERATOR_RIGHTHANDED

# define IU_7		{IU_7_0, IU_7_1, IU_7_2, IU_7_3}
# define IU_7S		">&"
# define TGREATAND				6
# define IU_7_0		TGREATAND
# define IU_7_1		">&"
# define IU_7_2		2
# define IU_7_3		TT_OPERATOR_RIGHTHANDED

# define IU_8		{IU_8_0, IU_8_1, IU_8_2, IU_8_3}
# define IU_8S		">"
# define TGREAT					7
# define IU_8_0		TGREAT
# define IU_8_1		">"
# define IU_8_2		1
# define IU_8_3		TT_OPERATOR_RIGHTHANDED

# define IU_9		{IU_9_0, IU_9_1, IU_9_2, IU_9_3}
# define IU_9S		"<<-"
# define TDLESSDASH				8
# define IU_9_0		TDLESSDASH
# define IU_9_1		"<<-"
# define IU_9_2		3
# define IU_9_3		TT_OPERATOR_RIGHTHANDED

# define IU_10		{IU_10_0, IU_10_1, IU_10_2, IU_10_3}
# define IU_10S		"<<"
# define TDLESS					9
# define IU_10_0	TDLESS
# define IU_10_1	"<<"
# define IU_10_2	2
# define IU_10_3	TT_OPERATOR_RIGHTHANDED

# define IU_11		{IU_11_0, IU_11_1, IU_11_2, IU_11_3}
# define IU_11S		"<&"
# define TLESSAND				10
# define IU_11_0	TLESSAND
# define IU_11_1	"<&"
# define IU_11_2	2
# define IU_11_3	TT_OPERATOR_RIGHTHANDED

# define IU_12		{IU_12_0, IU_12_1, IU_12_2, IU_12_3}
# define IU_12S		"<"
# define TLESS					11
# define IU_12_0	TLESS
# define IU_12_1	"<"
# define IU_12_2	1
# define IU_12_3	TT_OPERATOR_RIGHTHANDED

# define IU_13		{IU_13_0, IU_13_1, IU_13_2, IU_13_3}
# define IU_13S		"||"
# define TOR_IF					12
# define IU_13_0	TOR_IF
# define IU_13_1	"||"
# define IU_13_2	2
# define IU_13_3	TT_OPERATOR_TWOSIDED

# define IU_14		{IU_14_0, IU_14_1, IU_14_2, IU_14_3}
# define IU_14S		"|"
# define TPIPE					13
# define IU_14_0	TPIPE
# define IU_14_1	"|"
# define IU_14_2	1
# define IU_14_3	TT_OPERATOR_TWOSIDED

# define IU_15		{IU_15_0, IU_15_1, IU_15_2, IU_15_3}
# define IU_15S		"("
# define TLPAR					14
# define IU_15_0	TLPAR
# define IU_15_1	"("
# define IU_15_2	1
# define IU_15_3	TT_OPERATOR_RIGHTHANDED

# define IU_16		{IU_16_0, IU_16_1, IU_16_2, IU_16_3}
# define IU_16S		")"
# define TRPAR					15
# define IU_16_0		TRPAR
# define IU_16_1		")"
# define IU_16_2		1
# define IU_16_3		TT_OPERATOR_LEFTHANDED

# define IUSER_TOKEN_COUNT	T_COUNT(16)

# define IU_TOTAL	IU_T1, IU_T2
# define IU_T1		IU_1, IU_2, IU_3, IU_4, IU_5, IU_6, IU_7, IU_8, IU_9
# define IU_T2		IU_10, IU_11, IU_12, IU_13, IU_14, IU_15, IU_16

# define TKN_STRVAL TKN_SV1, TKN_SV2, TKN_SV3
# define TKN_SV1	IU_1S, IU_2S, IU_3S, IU_4S, IU_5S, IU_6S, IU_7S, IU_8S
# define TKN_SV2	IU_9S, IU_10S, IU_11S, IU_12S, IU_13S, IU_14S, IU_15S
# define TKN_SV3	IU_16S, "WORD", "IONUMBER", "ASSIGNMENT_WORD", "NAME"

# define TWORD				IUSER_TOKEN_COUNT - 1
# define TIONUMBER			IUSER_TOKEN_COUNT
# define TASSIGNMENT_WORD	IUSER_TOKEN_COUNT + 1
# define TNAME				IUSER_TOKEN_COUNT + 2

# define IUSER_T_COUNT_NAME	IUSER_TOKEN_COUNT + 3

#endif
