# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 16:03:07 by younhwan          #+#    #+#              #
#    Updated: 2022/07/15 02:56:47 by younhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_print.a

LIBFT_DIR = libft
LIBFT_NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

INC_DIR = ./includes

MANDATORY_SRC_DIR = ./mandatory_srcs
MANDATORY_OBJ_DIR = ./mandatory_objs
BONUS_SRC_DIR = ./bonus_srcs
BONUS_OBJ_DIR = ./bonus_objs

MANDATORY_SOURCES = ${wildcard ${MANDATORY_SRC_DIR}/*.c}
BONUS_SOURCES = ${wildcard ${bonus_srcs}/*.c}

MANDATORY_OBJECTS = ${MANDATORY_SOURCES:${MANDATORY_SRC_DIR}/%.c=${MANDATORY_OBJ_DIR}/%.o}
BONUS_OBJECTS = ${BONUS_SOURCES:${BONUS_SRC_DIR}/%.c=${BONUS_OBJ_DIR}/%.o}

ifdef WITH_BONUS
	OBJ_FILES = ${MANDATORY_OBJECTS} ${BONUS_OBJECTS}
else
	OBJ_FILES = ${MANDATORY_OBJECTS}
endif

bonus: ${BONUS_OBJ_DIR}
	WITH_BONUS=1 make all

${MANDATORY_OBJ_DIR}:
	mkdir -p mandatory_objs

${BONUS_OBJ_DIR}:
	mkdir -p bonus_objs

${OBJ_FILES}: ${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${MANDATORY_OBJ_DIR}
	${CC} ${CFLAGS} -c $< -o $@ -I ${INC_DIR}

${NAME}: ${OBJ_FILES}
	make -C ${LIBFT_DIR}
	cp ${LIBFT_DIR}/${LIBFT_NAME} .
	mv ${LIBFT_NAME} ${NAME}
	${AR} $@ $^

all: ${NAME}

clean:
	rm -rf ${MANDATORY_OBJ_DIR}
	rm -rf ${BONUS_OBJ_DIR}
	make clean -C ${LIBFT_DIR} 

fclean: clean
	${RM} ${NAME}
	${RM} ${LIBFT_DIR}/${LIBFT_NAME}

re:
	make fclean
	make all

.PHONY: bonus all clean fclean re