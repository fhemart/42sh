/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_tkn_grammar.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 20:16:22 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 19:36:26 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_TKN_GRAMMAR_H
# define INPUT_TKN_GRAMMAR_H

# include "ft_tkn_type.h"
# include "token_charsets/input_tkn_chrset.h"
# include "token_charsets/input_grammar_reducters.h"
# include "token_charsets/input_grammar_struct.h"

# define IUSER_STARTING_EXPR	E_COMPLETE_COMMAND

/*
**	|-************************************************************************-|
**	|-*				  	    IUSER GRAMMAR EXPRESSIONS						 *-|
**	|-************************************************************************-|
*/

# define E_SIMPLE_COMMAND			TEXP_VAL(0)
# define IUE_1		{IUE_1_0, IUE_1_1, NULL, NULL, IUE_1_3, IUE_1_4}
# define IUE_1S		"simple_command"
# define IUE_1_0	E_SIMPLE_COMMAND
# define IUE_1_1	5
# define IUE_1_2	IUE_1_21, IUE_1_22, IUE_1_23
# define IUE_1_21	TEXP_GLINE3(IUE_1_2A), TEXP_GLINE2(IUE_1_2B)
# define IUE_1_22	TEXP_GLINE1(IUE_1_2C), TEXP_GLINE2(IUE_1_2D)
# define IUE_1_23	TEXP_GLINE1(IUE_1_2E)
# define IUE_1_2A	E_CMD_PREFIX, E_CMD_WORD, E_CMD_SUFFIX
# define IUE_1_2B	E_CMD_PREFIX, E_CMD_WORD
# define IUE_1_2C	E_CMD_PREFIX
# define IUE_1_2D	E_CMD_NAME, E_CMD_SUFFIX
# define IUE_1_2E	E_CMD_NAME
# define IUE_1_3	reduce_simple_command
# define IUE_1_4	CLEANERCAST(del_command)

# define E_CMD_NAME					TEXP_VAL(1)
# define IUE_2		{IUE_2_0, IUE_2_1, NULL, NULL, IUE_2_3, IUE_2_4}
# define IUE_2S		"cmd_name"
# define IUE_2_0	E_CMD_NAME
# define IUE_2_1	1
# define IUE_2_2	TEXP_GLINE1(IUE_2_2A)
# define IUE_2_2A	TWORD
# define IUE_2_3	reduce_cmd_name
# define IUE_2_4	CLEANERCAST(del_command)

# define E_CMD_SUFFIX				TEXP_VAL(2)
# define IUE_3		{IUE_3_0, IUE_3_1, NULL, NULL, IUE_3_3, IUE_3_4}
# define IUE_3S		"cmd_suffix"
# define IUE_3_0	E_CMD_SUFFIX
# define IUE_3_1	4
# define IUE_3_2	IUE_3_21, IUE_3_22
# define IUE_3_21	TEXP_GLINE1(IUE_3_2A), TEXP_GLINE2(IUE_3_2B)
# define IUE_3_22	TEXP_GLINE1(IUE_3_2C), TEXP_GLINE2(IUE_3_2D)
# define IUE_3_2A				  E_IO_REDIRECT
# define IUE_3_2B	E_CMD_SUFFIX, E_IO_REDIRECT
# define IUE_3_2C				  TWORD
# define IUE_3_2D	E_CMD_SUFFIX, TWORD
# define IUE_3_3	reduce_cmd_suffix
# define IUE_3_4	NULL

# define E_SEPARATOR_OP				TEXP_VAL(3)
# define IUE_4		{IUE_4_0, IUE_4_1, NULL, NULL, IUE_4_3, IUE_4_4}
# define IUE_4S		"separator_op"
# define IUE_4_0	E_SEPARATOR_OP
# define IUE_4_1	1
# define IUE_4_2	TEXP_GLINE1(IUE_4_2A)
# define IUE_4_2A	TSEMICOLON
# define IUE_4_3	reduce_separator_op
# define IUE_4_4	NULL

# define E_SEPARATOR				TEXP_VAL(4)
# define IUE_5		{IUE_5_0, IUE_5_1, NULL, NULL, IUE_5_3, IUE_5_4}
# define IUE_5S		"separator"
# define IUE_5_0	E_SEPARATOR
# define IUE_5_1	3
# define IUE_5_2	IUE_5_21, IUE_5_22
# define IUE_5_21	TEXP_GLINE1(IUE_5_2A), TEXP_GLINE2(IUE_5_2B)
# define IUE_5_22	TEXP_GLINE1(IUE_5_2C)
# define IUE_5_2A	E_SEPARATOR_OP
# define IUE_5_2B	E_SEPARATOR_OP, E_LINEBREAK
# define IUE_5_2C	E_NEWLINE_LIST
# define IUE_5_3	reduce_separator
# define IUE_5_4	NULL

# define E_COMMAND					TEXP_VAL(5)
# define IUE_6		{IUE_6_0, IUE_6_1, NULL, NULL, IUE_6_3, IUE_6_4}
# define IUE_6S		"command"
# define IUE_6_0	E_COMMAND
# define IUE_6_1	3
# define IUE_6_2	IUE_6_21, IUE_6_22
# define IUE_6_21	TEXP_GLINE1(IUE_6_2A), TEXP_GLINE1(IUE_6_2B)
# define IUE_6_22	TEXP_GLINE2(IUE_6_2C)
# define IUE_6_2A	E_SIMPLE_COMMAND
# define IUE_6_2B	E_COMPOUND_COMMAND
# define IUE_6_2C	E_COMPOUND_COMMAND, E_REDIRECT_LIST
# define IUE_6_3	reduce_command
# define IUE_6_4	CLEANERCAST(del_command)

# define E_COMPLETE_COMMAND			TEXP_VAL(6)
# define IUE_7		{IUE_7_0, IUE_7_1, NULL, NULL, IUE_7_3, IUE_7_4}
# define IUE_7S		"complete_command"
# define IUE_7_0	E_COMPLETE_COMMAND
# define IUE_7_1	2
# define IUE_7_2	TEXP_GLINE3(IUE_7_2A), TEXP_GLINE2(IUE_7_2B)
# define IUE_7_2A	E_LIST, E_SEPARATOR
# define IUE_7_2B	E_LIST, E_LINEBREAK
# define IUE_7_3	reduce_complete_command
# define IUE_7_4	CLEANERCAST(del_inputlist)

# define E_LIST						TEXP_VAL(7)
# define IUE_8		{IUE_8_0, IUE_8_1, NULL, NULL, IUE_8_3, IUE_8_4}
# define IUE_8S		"list"
# define IUE_8_0	E_LIST
# define IUE_8_1	2
# define IUE_8_2	TEXP_GLINE3(IUE_8_2A), TEXP_GLINE1(IUE_8_2B)
# define IUE_8_2A	E_LIST, E_SEPARATOR, E_AND_OR
# define IUE_8_2B						E_AND_OR
# define IUE_8_3	reduce_list
# define IUE_8_4	CLEANERCAST(del_inputlist)

# define E_AND_OR					TEXP_VAL(8)
# define IUE_9		{IUE_9_0, IUE_9_1, NULL, NULL, IUE_9_3, IUE_9_4}
# define IUE_9S		"and_or"
# define IUE_9_0	E_AND_OR
# define IUE_9_1	3
# define IUE_9_2	IUE_9_21, IUE_9_22
# define IUE_9_21	TEXP_GLINE1(IUE_9_2A), TEXP_GLINE4(IUE_9_2B)
# define IUE_9_22	TEXP_GLINE4(IUE_9_2C)
# define IUE_9_2A									E_PIPELINE
# define IUE_9_2B	E_AND_OR, TAND_IF, E_LINEBREAK, E_PIPELINE
# define IUE_9_2C	E_AND_OR,  TOR_IF, E_LINEBREAK, E_PIPELINE
# define IUE_9_3	reduce_and_or
# define IUE_9_4	CLEANERCAST(del_andor)

# define E_IO_REDIRECT				TEXP_VAL(9)
# define IUE_10		{IUE_10_0, IUE_10_1, NULL, NULL, IUE_10_3, IUE_10_4}
# define IUE_10S	"io_redirect"
# define IUE_10_0	E_IO_REDIRECT
# define IUE_10_1	4
# define IUE_10_2	IUE_10_21, IUE_10_22
# define IUE_10_21	TEXP_GLINE2(IUE_10_2A), TEXP_GLINE1(IUE_10_2B)
# define IUE_10_22	TEXP_GLINE2(IUE_10_2C), TEXP_GLINE1(IUE_10_2D)
# define IUE_10_2A	TIONUMBER, E_IO_FILE
# define IUE_10_2B			   E_IO_FILE
# define IUE_10_2C	TIONUMBER, E_IO_HERE
# define IUE_10_2D			   E_IO_HERE
# define IUE_10_3	reduce_io_redirect
# define IUE_10_4	CLEANERCAST(del_iocontent)

# define E_IO_FILE					TEXP_VAL(10)
# define IUE_11		{IUE_11_0, IUE_11_1, NULL, NULL, IUE_11_3, IUE_11_4}
# define IUE_11S	"io_file"
# define IUE_11_0	E_IO_FILE
# define IUE_11_1	5
# define IUE_11_2	IUE_11_21, IUE_11_22, IUE_11_23
# define IUE_11_21	TEXP_GLINE2(IUE_11_2A), TEXP_GLINE2(IUE_11_2B)
# define IUE_11_22	TEXP_GLINE2(IUE_11_2C), TEXP_GLINE2(IUE_11_2D)
# define IUE_11_23	TEXP_GLINE2(IUE_11_2E)
# define IUE_11_2A		 TLESS, E_FILENAME
# define IUE_11_2B	  TLESSAND, E_FILENAME
# define IUE_11_2C		TGREAT, E_FILENAME
# define IUE_11_2D	 TGREATAND, E_FILENAME
# define IUE_11_2E	   TDGREAT, E_FILENAME
# define IUE_11_3	reduce_io_file
# define IUE_11_4	CLEANERCAST(del_iocontent)

# define E_FILENAME					TEXP_VAL(11)
# define IUE_12		{IUE_12_0, IUE_12_1, NULL, NULL, IUE_12_3, IUE_12_4}
# define IUE_12S	"filename"
# define IUE_12_0	E_FILENAME
# define IUE_12_1	1
# define IUE_12_2	TEXP_GLINE1(IUE_12_2A)
# define IUE_12_2A	TWORD
# define IUE_12_3	reduce_filename
# define IUE_12_4	CLEANERCAST(ft_memdel)

# define E_IO_HERE					TEXP_VAL(12)
# define IUE_13		{IUE_13_0, IUE_13_1, NULL, NULL, IUE_13_3, IUE_13_4}
# define IUE_13S	"io_here"
# define IUE_13_0	E_IO_HERE
# define IUE_13_1	2
# define IUE_13_2	TEXP_GLINE2(IUE_13_2A), TEXP_GLINE2(IUE_13_2B)
# define IUE_13_2A		TDLESS, E_HERE_END
# define IUE_13_2B	TDLESSDASH, E_HERE_END
# define IUE_13_3	reduce_io_here
# define IUE_13_4	CLEANERCAST(del_iocontent)

# define E_HERE_END					TEXP_VAL(13)
# define IUE_14		{IUE_14_0, IUE_14_1, NULL, NULL, IUE_14_3, IUE_14_4}
# define IUE_14S	"here_end"
# define IUE_14_0	E_HERE_END
# define IUE_14_1	1
# define IUE_14_2	TEXP_GLINE1(IUE_14_2A)
# define IUE_14_2A	TWORD
# define IUE_14_3	reduce_here_end
# define IUE_14_4	CLEANERCAST(ft_memdel)

# define E_PIPELINE					TEXP_VAL(14)
# define IUE_15		{IUE_15_0, IUE_15_1, NULL, NULL, IUE_15_3, IUE_15_4}
# define IUE_15S	"pipeline"
# define IUE_15_0	E_PIPELINE
# define IUE_15_1	2
# define IUE_15_2	TEXP_GLINE1(IUE_15_2A), TEXP_GLINE4(IUE_15_2B)
# define IUE_15_2A									E_COMMAND
# define IUE_15_2B	E_PIPELINE, TPIPE, E_LINEBREAK, E_COMMAND
# define IUE_15_3	reduce_pipeline
# define IUE_15_4	CLEANERCAST(del_pipeline)

# define E_CMD_PREFIX				TEXP_VAL(15)
# define IUE_16		{IUE_16_0, IUE_16_1, NULL, NULL, IUE_16_3, IUE_16_4}
# define IUE_16S	"cmd_prefix"
# define IUE_16_0	E_CMD_PREFIX
# define IUE_16_1	2
# define IUE_16_2	TEXP_GLINE1(IUE_16_2A), TEXP_GLINE2(IUE_16_2B)
# define IUE_16_2A				  E_IO_REDIRECT
# define IUE_16_2B	E_CMD_PREFIX, E_IO_REDIRECT
# define IUE_16_3	reduce_cmd_prefix
# define IUE_16_4	CLEANERCAST(del_command)

# define E_CMD_WORD					TEXP_VAL(16)
# define IUE_17		{IUE_17_0, IUE_17_1, NULL, NULL, IUE_17_3, IUE_17_4}
# define IUE_17S	"cmd_word"
# define IUE_17_0	E_CMD_WORD
# define IUE_17_1	1
# define IUE_17_2	TEXP_GLINE1(IUE_17_2A)
# define IUE_17_2A	TWORD
# define IUE_17_3	reduce_cmd_word
# define IUE_17_4	NULL

# define E_LINEBREAK				TEXP_VAL(17)
# define IUE_18		{IUE_18_0, IUE_18_1, NULL, NULL, IUE_18_3, IUE_18_4}
# define IUE_18S	"linebreak"
# define IUE_18_0	E_LINEBREAK
# define IUE_18_1	2
# define IUE_18_2	TEXP_GLINE1(IUE_18_2A), TEXP_EMPTY
# define IUE_18_2A	E_NEWLINE_LIST
# define IUE_18_3	reduce_linebreak
# define IUE_18_4	NULL

# define E_NEWLINE_LIST				TEXP_VAL(18)
# define IUE_19		{IUE_19_0, IUE_19_1, NULL, NULL, IUE_19_3, IUE_19_4}
# define IUE_19S	"newline_list"
# define IUE_19_0	E_NEWLINE_LIST
# define IUE_19_1	2
# define IUE_19_2	TEXP_GLINE1(IUE_19_2A), TEXP_GLINE2(IUE_19_2B)
# define IUE_19_2A					TNEWLINE
# define IUE_19_2B	E_NEWLINE_LIST, TNEWLINE
# define IUE_19_3	reduce_newline_list
# define IUE_19_4	NULL

# define E_COMPOUND_COMMAND			TEXP_VAL(19)
# define IUE_20		{IUE_20_0, IUE_20_1, NULL, NULL, IUE_20_3, IUE_20_4}
# define IUE_20S	"compound_command"
# define IUE_20_0	E_COMPOUND_COMMAND
# define IUE_20_1	1
# define IUE_20_2	TEXP_GLINE1(IUE_20_2A)
# define IUE_20_2A	E_SUBSHELL
# define IUE_20_3	reduce_compound_command
# define IUE_20_4	CLEANERCAST(del_command)

# define E_SUBSHELL					TEXP_VAL(20)
# define IUE_21		{IUE_21_0, IUE_21_1, NULL, NULL, IUE_21_3, IUE_21_4}
# define IUE_21S	"subshell"
# define IUE_21_0	E_SUBSHELL
# define IUE_21_1	1
# define IUE_21_2	TEXP_GLINE4(IUE_21_2A)
# define IUE_21_2A	TLPAR, E_LINEBREAK, E_COMPOUND_LIST, TRPAR
# define IUE_21_3	reduce_subshell
# define IUE_21_4	CLEANERCAST(del_command)

# define E_COMPOUND_LIST			TEXP_VAL(21)
# define IUE_22		{IUE_22_0, IUE_22_1, NULL, NULL, IUE_22_3, IUE_22_4}
# define IUE_22S	"compound_list"
# define IUE_22_0	E_COMPOUND_LIST
# define IUE_22_1	4
# define IUE_22_2	IUE_22_21, IUE_22_22
# define IUE_22_21	TEXP_GLINE1(IUE_22_2A), TEXP_GLINE2(IUE_22_2B)
# define IUE_22_22	TEXP_GLINE2(IUE_22_2C), TEXP_GLINE3(IUE_22_2D)
# define IUE_22_2A					E_TERM
# define IUE_22_2B	E_NEWLINE_LIST, E_TERM
# define IUE_22_2C					E_TERM, E_SEPARATOR
# define IUE_22_2D	E_NEWLINE_LIST, E_TERM, E_SEPARATOR
# define IUE_22_3	reduce_compound_list
# define IUE_22_4	CLEANERCAST(del_inputlist)

# define E_TERM						TEXP_VAL(22)
# define IUE_23		{IUE_23_0, IUE_23_1, NULL, NULL, IUE_23_3, IUE_23_4}
# define IUE_23S	"term"
# define IUE_23_0	E_TERM
# define IUE_23_1	3
# define IUE_23_2	IUE_23_21, IUE_23_22
# define IUE_23_21	TEXP_GLINE4(IUE_23_2A), TEXP_GLINE3(IUE_23_2B)
# define IUE_23_22	TEXP_GLINE1(IUE_23_2C)
# define IUE_23_2A	E_TERM, E_SEPARATOR, E_LINEBREAK, E_AND_OR
# define IUE_23_2B	E_TERM, E_SEPARATOR, E_LINEBREAK
# define IUE_23_2C									E_AND_OR
# define IUE_23_3	reduce_list
# define IUE_23_4	CLEANERCAST(del_inputlist)

# define E_REDIRECT_LIST			TEXP_VAL(23)
# define IUE_24		{IUE_24_0, IUE_24_1, NULL, NULL, IUE_24_3, IUE_24_4}
# define IUE_24S	"redirect list"
# define IUE_24_0	E_REDIRECT_LIST
# define IUE_24_1	2
# define IUE_24_2	TEXP_GLINE1(IUE_24_2A), TEXP_GLINE2(IUE_24_2B)
# define IUE_24_2A					E_IO_REDIRECT
# define IUE_24_2B	E_REDIRECT_LIST, E_IO_REDIRECT
# define IUE_24_3	reduce_rdlist
# define IUE_24_4	CLEANERCAST(del_iocontent)

# define IUSER_EXPR_COUNT	TEXP_COUNT(24)

# define IUSER_EXPR_STR	IU_ES1, IU_ES2, IU_ES3, IU_ES4
# define IU_ES1		IUE_1S, IUE_2S, IUE_3S, IUE_4S, IUE_5S, IUE_6S, IUE_7S
# define IU_ES2		IUE_8S, IUE_9S, IUE_10S, IUE_11S, IUE_12S, IUE_13S, IUE_14S
# define IU_ES3		IUE_15S, IUE_16S, IUE_17S, IUE_18S, IUE_19S, IUE_20S
# define IU_ES4		IUE_21S, IUE_22S, IUE_23S, IUE_24S

# define IUSER_EXPR_LIST	TEXP_TEMPLATES(IUSER_EX_TOTAL)
# define IUSER_EX_TOTAL	IU_E_T1, IU_E_T2, IU_E_T3, IU_E_T4
# define IU_E_T1	IUE_1, IUE_2, IUE_3, IUE_4, IUE_5, IUE_6, IUE_7, IUE_8
# define IU_E_T2	IUE_9, IUE_10, IUE_11, IUE_12, IUE_13, IUE_14, IUE_15
# define IU_E_T3	IUE_16, IUE_17, IUE_18, IUE_19, IUE_20, IUE_21, IUE_22
# define IU_E_T4	IUE_23, IUE_24

# define IUSER_GRAMMAR_SIZE	IU_GS1 + IU_GS2 + IU_GS3 + IU_GS4 + IU_GS5
# define IU_GS1		IUE_1_1 + IUE_2_1 + IUE_3_1 + IUE_4_1 + IUE_5_1 + IUE_6_1
# define IU_GS2		IUE_7_1 + IUE_8_1 + IUE_9_1 + IUE_10_1 + IUE_11_1 + IUE_12_1
# define IU_GS3		IUE_13_1 + IUE_14_1 + IUE_15_1 + IUE_16_1 + IUE_17_1
# define IU_GS4		IUE_18_1 + IUE_19_1 + IUE_20_1 + IUE_21_1 + IUE_22_1
# define IU_GS5		IUE_23_1 + IUE_24_1

# define IUSER_GRAMMAR_LIST	IU_GL1, IU_GL2, IU_GL3, IU_GL4, IU_GL5
# define IU_GL1		IUE_1_2, IUE_2_2, IUE_3_2, IUE_4_2, IUE_5_2, IUE_6_2
# define IU_GL2		IUE_7_2, IUE_8_2, IUE_9_2, IUE_10_2, IUE_11_2, IUE_12_2
# define IU_GL3		IUE_13_2, IUE_14_2, IUE_15_2, IUE_16_2, IUE_17_2
# define IU_GL4		IUE_18_2, IUE_19_2, IUE_20_2, IUE_21_2, IUE_22_2, IUE_23_2
# define IU_GL5		IUE_24_2

#endif
