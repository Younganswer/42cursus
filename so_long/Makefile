# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 16:03:07 by younhwan          #+#    #+#              #
#    Updated: 2022/08/12 23:31:18 by younhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

INCS_DIR = ./includes

FT_PRINTF_DIR = ./libs/ft_printf
GNL_DIR = ./libs/get_next_line

LIBS =	./libs/ft_printf/libftprintf.a\
		./libs/get_next_line/libgnl.a

LIB_MLX = libmlx.dylib
MLX_DIR = ./mlx
MLX_FLAS = -lmlx -framework OpenGL -framework AppKit

SRCS_DIR = ./srcs
OBJS_DIR = ./objs

SRCS = 	main_bonus.c\
		game/draw_images_bonus.c\
		game/end_game_bonus.c\
		game/init_game_bonus.c\
		game/key_pressed_bonus.c\
		game/move_to_bonus.c\
		game/render_game_bonus.c\
		game/reset_bonus.c\
		img/init_imgs_bonus.c\
		img/init_collect_imgs_bonus.c\
		img/init_exit_imgs_bonus.c\
		img/init_ghost_imgs_bonus.c\
		img/init_player_imgs_bonus.c\
		img/init_player_down_imgs_bonus.c\
		img/init_player_left_imgs_bonus.c\
		img/init_player_right_imgs_bonus.c\
		img/init_player_up_imgs_bonus.c\
		map/init_map_bonus.c\
		map/read_map_file_bonus.c\
		map/validate_file_name_bonus.c\
		map/validate_map_bonus.c\
		player/init_player_bonus.c

SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}

OBJS = ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}

all: ${NAME}

bonus:
	make all

${OBJS_DIR}:
	mkdir -p objs
	mkdir -p objs/game
	mkdir -p objs/img
	mkdir -p objs/map
	mkdir -p objs/player

${OBJS}: %.o: ${addsuffix .c,${subst obj,src,${%}}} | ${OBJS_DIR}
	${CC} ${CFLAGS} -c ${patsubst %.o,%.c,${subst obj,src,$@}} -o $@ -I ${INCS_DIR}

${NAME}: ${OBJS}
	make -C ${FT_PRINTF_DIR}
	make -C ${GNL_DIR}
	make -C ${MLX_DIR}
	${CC} -g -o ${NAME} ${OBJS} ${LIBS} -I ${INCS_DIR} -L ${MLX_DIR} ${MLX_FLAS}
	mv ${MLX_DIR}/${LIB_MLX} .

clean:
	make -C ${FT_PRINTF_DIR} clean
	make -C ${GNL_DIR} clean
	make -C ${MLX_DIR} clean
	rm -rf ${OBJS_DIR}

fclean: clean
	make -C ${FT_PRINTF_DIR} fclean
	make -C ${GNL_DIR} fclean
	${RM} ${NAME} ${LIB_MLX}

re:
	make fclean
	make all

.PHONY: all clean fclean re bonus