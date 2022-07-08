# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 16:03:07 by younhwan          #+#    #+#              #
#    Updated: 2022/07/08 16:16:35 by younhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
NAME = libft.a

SRCS_DIR = .
OBJS_DIR = .
INCS_DIR = .

SOURCES = ${wildcard ${SRCS_DIR}/*.c}
OBJECTS = ${SOURCES:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}

all: ${NAME}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all

${NAME}: ${OBJECTS}
	${AR} ${NAME} ${OBJECTS}

${OBJECTS}: ${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	${CC} ${CFLAGS} -c $< -o $@ -I INCS_DIR

.PHONY: all clean fclean re