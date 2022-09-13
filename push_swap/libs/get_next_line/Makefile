# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 00:26:43 by younhwan          #+#    #+#              #
#    Updated: 2022/09/13 22:24:52 by younhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

INCS_DIR = ./includes

SRCS_DIR = ./srcs
OBJS_DIR = ./objs

SRCS = 	get_next_line.c\
		get_next_line_utils.c

SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}
OBJS = ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}

all: ${NAME}
	@echo "done"

${OBJS_DIR}:
	@echo "Build libgnl.a"
	@mkdir -p objs

${OBJS}: %.o: ${addsuffix .c,${subst obj,src,${%}}} | ${OBJS_DIR}
	@${CC} ${CFLAGS} -c ${patsubst %.o,%.c,${subst obj,src,$@}} -o $@ -I ${INCS_DIR}

${NAME}: ${OBJS}
	@${AR} $@ $^

clean:
	@echo "Remove dependencies in get_next_line"
	@rm -rf ${OBJS_DIR}

fclean: clean
	@echo "Remove libgnl.a"
	@${RM} ${NAME}

re:
	@echo "Re-build libgnl.a"
	@make fclean
	@make all

.PHONY: all clean fclean re