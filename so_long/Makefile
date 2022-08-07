# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 16:03:07 by younhwan          #+#    #+#              #
#    Updated: 2022/08/08 01:18:03 by younhwan         ###   ########.fr        #
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

LIBS =	./libs/ft_printf/libftprintf.a\
		./libs/get_next_line/libgnl.a

LIB_MLX = libmlx.dylib
MLX_DIR = ./mlx
MLX_FLAS = -lmlx -framework OpenGL -framework AppKit

SRCS_DIR = ./srcs
OBJS_DIR = ./objs
#SRC_BONUS_DIR = ./srcs_bonus
#OBJS_BONUS_DIR = ./objs_bonus

SRCS = 	main.c\
		game/end_game.c\
		game/init_game.c\
		game/key_pressed.c\
		game/move_to.c\
		game/render_game.c\
		game/reset.c\
		img/init_img.c\
		img/init_exit_imgs.c\
		img/init_collect_imgs.c\
		img/init_player_imgs.c\
		img/init_player_down_imgs.c\
		img/init_player_left_imgs.c\
		img/init_player_right_imgs.c\
		img/init_player_up_imgs.c\
		map/init_map.c\
		map/read_map_file.c\
		map/validate_file_name.c\
		map/validate_map.c\
		player/init_player.c
#SRCS_BONUS = 

SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}
#SRCS_BONUS := ${addprefix ${SRC_BONUS_DIR}/, ${SRCS_BONUS}}

OBJS = ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}
#OBJS_BONUS = ${SRCS_BONUS:${SRC_BONUS_DIR}/%.c=${OBJS_BONUS_DIR}/%.o}

#bonus: ${NAME_BONUS}

all: ${NAME}

${OBJS_DIR}:
	mkdir -p objs
	mkdir -p objs/game
	mkdir -p objs/map
	mkdir -p objs/player

# ${OBJS_BONUS_DIR}:
#	mkdir -p objs_bonus

${OBJS}: %.o: ${addsuffix .c,${subst obj,src,${%}}} | ${OBJS_DIR}
	${CC} ${CFLAGS} -c ${patsubst %.o,%.c,${subst obj,src,$@}} -o $@ -I ${INCS_DIR}

#${OBJS_BONUS}: %.o: ${addsuffix .c,${subst obj,src,${%}}} | ${OBJS_BONUS_DIRS}
#	${CC} ${CFLAGS} -c ${patsubst %.o,%.c,${subst obj,src,$@}} -o $@ -I ${INCS_BONUS_DIR}

${NAME}: ${OBJS}
	make -C ${FT_PRINTF_DIR}
	make -C ${GNL_DIR}
	make -C ${MLX_DIR}
	${CC} -g -o ${NAME} ${OBJS} ${LIBS} -I ${INCS_DIR} -L ${MLX_DIR} ${MLX_FLAS}
	mv ${MLX_DIR}/${LIB_MLX} .

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
	${RM} ${NAME} ${LIB_MLX}
#	${RM} ${NAME_BONUS}

re:
	make fclean
	make all

.PHONY: all clean fclean re #bonus