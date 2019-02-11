# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 16:49:28 by jbulant           #+#    #+#              #
#    Updated: 2018/09/30 22:56:48 by fhemart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft.a
LIBFTDIR = ../../
# LIBFTDIR = ./libft/
NAME = $(addprefix $(LIBFTDIR),$(LIBFT))

MODULENAME = FT_STRINGS

LINUX = 0
DEBUG = 0

HEADERS_NAME =	\
				ft_lstr.h \
				ft_lstrprivate.h \
				ft_awstr.h \
				ft_strings.h

SRCS_DIR = \
			ft__str \
			ft_awstr \
			ft_lstr \
			ft_nstr \
			private

SRCS_NAME = \
			ft__str/ft__strcat.c \
			ft__str/ft__strnew.c \
			ft__str/ft__strnnew.c \
			ft__str/ft__strncat.c \
			ft_awstr/ft_awpad.c \
			ft_awstr/ft_awstrlpad.c \
			ft_awstr/ft_awstrrpad.c \
			ft_awstr/ft_awstrncat.c \
			ft_awstr/ft_awstrncatendl.c \
			ft_awstr/ft_awstrset.c \
			ft_awstr/ft_putawstr.c \
			ft_lstr/ft_lstr_tostring.c \
			ft_lstr/ft_lstrclr.c \
			ft_lstr/ft_lstrdel.c \
			ft_lstr/ft_lstrdelone.c \
			ft_lstr/ft_lstrlen.c \
			ft_lstr/ft_putlstr_fd.c \
			ft_lstr/ft_putlstr.c \
			ft_lstr/ft_putlstrendl_fd.c \
			ft_lstr/ft_putlstrendl.c \
			ft_nstr/ft_nstrcat.c \
			ft_nstr/ft_nstrncat.c \
			ft_nstr/ft_nstrnew.c \
			private/ft_lstradd.c \
			private/ft_lstrnew_empty.c \
			private/ft_lstrfreespace.c

OBJ_ROOTDIR = objs/
OBJ_VDIR := $(addprefix $(OBJ_ROOTDIR),$(SRCS_DIR))
SRCS_ROOTDIR = srcs/
HEADERS_PATH = includes/

SRCS := $(addprefix $(SRCS_ROOTDIR),$(SRCS_NAME))
OBJS := $(addprefix $(OBJ_ROOTDIR),$(SRCS_NAME:.c=.o))
HEADERS := $(addprefix $(HEADERS_PATH), $(HEADERS_NAME))

CC = cc
INCLUDES = -Iincludes -I$(LIBFTDIR)includes
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -fsanitize=address -g3
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
