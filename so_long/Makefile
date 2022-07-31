# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 16:03:07 by younhwan          #+#    #+#              #
#    Updated: 2022/08/01 00:06:27 by younhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

INCS_DIR = ./includes
INCS_BONUS_DIR = ./includes_bonus

LIB_DIR = ./lib
LIB_NAME = lib_my_own.a

MLX_DIR = ./mlx
MLX_FLAS = -lmlx -framework OpenGL -framework Appkit

SRC_DIR = ./srcs
OBJ_DIR = ./objs
SRC_BONUS_DIR = ./srcs_bonus
OBJ_BONUS_DIR = ./objs_bonus

SRCS = 
SRCS_BONUS = 

SRCS := ${addprefix ${SRC_DIR}/, ${SRCS}}
SRCS_BONUS := ${addprefix ${SRC_BONUS_DIR}/, ${SRCS_BONUS}}

OBJS = ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}
OBJS_BONUS = ${SRCS_BONUS:${SRC_BONUS_DIR}/%.c=${OBJ_BONUS_DIR}/%.o}

#bonus: ${NAME_BONUS}

all: ${NAME}

${OBJ_DIR}:
	mkdir -p objs

${OBJ_BONUS_DIR}:
	mkdir -p objs_bonus

${OBJS}: %.o: ${addsuffix .c,${subst obj,src,${%}}} | ${OBJ_DIRS}
	${CC} ${CFLAGS} -c ${patsubst %.o,%.c,${subst obj,src,$@}} -o $@ -I ${INCS_DIR}

${OBJS_BONUS}: %.o: ${addsuffix .c,${subst obj,src,${%}}} | ${OBJ_BONUS_DIRS}
	${CC} ${CFLAGS} -c ${patsubst %.o,%.c,${subst obj,src,$@}} -o $@ -I ${INCS_BONUS_DIR}

${NAME}: ${OBJS}
	make -C ${LIB_DIR}
	make -C ${MLX_DIR}
	${CC} -o ${NAME} ${OBJS} -L ${LIB_DIR} -l_my_own -I ${INCS_DIR} -L ${MLX_DIR} ${MLX_FLAS}

${NAME_BONUS}: ${OBJS_BONUS}
	make -C ${LIB_BONUS_DIR}
	make -C ${MLX_DIR}
	${CC} -o ${NAME_BONUS} ${OBJS_BONUS} -L ${LIB_BONUS_DIR} -l_my_own -I ${INCS_BONUS_DIR} -L ${MLX_DIR} ${MLX_FLAS}

clean:
	make -C ${LIB_DIR} clean
	make -C ${MLX_DIR} clean
	rm -rf ${OBJ_DIR}
#	rm -rf ${OBJ_BONUS_DIR}

fclean: clean
	make -C ${LIB_DIR} fclean
	${RM} ${NAME} ${NAME_BONUS}

re:
	make fclean
	make all

.PHONY: all clean fclean re #bonus