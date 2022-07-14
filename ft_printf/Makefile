# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 16:03:07 by younhwan          #+#    #+#              #
#    Updated: 2022/07/14 21:51:36 by younhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_print.a

LIBFT = libft

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRC_DIR = ./srcs
OBJ_DIR = ./objs
INC_DIR = ./includes

MANDATORY_SOURCES =  

BONUS_SOURCES = 

MANDATORY_SOURCES := ${MANDATORY_SOURCES:%.c=${SRC_DIR}/%.c}
BONUS_SOURCES := ${BONUS_SOURCES:%.c=${SRC_DIR}/%.c}

MANDATORY_OBJECTS = ${MANDATORY_SOURCES:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}
BONUS_OBJECTS = ${BONUS_SOURCES:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}

ifdef WITH_BONUS
	OBJ_FILES = ${MANDATORY_OBJECTS} ${BONUS_OBJECTS}
else
	OBJ_FILES = ${MANDATORY_OBJECTS}
endif

${OBJ_DIR}:
	mkdir -p objs

${OBJ_FILES}: ${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${OBJ_DIR}
	${CC} ${CFLAGS} -c $< -o $@ -I ${INC_DIR}

${NAME}: ${OBJ_FILES}
	${AR} $@ $^

bonus:
	WITH_BONUS=1 make all

all: ${NAME}

#rmdir 고쳐야됨.
clean:
	${RM} ${MANDATORY_OBJECTS} ${BONUS_OBJECTS}
	rmdir ${OBJ_DIR} 

fclean: clean
	${RM} ${NAME}

re:
	make fclean
	make all

.PHONY: bonus all clean fclean re