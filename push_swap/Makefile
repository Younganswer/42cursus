# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 16:03:07 by younhwan          #+#    #+#              #
#    Updated: 2022/08/25 16:26:03 by younhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

INCS_DIR = ./includes

FT_PRINTF_DIR = ./libs/ft_printf
GNL_DIR = ./libs/get_next_line

LIBS =	./libs/ft_printf/libftprintf.a\
		./libs/get_next_line/libgnl.a

SRCS_DIR = ./srcs
OBJS_DIR = ./objs

SRCS = 	main.c

SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}
OBJS = ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}

all: ${NAME}

# bonus:

${OBJS_DIR}:
	mkdir -p objs

${OBJS}: %.o: ${addsuffix .c,${subst obj,src,${%}}} | ${OBJS_DIR}
	${CC} ${CFLAGS} -g -c ${patsubst %.o,%.c,${subst obj,src,$@}} -o $@ -I ${INCS_DIR}

${NAME}: ${OBJS}
	make -C ${FT_PRINTF_DIR}
	make -C ${GNL_DIR}
	${CC} -g -o ${NAME} ${OBJS} ${LIBS} -I ${INCS_DIR}

clean:
	make -C ${FT_PRINTF_DIR} clean
	make -C ${GNL_DIR} clean
	rm -rf ${OBJS_DIR}

fclean: clean
	make -C ${FT_PRINTF_DIR} fclean
	make -C ${GNL_DIR} fclean

re:
	make fclean
	make all

.PHONY: all clean fclean re bonus