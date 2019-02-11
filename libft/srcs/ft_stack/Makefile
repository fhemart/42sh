# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 16:49:28 by jbulant           #+#    #+#              #
#    Updated: 2018/09/30 22:56:55 by fhemart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft.a
LIBFTDIR = ../../
# LIBFTDIR = ./libft/
NAME = $(addprefix $(LIBFTDIR),$(LIBFT))

MODULENAME = FT_STACK
LINUX = 0
DEBUG = 0

HEADERS_NAME = ft_stack.h

SRCS_DIR = \
			core \
			public \
			tools

SRCS_NAME = \
			core/ft_stack_cleanerdelfrom.c \
			core/ft_stack_cleanerexit.c \
			core/ft_stack_cleanernew.c \
			core/ft_stack_newblock.c \
			core/ft_stack_realloc.c \
			core/ft_stack_removedcheck.c \
			public/ft_stack_add_content.c \
			public/ft_stack_clean.c \
			public/ft_stack_cleaneradd.c \
			public/ft_stack_destroy.c \
			public/ft_stack_get_content.c \
			public/ft_stack_reset.c \
			public/ft_stack_init.c \
			tools/ft_stack_lookat.c \
			tools/ft_stack_looktop.c \
			tools/ft_stack_replaceat.c \
			tools/ft_stack_totalsize.c \
			tools/ft_stack_isempty.c

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
