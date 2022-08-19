# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 16:03:07 by younhwan          #+#    #+#              #
#    Updated: 2022/08/19 15:16:57 by younhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f


LIBFT_DIR = ./libs/libft
GNL_DIR = ./libs/get_next_line
LIBS = 	./libs/libft/libft.a\
		./libs/get_next_line/libgnl.a

INCS_DIR = ./includes
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

SRCS =	pipex_bonus.c\
		pipex_utils_bonus.c

SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}
OBJS = ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}

all: ${NAME}

bonus:
	make all

${OBJS_DIR}:
	mkdir -p objs

${OBJS}: %.o: ${addsuffix .c,${subst obj,src,${%}}} | ${OBJS_DIR}
	${CC} ${CFLAGS} -c ${patsubst %.o,%.c,${subst obj,src,$@}} -o $@ -I ${INCS_DIR}

${NAME}: ${OBJS}
	make -C ${LIBFT_DIR}
	make -C ${GNL_DIR}
	${CC} -g -o ${NAME} ${OBJS} ${LIBS} -I ${INCS_DIR}

clean:
	make -C ${LIBFT_DIR} clean
	make -C ${GNL_DIR} clean
	rm -rf ${OBJS_DIR}

fclean: clean
	make -C ${LIBFT_DIR} fclean
	make -C ${GNL_DIR} fclean
	${RM} ${NAME}

re:
	make fclean
	make all

.PHONY: all clean fclean re bonus