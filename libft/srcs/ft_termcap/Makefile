# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 16:49:28 by jbulant           #+#    #+#              #
#    Updated: 2018/10/17 16:22:24 by fhemart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft.a
LIBFTDIR = ../../
NAME = $(addprefix $(LIBFTDIR),$(LIBFT))

MODULENAME = FT_TERMCAP
LINUX = 0
DEBUG = 0

HEADERS_NAME = ft_termcap.h \
			   ft_prompt.h \
			   ft_dlist.h

SRCS_DIR =	cursor \
			dlist \
			prompt \
			tab \
			terminal \
			controls

SRCS_NAME =	terminal/ft_term_init.c \
			terminal/ft_term_close.c \
			terminal/ft_term_setcanon.c \
			terminal/ft_term_restore.c \
			terminal/ft_term_sigwinch.c \
			terminal/ft_term_sighandler.c \
			terminal/ft_term_debug_putfd.c \
			terminal/ft_term_readkey.c \
			terminal/ft_term_ifhandler.c \
			terminal/ft_term_writetc.c \
			prompt/ft_prompt_init.c \
			prompt/ft_prompt_writechar.c \
			prompt/ft_prompt_handlefn.c \
			prompt/ft_prompt_ifresise.c \
			prompt/ft_prompt_getline.c \
			prompt/ft_prompt_cleanline.c \
			prompt/ft_prompt_close.c \
			prompt/ft_prompt_wratcurrent.c \
			prompt/ft_prompt_wratchunck.c \
			prompt/ft_prompt_wrat2.c \
			prompt/ft_prompt_private.c \
			prompt/ft_prompt_resize_smooth.c \
			controls/ft_control_pasteleft.c \
			controls/ft_control_cpy.c \
			controls/ft_control_cut.c \
			controls/ft_control_paste.c \
			controls/ft_control_supcpy.c \
			controls/ft_control_cpyright.c \
			controls/ft_control_cpyleft.c \
			controls/ft_control_pasteright.c \
			controls/ft_control_bsearch.c \
			controls/ft_control_bsearch_tools.c \
			controls/ft_control_ctrlg.c \
			prompt/ft_prompt_wrupdate.c \
			prompt/ft_prompt_printable_key.c \
			prompt/ft_prompt_fnselector.c \
			prompt/ft_prompt_getline_debug.c \
			prompt/ft_prompt_debug_putfd_current.c \
			prompt/ft_prompt_debug_putfd_termsize.c \
			prompt/ft_prompt_cleanscren.c \
			prompt/ft_prompt_cleanscreentr.c \
			prompt/ft_prompt_clean.c \
			prompt/ft_prompt_returnafterwr.c \
			prompt/ft_prompt_outtrmode.c  \
			prompt/ft_prompt_hist_tools.c  \
			prompt/ft_prompt_hist_tools2.c  \
			dlist/ft_dlist_addafternode.c \
			dlist/ft_dlist_addbeforenode.c \
			dlist/ft_dlist_addfirstnode.c \
			dlist/ft_dlist_addlastnode.c \
			dlist/ft_dlist_addnode.c \
			dlist/ft_dlist_createnode.c \
			dlist/ft_dlist_createroot.c \
			dlist/ft_dlist_debug_print.c \
			dlist/ft_dlist_destroyroot.c \
			dlist/ft_dlist_rmnode.c \
			dlist/ft_dlist_rmonenode.c \
			dlist/ft_dlist_haswordba.c \
			dlist/ft_dlist_haswordfw.c \
			dlist/ft_dlist_str2dlist.c \
			dlist/ft_dlist_clr_dlist2str.c \
			cursor/ft_curs_mov.c \
			controls/ft_control_delette.c \
			cursor/ft_curs_movco.c \
			cursor/ft_curs_movli_up.c \
			cursor/ft_curs_movli_do.c \
			cursor/ft_curs_movco_le.c \
			cursor/ft_curs_movli.c \
			cursor/ft_curs_trunckmovele.c \
			cursor/ft_curs_trunckmoveri.c \
			cursor/ft_curs_trunckmove.c \
			controls/ft_control_exit.c \
			controls/ft_control_movewordfw.c \
			controls/ft_control_movewordba.c \
			controls/ft_control_movelido.c \
			controls/ft_control_right.c \
			controls/ft_control_moveliup.c \
			controls/ft_control_movebeg.c \
			controls/ft_control_moveend.c \
			controls/ft_control_nothing.c \
			controls/ft_control_left.c \
			controls/ft_control_ctrlc.c \
			controls/ft_control_clear.c \
			controls/ft_control_hystoryup.c \
			prompt/ft_prompt_resize.c \
			prompt/ft_prompt_resize_write.c \
			prompt/ft_prompt_exportline.c \
			prompt/ft_prompt_exportline_tools.c \
			prompt/ft_prompt_checkwrite.c \
			prompt/ft_prompt_printablebsearch.c \
			prompt/ft_prompt_bsearch_tools.c \
			prompt/ft_prompt_printable_key_tool.c \
			terminal/ft_term_update_size.c

OBJ_ROOTDIR = objs/
OBJ_VDIR := $(addprefix $(OBJ_ROOTDIR),$(SRCS_DIR))
SRCS_ROOTDIR = srcs/
HEADERS_PATH = includes/

SRCS := $(addprefix $(SRCS_ROOTDIR),$(SRCS_NAME))
OBJS := $(addprefix $(OBJ_ROOTDIR),$(SRCS_NAME:.c=.o))
HEADERS := $(addprefix $(HEADERS_PATH), $(HEADERS_NAME))

CC = cc
INCLUDES =	-Iincludes \
			-I$(LIBFTDIR)includes \
			-I../../../includes \
			-I../ft_stack/includes \
			-I../ft_queue/includes \
			-I../ft_pool/includes \
			-I../ft_strings/includes \
			-I../ft_dictionary/includes \
			-I../ft_hashtable/includes \
			-I../ft_bracketeer/includes

CFLAGS = -Wall -Wextra -Werror -g
DEBUGFLAGS = -g3 -fsanitize=address
#DEBUGFLAGS = -fsanitize=address -lasan -g3
# @ranlib $(NAME)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\r \360\237\215\272 MODULE [\e[0;35m %s \e[0m] HAS BEEN INJECTED TO [\e[0;32m %s \e[0m].\e[K\n" \
	`echo $(MODULENAME) | sed 's/lib//' | rev | cut -d '.' -f2 | rev | tr a-z A-Z` \
	`echo $(LIBFT) | rev | cut -d '.' -f2 | rev| tr a-z A-Z`;\

$(OBJ_ROOTDIR)%.o: $(SRCS_ROOTDIR)%.c ${HEADERS}
	@mkdir -p $(OBJ_ROOTDIR) $(OBJ_VDIR)
	@if [ $(DEBUG) -eq 1 ];\
	then\
		printf "\r   [\e[0;35m %s \e[0m - \e[1;33mDEBUG\e[0m ] converting \e[1;35m%s\e[0m\e[K" \
		`echo $(MODULENAME)` \
		`echo $< | sed 's/^srcs\///g' | sed 's/\.c$///g'`;\
		$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDES) -c -o $@ $<;\
		printf "\r \e[0;32m\xE2\x9C\x94\033[0m [\e[0;35m %s \e[0m - \e[1;33mDEBUG\e[0m ] converting \e[1;35m%s\e[0m\e[K" \
		`echo $(MODULENAME)` \
		`echo $< | sed 's/^srcs\///g' | sed 's/\.c$///g'`;\
	else\
		printf "\r   [\e[0;35m %s \e[0m] converting \e[1;35m%s\e[0m\e[K" \
		`echo $(MODULENAME)` \
		`echo $< | sed 's/^srcs\///g' | sed 's/\.c$///g'`;\
		$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<;\
		printf "\r \e[0;32m\xE2\x9C\x94\033[0m [\e[0;35m %s \e[0m] converting \e[1;35m%s\e[0m\e[K" \
		`echo $(MODULENAME)` \
		`echo $< | sed 's/^srcs\///g' | sed 's/\.c$///g'`;\
	fi
	@ar rc $(NAME) $@

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_ROOTDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
