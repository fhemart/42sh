# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/28 05:02:12 by jbulant           #+#    #+#              #
#    Updated: 2018/09/30 22:56:33 by fhemart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft.a
LIBFTDIR = ../../
FT_STACKDIR   = $(LIBFTDIR)srcs/ft_stack/

# LIBFTDIR = ./libft/
NAME = $(addprefix $(LIBFTDIR),$(LIBFT))

MODULENAME = FT_BRACKETEER
LINUX = 0
DEBUG = 0

HEADERS_NAME =	\
				brackets.h \
				brackets_private.h \
				brackets_proto.h

SRCS_DIR =	\
			public \
			tools \
			private \
			private/gnqword \

SRCS_NAME = \
			private/gnqword/close_escaping.c \
			private/gnqword/find_next_closure.c \
			private/gnqword/find_next_quote.c \
			private/gnqword/try_extend.c \
			private/brdata_misc.c \
			private/close_br.c \
			private/find_openbr.c \
			private/new_brdata.c \
			private/new_brset.c \
			private/update_info.c \
			public/brackets.c \
			public/brdata_addfeeder.c \
			public/get_next_qword.c \
			public/get_next_closure.c \
			tools/brdata_resetsrc.c \
			tools/brdata_updatesrc.c \
			tools/brdata_utils.c \
			tools/create_new_brdata.c \
			tools/gnqw_utils.c

OBJ_ROOTDIR = objs/
OBJ_VDIR := $(addprefix $(OBJ_ROOTDIR), $(SRCS_DIR))
SRCS_ROOTDIR = srcs/
HEADERS_PATH =	includes/

SRCS := $(addprefix $(SRCS_ROOTDIR),$(SRCS_NAME))
OBJS := $(addprefix $(OBJ_ROOTDIR),$(SRCS_NAME:.c=.o))
HEADERS := $(addprefix $(HEADERS_PATH), $(HEADERS_NAME))

CC = cc
INCLUDES =	-Iincludes \
			-I$(LIBFTDIR)includes \
			-I$(FT_STRINGSDIR)includes \
			-I$(FT_STACKDIR)includes
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -fsanitize=address -g3
# echo [ '\033[0;35m'`echo $(MODULENAME)`'\033[0m' - '\033[1;33m'DEBUG'\033[0m' ] converting '\033[1;35m'`echo $< | sed 's/^srcs\///g' | sed 's/\.c$///g'`'\033[0m';\
# echo [ '\033[0;35m'`echo $(MODULENAME)`'\033[0m' ] converting '\033[1;35m'`echo $< | sed 's/^srcs\///g' | sed 's/\.c$///g'`'\033[0m';\
# @echo MODULE [ '\033[0;35m'`echo $(MODULENAME) | sed 's/lib//' | rev | cut -d '.' -f2 | rev | tr a-z A-Z`'\033[0m' ] HAS BEEN INJECTED TO [ '\033[0;32m'`echo $(LIBFT) | rev | cut -d '.' -f2 | rev| tr a-z A-Z`'\033[0m' ].
# @ar rcs $(NAME) $(OBJS)
# @ranlib $(NAME)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\r \360\237\215\272 MODULE [\e[0;35m %s \e[0m] HAS BEEN INJECTED TO [\e[0;32m %s \e[0m].\n" \
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
