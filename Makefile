NAME = 42sh

LINUX = 0
DEBUG = 0
PRINTHEAD = 0
LEAKS = 0

LIBFTDIR = libft/

FT_BRACKETEERDIR = $(LIBFTDIR)srcs/ft_bracketeer/
FT_STRINGSDIR = $(LIBFTDIR)srcs/ft_strings/
FT_STACKDIR   = $(LIBFTDIR)srcs/ft_stack/
FT_QUEUEDIR   = $(LIBFTDIR)srcs/ft_queue/
FT_POOLDIR    = $(LIBFTDIR)srcs/ft_pool/
FT_DICTIONARYDIR    = $(LIBFTDIR)srcs/ft_dictionary/
FT_HASHTABLEDIR    = $(LIBFTDIR)srcs/ft_hashtable/
FT_TERMCAP = $(LIBFTDIR)srcs/ft_termcap/

LIBFT_NAME = libft.a

LIBFT = $(LIBFTDIR)$(LIBFT_NAME)

SRCS_DIR =	\
			errormsgs \
			tools \
			builtins \
			builtins/alias \
			builtins/cd \
			builtins/echo \
			builtins/exit \
			builtins/env \
			builtins/env/tools \
			builtins/pwd \
			builtins/history \
			builtins/history/tools \
			builtins/set \
			builtins/snake/draw \
			builtins/snake/graphic \
			builtins/snake/init \
			builtins/snake/mechanics \
			builtins/snake/tc \
			builtins/snake/update \
			builtins/snake \
			fs \
			ft_exec \
			ft_exec/pipeline \
			ft_exec/cookedio \
			ft_exec/cookedcmd \
			ft_exec/cookedcmd/argv \
			ft_exec/cookedcmd/argv/cmd_subst \
			ft_iuser \
			ft_iuser/tlex \
			ft_iuser/histexpand \
			ft_iuser/grammar_structs \
			ft_iuser/reducters \
			ft_tlex \
			ft_tlex/op_compatibility_mode \
			ft_tlex/tools \
			ft_tlex/tools/error \
			ft_tlex/tools/source_feeder \
			ft_tlex/tools/tokens \
			ft_tlex/tools/words \
			ft_tlex/tools/words/quoting \
			ft_tlex/tools/words/polisher \
			ft_zebu \
			ft_zebu/core \
			ft_zebu/core/init \
			ft_zebu/core/tools \
			ft_zebu/core/tools/analyzis \
			ft_zebu/core/tools/blacklist \
			ft_zebu/core/tools/expr \
			ft_zebu/core/tools/others \
			ft_zebu/tools \
			ft_zebu/tools/substates \
			shdata \
			hashtable \
			autocomplete \
			dictionary \
			terminal \
			terminal/controls \
			tmp

SRCS_NAME = \
			main.c \
			$(SHDATA_SRCS) \
			$(FS_SRCS) \
			$(FT_IUSER_SRCS) \
			$(BUILTINS_SRCS) \
			$(FT_EXEC_SRCS) \
			$(TLEX_SRCS) \
			$(ZEBU_SRC) \
			$(TERMINAL_SRCS) \
			$(TOOLS_SRCS) \
			$(AUTOCOMPLETE_SRCS) \
			$(DICTIONARY_SRCS) \
			$(ERRORMSGS_SRCS)

FS_SRCS = \
			fs/get_file_content.c

SHDATA_SRCS = \
			shdata/exit_shell.c \
			shdata/init_shell_data.c \
			shdata/init_shell_history.c \
			shdata/init_shell_info.c \
			shdata/init_shell_env.c \
			shdata/shdata_destroy.c \
			shdata/signal.c

FT_IUSER_SRCS = \
			ft_iuser/br_display_ps2.c \
			ft_iuser/clean_input.c \
			ft_iuser/display_ps1.c \
			ft_iuser/get_inputline.c \
			ft_iuser/gnl_mode.c \
			ft_iuser/get_sh_brdata.c \
			ft_iuser/iuser_refill_src_ps2.c \
			ft_iuser/new_iuser.c \
			\
			ft_iuser/tlex/get_iuser_tlex.c \
			ft_iuser/tlex/get_iuser_expressions.c \
			ft_iuser/tlex/get_iuser_grammar.c \
			\
			ft_iuser/histexpand/get_event_word.c \
			ft_iuser/histexpand/get_event.c \
			ft_iuser/histexpand/get_hist_tlex.c \
			ft_iuser/histexpand/get_histexpand.c \
			ft_iuser/histexpand/get_modifiers.c \
			ft_iuser/histexpand/get_next_modtype.c \
			ft_iuser/histexpand/get_word_laststr.c \
			ft_iuser/histexpand/get_words_replace.c \
			ft_iuser/histexpand/get_words.c \
			ft_iuser/histexpand/hexp_errors.c \
			ft_iuser/histexpand/pmod_p1.c \
			ft_iuser/histexpand/pmod_p2.c \
			ft_iuser/histexpand/pmod_p3.c \
			ft_iuser/histexpand/print_and_save_line.c \
			ft_iuser/histexpand/update_line.c \
			ft_iuser/histexpand/wordq_replace.c \
			\
			ft_iuser/grammar_structs/del_grammar_structs_p1.c \
			ft_iuser/grammar_structs/del_grammar_structs_p2.c \
			ft_iuser/grammar_structs/del_grammar_structs_p3.c \
			ft_iuser/grammar_structs/new_grammar_structs_p1.c \
			ft_iuser/grammar_structs/new_grammar_structs_p2.c \
			\
			ft_iuser/reducters/clean_expr_overage.c \
			ft_iuser/reducters/reduce_and_or.c \
			ft_iuser/reducters/reduce_cmd_name.c \
			ft_iuser/reducters/reduce_cmd_prefix.c \
			ft_iuser/reducters/reduce_cmd_suffix.c \
			ft_iuser/reducters/reduce_cmd_word.c \
			ft_iuser/reducters/reduce_command.c \
			ft_iuser/reducters/reduce_complete_command.c \
			ft_iuser/reducters/reduce_filename.c \
			ft_iuser/reducters/reduce_here_end.c \
			ft_iuser/reducters/reduce_inputlist.c \
			ft_iuser/reducters/reduce_io_file.c \
			ft_iuser/reducters/reduce_io_here.c \
			ft_iuser/reducters/reduce_io_redirect.c \
			ft_iuser/reducters/reduce_pipeline.c \
			ft_iuser/reducters/reduce_linebreak.c \
			ft_iuser/reducters/reduce_newline_list.c \
			ft_iuser/reducters/reduce_separator_op.c \
			ft_iuser/reducters/reduce_separator.c \
			ft_iuser/reducters/reduce_simple_command.c \
			ft_iuser/reducters/reduce_compound_command.c \
			ft_iuser/reducters/reduce_subshell.c \
			ft_iuser/reducters/reduce_compound_list.c \
			ft_iuser/reducters/reduce_rdlist.c \
			ft_iuser/reducters/remove_opexpr.c \

TERMINAL_SRCS = \
			terminal/close_tc.c \
			terminal/term_hist_tools.c \
			terminal/get_ttyline.c\
			terminal/init_tc.c \
			terminal/init_tc_data.c \
			terminal/controls/control_tab.c \
			terminal/controls/ft_control_enter.c \
			terminal/controls/get_controls.c

TOOLS_SRCS = \
			tools/ft_getopt.c \
			tools/check_opt.c \
			\
			hashtable/hashtable_destroy_content.c \
			hashtable/hashtable_new_content.c

AUTOCOMPLETE_SRCS = \
			autocomplete/tab_space.c \
			autocomplete/tab_quote.c \
			autocomplete/tab_semico.c \
			autocomplete/tab_backtick.c \
			autocomplete/tab_backslash.c \
			autocomplete/tab_load.c \
			autocomplete/tab_request.c \
			autocomplete/tab_next.c \
			autocomplete/tab_get.c \
			autocomplete/tabtab.c \
			autocomplete/tab_print.c \
			autocomplete/tab_tools.c \
			autocomplete/tab_print_tools.c \

DICTIONARY_SRCS = \
			dictionary/destroy_bin.c \
			dictionary/destroy_books.c \
			dictionary/fill_bin.c \
			dictionary/fill_books.c \
			dictionary/fill_all.c \
			dictionary/fill_all_bin.c \
			dictionary/fill_builtins.c \
			dictionary/gsd_books.c \
			dictionary/new_books.c \
			dictionary/parse_bin.c \
			dictionary/fill_onetime_all.c \
			dictionary/tab_ifexecbin.c

FT_EXEC_SRCS =	\
				ft_exec/cookedio/call_dup2.c \
				ft_exec/cookedio/compress_iocontent.c \
				ft_exec/cookedio/fdlist_tools.c \
				ft_exec/cookedio/get_rh_from.c \
				ft_exec/cookedio/make_redir_p1.c \
				ft_exec/cookedio/make_redir_p2.c \
				ft_exec/cookedio/protected_close.c \
				ft_exec/cookedio/reset_cookedio.c \
				ft_exec/cookedio/stdio_tools.c \
				ft_exec/cookedio/update_stdtable.c \
				\
				ft_exec/cookedcmd/argv/cmd_subst/get_child_stdout.c \
				ft_exec/cookedcmd/argv/cmd_subst/get_cmdsubst_iuser.c \
				ft_exec/cookedcmd/argv/cmd_subst/parse_cmd.c \
				ft_exec/cookedcmd/argv/cmd_subst/proceed_child_cmdsubst.c \
				ft_exec/cookedcmd/argv/cmd_subst/proceed_parent_cmdsubst.c \
				ft_exec/cookedcmd/argv/cmdarg.c \
				ft_exec/cookedcmd/argv/exp_dolq.c \
				ft_exec/cookedcmd/argv/exp_p1.c \
				ft_exec/cookedcmd/argv/exp_p2.c \
				ft_exec/cookedcmd/argv/exp_p3.c \
				ft_exec/cookedcmd/argv/exp_p4.c \
				ft_exec/cookedcmd/argv/fill_argv.c \
				ft_exec/cookedcmd/argv/get_delim_msk.c \
				ft_exec/cookedcmd/argv/parse.c \
				ft_exec/cookedcmd/print_sh_parse_error.c \
				ft_exec/cookedcmd/cookedcmd_del.c \
				ft_exec/cookedcmd/cookedcmd_new.c \
				ft_exec/cookedcmd/get_command_name.c \
				ft_exec/cookedcmd/is_executable.c \
				\
				ft_exec/create_tmpenv.c \
				ft_exec/ft_exec_inputlist.c \
				ft_exec/ft_exec_andor.c \
				ft_exec/ft_exec_cmd.c \
				ft_exec/ft_exec_shellfile.c \
				ft_exec/ft_exec_cookedcmd.c \
				ft_exec/ft_exec_pipeline.c \
				ft_exec/parse_exec_ret.c \
				ft_exec/get_command.c \
				ft_exec/add_cmd2history.c \
				ft_exec/pl_exec_cmd.c

BUILTINS_SRCS =	\
				builtins/snake/draw/draw_tools_p1.c \
				builtins/snake/draw/draw_tools_p2.c \
				builtins/snake/graphic/vec2_cmp.c \
				builtins/snake/graphic/vec2_convert.c \
				builtins/snake/graphic/vec2_directional.c \
				builtins/snake/graphic/vec2_op.c \
				builtins/snake/init/init_gamedata.c \
				builtins/snake/init/init_snk.c \
				builtins/snake/mechanics/exit_snk.c \
				builtins/snake/mechanics/food.c \
				builtins/snake/tc/sig.c \
				builtins/snake/tc/tc_engine.c \
				builtins/snake/update/draw_update.c \
				builtins/snake/update/input_update.c \
				builtins/snake/update/update_snk.c \
				builtins/snake/builtin_snake.c \
				\
				builtins/env/tools/varkey_new.c \
				builtins/env/tools/sh_evar_lstdup.c \
				builtins/env/tools/varkey_del.c \
				builtins/env/tools/varkey_print.c \
				builtins/env/tools/varkey_isort.c \
				builtins/env/tools/varkey_find.c \
				builtins/env/tools/is_valid_varname.c \
				builtins/env/tools/sh_env_destroy.c \
				builtins/env/tools/sh_env_new.c \
				builtins/env/tools/sh_env_update.c \
				builtins/env/tools/sh_env_getvalue.c \
				builtins/env/tools/sh_evar_addkey.c \
				builtins/env/tools/sh_evar_delkey.c \
				builtins/env/tools/sh_evar_delone.c \
				builtins/env/tools/sh_evar_delvar.c \
				builtins/env/tools/sh_evar_fromstring.c \
				builtins/env/tools/sh_evar_getkey.c \
				builtins/env/tools/sh_evar_new.c \
				builtins/env/tools/sh_evar_print_debug.c \
				builtins/env/tools/sh_evar_toarraystring.c \
				builtins/env/tools/sh_evar_tostring.c \
				builtins/env/builtin_env.c \
				builtins/env/env_actions.c \
				builtins/env/env_common.c \
				builtins/env/env_errors.c \
				builtins/env/builtin_unsetenv.c \
				builtins/env/builtin_setenv.c \
				builtins/env/update_pwd.c \
				\
				builtins/cd/builtin_cd.c \
				builtins/cd/cd_findpath.c \
				builtins/cd/cd_go.c \
				builtins/cd/cd_parsefile.c \
				builtins/cd/cd_followlinks.c \
				builtins/cd/cd_list_to_path.c \
				builtins/cd/cd_checker.c \
				\
				builtins/pwd/builtin_pwd.c \
				\
				builtins/alias/builtin_alias.c \
				builtins/alias/builtin_unalias.c \
				\
				builtins/echo/builtin_echo.c \
				builtins/echo/echo_print_param.c \
				builtins/echo/echo_parse_bs.c \
				builtins/echo/echo_tools.c \
				\
				builtins/exit/builtin_exit.c \
				\
				builtins/set/builtin_set.c \
				builtins/set/set_options.c \
				\
				builtins/history/builtin_history.c \
				builtins/history/hist_optaction.c \
				builtins/history/history_options_p1.c \
				builtins/history/history_options_p2.c \
				builtins/history/tools/convert_file2entries.c \
				builtins/history/tools/get_histcontrol.c \
				builtins/history/tools/hist_add_entry.c \
				builtins/history/tools/hist_append_entries.c \
				builtins/history/tools/hist_clamp_maxentries.c \
				builtins/history/tools/hist_del_p1.c \
				builtins/history/tools/hist_del_p2.c \
				builtins/history/tools/hist_find_book.c \
				builtins/history/tools/hist_get.c \
				builtins/history/tools/hist_ins_entry.c \
				builtins/history/tools/hist_new_p1.c \
				builtins/history/tools/hist_new_p2.c \
				builtins/history/tools/hist_print.c \
				builtins/history/tools/hist_update_books.c \
				\
				builtins/load_builtins.c \
				builtins/builtin_need_help.c \
				builtins/get_builtin.c \
				builtins/print_bad_opt.c \
				builtins/usage_error.c

TLEX_SRCS =	\
			ft_tlex/ft_tlex_destroy.c \
			ft_tlex/ft_tlex_fill.c \
			ft_tlex/ft_tlex_new.c \
			ft_tlex/ft_tlex_resetsrc.c \
			\
			ft_tlex/op_compatibility_mode/ft_tlex_fill_cmpchk.c \
			ft_tlex/op_compatibility_mode/get_token_cat.c \
			ft_tlex/op_compatibility_mode/look_last_compatibility.c \
			ft_tlex/op_compatibility_mode/token_are_compatible.c \
			\
			ft_tlex/tools/error/ft_tlex_errtok.c \
			\
			ft_tlex/tools/source_feeder/ft_tlex_feed.c \
			\
			ft_tlex/tools/tokens/create_new_token.c \
			ft_tlex/tools/tokens/get_next_token.c \
			ft_tlex/tools/tokens/get_next_token_type.c \
			ft_tlex/tools/tokens/tkn_tostring.c \
			ft_tlex/tools/tokens/token_del.c \
			\
			ft_tlex/tools/words/create_word.c \
			ft_tlex/tools/words/ft_tlex_gword.c \
			ft_tlex/tools/words/get_wordcontent.c \
			ft_tlex/tools/words/reduce_word.c \
			\
			ft_tlex/tools/words/quoting/cancel_qword_creation.c\
			ft_tlex/tools/words/quoting/extend2qword.c \
			\
			ft_tlex/tools/words/polisher/ft_tlex_addwpolish.c \
			ft_tlex/tools/words/polisher/use_word_polish.c

ZEBU_SRC =	\
			ft_zebu/core/tools/analyzis/check_state.c \
			ft_zebu/core/tools/analyzis/check_substate.c \
			ft_zebu/core/tools/analyzis/reduce.c \
			ft_zebu/core/tools/analyzis/shift.c \
			\
			ft_zebu/core/tools/blacklist/add_expr_to_blacklist.c \
			ft_zebu/core/tools/blacklist/expr_is_blacklisted.c \
			ft_zebu/core/tools/blacklist/reset_blacklist.c \
			\
			ft_zebu/core/tools/expr/discard_expr.c \
			ft_zebu/core/tools/expr/exptoken_freshdup.c \
			ft_zebu/core/tools/expr/get_expmodel.c \
			ft_zebu/core/tools/expr/id_isexpr.c \
			ft_zebu/core/tools/expr/new_exptoken.c \
			\
			ft_zebu/core/tools/others/close_state.c \
			ft_zebu/core/tools/others/factory_set_error_msg.c \
			ft_zebu/core/tools/others/fill_container.c \
			ft_zebu/core/tools/others/try_expanding.c \
			ft_zebu/core/tools/others/take_next_token.c \
			\
			ft_zebu/core/init/factory_get_stacks.c \
			ft_zebu/core/init/get_expr_stack.c \
			ft_zebu/core/init/get_token_stack.c \
			ft_zebu/core/init/factory_init_pools.c \
			ft_zebu/core/init/get_token_pool.c \
			ft_zebu/core/init/get_exptoken_pool.c \
			\
			ft_zebu/core/factory_analyze.c \
			ft_zebu/core/factory_close.c \
			ft_zebu/core/factory_ending.c \
			ft_zebu/core/factory_init.c \
			\
			ft_zebu/tools/ft_zebu_get_curr_expr.c \
			ft_zebu/tools/ft_zebu_get_curr_tok.c \
			ft_zebu/tools/ft_zebu_look_curr_expr.c \
			ft_zebu/tools/ft_zebu_look_curr_tok.c \
			ft_zebu/tools/ft_zebu_notokleft.c \
			ft_zebu/tools/ft_zebu_set_error.c \
			\
			ft_zebu/tools/substates/get_substate_value.c \
			ft_zebu/tools/substates/substate_match_id.c \
			ft_zebu/tools/substates/substate_match_token.c \
			\
			ft_zebu/ft_zebu_destroy_ret.c \
			ft_zebu/ft_zebu_exit.c \
			ft_zebu/ft_zebu_get_errmsg.c \
			ft_zebu/ft_zebu_start.c

ERRORMSGS_SRCS = \
				errormsgs/err1.c \
				errormsgs/err2.c \
				errormsgs/err3.c

INCLUDES =	-Iincludes \
			-I$(LIBFTDIR)includes \
			-I$(FT_STRINGSDIR)includes \
			-I$(FT_BRACKETEERDIR)includes \
			-I$(FT_STACKDIR)includes \
			-I$(FT_QUEUEDIR)includes \
			-I$(FT_POOLDIR)includes \
			-I$(FT_TERMCAP)includes \
			-I$(FT_DICTIONARYDIR)includes \
			-I$(FT_HASHTABLEDIR)includes

LIBS =	-ltermcap -L $(LIBFTDIR) -lft
#DEBUGFLAGS = -g3

HEADERS_PATH =	includes/
HEADERS_NAME =	\
				token_charsets/input_grammar_reducters.h \
				token_charsets/input_grammar_struct.h \
				token_charsets/input_tkn_chrset.h \
				token_charsets/input_tkn_grammar.h \
				token_charsets/iuser_lexinfo.h \
				token_charsets/iuser_tkn_chrmsk.h \
				brackets_shellinfo.h \
				builtins.h \
				builtins_private.h \
				ft_getopt.h \
				ft_tkn_type.h \
				ft_tlex.h \
				ft_zebu_core.h \
				autocomplete.h \
				controls.h \
				ftsh.h \
				ft_iuser.h \
				# ft_exec.h \
				# shell_env.h

CC = gcc

OBJ_VDIR = $(addprefix $(OBJ_ROOTDIR), $(SRCS_DIR))
SRCS = $(addprefix $(SRCS_ROOTDIR),$(SRCS_NAME))
OBJS = $(addprefix $(OBJ_ROOTDIR),$(SRCS_NAME:.c=.o))
HEADERS = $(addprefix $(HEADERS_PATH), $(HEADERS_NAME))

OBJ_ROOTDIR = objs/
SRCS_ROOTDIR = srcs/
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -g3 -fsanitize=address
# echo [ '\033[0;31m'`echo $(NAME) | tr a-z A-Z`'\033[0m' - '\033[1;33m'DEBUG'\033[0m' ] converting '\033[1;31m'`echo $< | sed 's/^srcs\///g' | sed 's/\.c$///g'`'\033[0m';\
# echo [ '\033[0;31m'`echo $(NAME) | tr a-z A-Z`'\033[0m' ] converting '\033[1;31m'`echo $< | sed 's/^srcs\///g' | sed 's/\.c$///g'`'\033[0m';\
# @echo PROGRAM [ '\033[0;31m'`echo $(NAME) | tr a-z A-Z`'\033[0m' ] HAS BEEN COMPILED.

.PHONY: libs all clean fclean re

all: libs $(NAME)

$(NAME): $(OBJS)
	@if [ $(DEBUG) -eq 1 ];\
	then\
		$(CC) $(CFLAGS) $(DEBUGFLAGS) -o $(NAME) $(INCLUDES) $(OBJS) $(LIBS);\
	elif [ $(LEAKS) -eq 1 ];\
	then\
		$(CC) $(CFLAGS) -framework Appkit -g3 -o $(NAME) $(INCLUDES) $(OBJS) $(LIBS);\
	else\
		$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBS);\
	fi
	@printf "\r \360\237\215\272 PROGAM [\e[0;31m %s \e[0m] HAS BEEN COMPILED.\e[K\n" \
	`echo $(NAME) | tr a-z A-Z`
	@if [ $(PRINTHEAD) -eq 1 ];\
	then\
		sleep .2; \
		echo "██████╗  ██╗███████╗██╗  ██╗           ____"; \
		printf "\a\r"; \
		sleep .2; \
		printf "\a\r"; \
		sleep .35; \
		echo "╚════██╗███║██╔════╝██║  ██║         ,'   Y\`."; \
		printf "\a\r"; \
		sleep .35; \
		echo " █████╔╝╚██║███████╗███████║        /        \\"; \
		printf "\a\r"; \
		sleep .2; \
		printf "\a\r"; \
		sleep .80; \
		echo "██╔═══╝  ██║╚════██║██╔══██║        \\ ()  () /"; \
		printf "\a\r"; \
		sleep .2; \
		printf "\a\r"; \
		sleep .35; \
		echo "███████╗ ██║███████║██║  ██║         \`. /\\ ,'"; \
		printf "\a\r"; \
		sleep .35; \
		echo "╚══════╝ ╚═╝╚══════╝╚═╝  ╚═╝ by: fhemart - jbulant"; \
		printf "\a\r"; \
		sleep .2; \
		printf "\a\r"; \
		sleep .35; \
	fi

libs:
	@make -sC $(LIBFTDIR)
	@make -sC $(FT_BRACKETEERDIR)
	@make -sC $(FT_STRINGSDIR)
	@make -sC $(FT_STACKDIR)
	@make -sC $(FT_QUEUEDIR)
	@make -sC $(FT_POOLDIR)
	@make -sC $(FT_TERMCAP)
	@make -sC $(FT_HASHTABLEDIR)
	@make -sC $(FT_DICTIONARYDIR)

$(OBJ_ROOTDIR)%.o: $(SRCS_ROOTDIR)%.c ${HEADERS}
	@mkdir -p $(OBJ_ROOTDIR) $(OBJ_VDIR)
	@if [ $(DEBUG) -eq 1 ];\
	then\
		printf "\r   [\e[0;31m %s - \e[1;33mDEBUG\e[0m ] converting \e[1;31m%s\e[0m\e[K" \
		`echo $(NAME) | tr a-z A-Z` \
		`echo $< | sed 's/^srcs\///g' | sed 's/\.c$///g'`;\
		$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDES) -c -o $@ $<;\
		printf "\r \e[0;32m\xE2\x9C\x94\033[0m [\e[0;31m %s - \e[1;33mDEBUG\e[0m ] converting \e[1;31m%s\e[0m\e[K" \
		`echo $(NAME) | tr a-z A-Z` \
		`echo $< | sed 's/^srcs\///g' | sed 's/\.c$///g'`;\
	else\
		printf "\r   [\e[0;31m %s \e[0m] converting \e[1;31m%s\e[0m\e[K" \
		`echo $(NAME) | tr a-z A-Z` \
		`echo $< | sed 's/^srcs\///g' | sed 's/\.c$///g'`;\
		$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<;\
		printf "\r \e[0;32m\xE2\x9C\x94\033[0m [\e[0;31m %s \e[0m] converting \e[1;31m%s\e[0m\e[K" \
		`echo $(NAME) | tr a-z A-Z` \
		`echo $< | sed 's/^srcs\///g' | sed 's/\.c$///g'`;\
	fi

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_ROOTDIR)
	@+make -sC $(LIBFTDIR) clean
	@+make -sC $(FT_BRACKETEERDIR) clean
	@+make -sC $(FT_STRINGSDIR) clean
	@+make -sC $(FT_STACKDIR) clean
	@+make -sC $(FT_QUEUEDIR) clean
	@+make -sC $(FT_POOLDIR) clean
	@make -C $(FT_TERMCAP) clean
	@make -C $(FT_DICTIONARYDIR) clean
	@make -C $(FT_HASHTABLEDIR) clean


fclean: clean
	@rm -f $(NAME)
	@+make -sC $(LIBFTDIR) fclean
	@+make -sC $(FT_BRACKETEERDIR) fclean
	@+make -sC $(FT_STRINGSDIR) fclean
	@+make -sC $(FT_STACKDIR) fclean
	@+make -sC $(FT_QUEUEDIR) fclean
	@+make -sC $(FT_POOLDIR) fclean
	@make -C $(FT_TERMCAP) fclean
	@make -C $(FT_DICTIONARYDIR) fclean
	@make -C $(FT_HASHTABLEDIR) fclean


re: fclean all
