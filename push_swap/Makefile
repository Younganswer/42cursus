# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 16:03:07 by younhwan          #+#    #+#              #
#    Updated: 2022/08/27 14:15:56 by younhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f


FT_PRINTF_DIR = ./libs/ft_printf
GNL_DIR = ./libs/get_next_line

LIBS =	./libs/ft_printf/libftprintf.a\
		./libs/get_next_line/libgnl.a

INCS_DIR = ./incs
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

SRCS = 	push_swap.c\
		init_node.c\
		init_stack.c\
		pop.c\
		push.c\
		push_ab.c\
		rotate.c\
		stack_utils.c\
		swap.c
		
SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}
OBJS = ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}

INCS_BONUS_DIR = ./incs_bonus
SRCS_BONUS_DIR = ./srcs_bonus
OBJS_BONUS_DIR = ./objs_bonus

SRCS_BONUS = main_bonus.c
SRCS_BONUS := ${addprefix ${SRCS_BONUS_DIR}/, ${SRCS_BONUS}}
OBJS_BONUS = ${SRCS_BONUS:${SRCS_BONUS_DIR}/%.c=${OBJS_BONUS_DIR}/%.o}

all: ${NAME}

bonus: ${NAME_BONUS}
	make all

${OBJS_DIR}:
	mkdir -p objs

${OBJS}: %.o: ${addsuffix .c,${subst obj,src,${%}}} | ${OBJS_DIR}
	${CC} ${CFLAGS} -g -c ${patsubst %.o,%.c,${subst obj,src,$@}} -o $@ -I ${INCS_DIR}

${NAME}: ${OBJS}
	make -C ${FT_PRINTF_DIR}
	make -C ${GNL_DIR}
	${CC} -g -o ${NAME} ${OBJS} ${LIBS} -I ${INCS_DIR}

${OBJS_BONUS_DIR}:
	mkdir -p objs_bonus

${OBJS_BONUS}: %.o: ${addsuffix .c,${subst obj,src,${%}}} | ${OBJS_BONUS_DIR}
	${CC} ${CFLAGS} -g -c ${patsubst %.o,%.c,${subst obj,src,$@}} -o $@ -I ${INCS_BONUS_DIR}

${NAME_BONUS}: ${OBJS_BONUS}
	make -C ${FT_PRINTF_DIR}
	make -C ${GNL_DIR}
	${CC} -g -o ${NAME_BONUS} ${OBJS_BONUS} ${LIBS} -I ${INCS_BONUS_DIR}

clean:
	make -C ${FT_PRINTF_DIR} clean
	make -C ${GNL_DIR} clean
	rm -rf ${OBJS_DIR} ${OBJS_BONUS_DIR}

fclean: clean
	make -C ${FT_PRINTF_DIR} fclean
	make -C ${GNL_DIR} fclean
	${RM} ${NAME} ${NAME_BONUS}
	
re:
	make fclean
	make all

.PHONY: all clean fclean re bonus