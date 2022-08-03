# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 16:03:07 by younhwan          #+#    #+#              #
#    Updated: 2022/08/03 19:14:11 by younhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
#NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

INCS_DIR = ./includes
#INCS_BONUS_DIR = ./includes_bonus

FT_PRINTF_DIR = ./libs/ft_printf
GNL_DIR = ./libs/get_next_line

LIBS =	./libs/ft_printf/libftprintf.a
		./libs/get_next_line/libgnl.a

MLX_DIR = ./mlx
MLX_FLAS = -lmlx -framework OpenGL -framework Appkit

SRCS_DIR = ./srcs
OBJS_DIR = ./objs
#SRC_BONUS_DIR = ./srcs_bonus
#OBJS_BONUS_DIR = ./objs_bonus

SRCS = 
#SRCS_BONUS = 

SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}
#SRCS_BONUS := ${addprefix ${SRC_BONUS_DIR}/, ${SRCS_BONUS}}

OBJS = ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}
#OBJS_BONUS = ${SRCS_BONUS:${SRC_BONUS_DIR}/%.c=${OBJS_BONUS_DIR}/%.o}

#bonus: ${NAME_BONUS}

all: ${NAME}

${OBJS_DIR}:
	mkdir -p objs

# ${OBJS_BONUS_DIR}:
#	mkdir -p objs_bonus

${OBJS}: %.o: ${addsuffix .c,${subst obj,src,${%}}} | ${OBJS_DIRS}
	${CC} ${CFLAGS} -c ${patsubst %.o,%.c,${subst obj,src,$@}} -o $@ -I ${INCS_DIR}

#${OBJS_BONUS}: %.o: ${addsuffix .c,${subst obj,src,${%}}} | ${OBJS_BONUS_DIRS}
#	${CC} ${CFLAGS} -c ${patsubst %.o,%.c,${subst obj,src,$@}} -o $@ -I ${INCS_BONUS_DIR}

${NAME}: ${OBJS}
	make -C ${FT_PRINTF_DIR}
	make -C ${GNL_DIR}
	make -C ${MLX_DIR}
	${CC} -o ${NAME} ${OBJS} ${LIBS} -I ${INCS_DIR} -L ${MLX_DIR} ${MLX_FLAS}

#${NAME_BONUS}: ${OBJS_BONUS}
#	make -C ${FT_PRINTF_DIR}
#	make -C ${GNL_DIR}
#	make -C ${MLX_DIR}
#	${CC} -o ${NAME_BONUS} ${OBJS_BONUS} ${LIBS} -I ${INCS_BONUS_DIR} -L ${MLX_DIR} ${MLX_FLAS}

clean:
	make -C ${FT_PRINTF_DIR} clean
	make -C ${GNL_DIR} clean
	make -C ${MLX_DIR} clean
	rm -rf ${OBJS_DIR}
#	rm -rf ${OBJS_BONUS_DIR}

fclean: clean
	make -C ${FT_PRINTF_DIR} fclean
	make -C ${GNL_DIR} fclean
#	make -C ${MLX_DIR} fclean
	${RM} ${NAME}
#	${RM} ${NAME_BONUS}

re:
	make fclean
	make all

.PHONY: all clean fclean re #bonus