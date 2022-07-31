# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 16:03:07 by younhwan          #+#    #+#              #
#    Updated: 2022/08/01 00:17:15 by younhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = libft
LIBFT_NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

INC_DIR = ./includes

SRC_DIR = ./srcs
OBJ_DIR = ./objs

#SRC_BONUS_DIR = ./srcs_bonus
#OBJ_BONUS_DIR = ./objs_bonus

SRCS = 	ft_print_char.c \
		ft_print_hex.c \
		ft_print_nbr.c \
		ft_print_ptr.c \
		ft_print_str.c \
		ft_print_unsigned_int.c \
		ft_printf.c

#SRC_BONUS = 

SRCS := ${addprefix ${SRC_DIR}/, ${SRCS}}
#SRC_BONUS := ${addprefix ${SRC_BONUS_DIR}/, ${SRC_BONUS}}

OBJS = ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}
#OBJS_BONUS = ${SRC_BONUS:${SRC_BONUS_DIR}/%.c=${OBJ_BONUS_DIR}/%.o}

ifdef WITH_BONUS
	OBJ_FILES = ${OBJS} ${OBJS_BONUS}
	OBJ_DIRS = ${OBJ_DIR} ${OBJ_BONUS_DIR}
else
	OBJ_FILES = ${OBJS}
	OBJ_DIRS = ${OBJ_DIR}
endif

#bonus:
#	WITH_BONUS=1 make all

all: ${NAME}

# ${OBJ_BONUS_DIR}:
# 	mkdir -p objs_bonus

${OBJ_DIR}:
	mkdir -p objs

${OBJ_FILES}: %.o: ${addsuffix .c,${subst obj,src,${%}}} | ${OBJ_DIRS}
	${CC} ${CFLAGS} -c ${patsubst %.o,%.c,${subst obj,src,$@}} -o $@ -I ${INC_DIR}

${NAME}: ${OBJ_FILES}
	make -C ${LIBFT_DIR}
	cp ${LIBFT_DIR}/${LIBFT_NAME} .
	mv ${LIBFT_NAME} ${NAME}
	${AR} $@ $^

clean:
	make -C ${LIBFT_DIR} clean
	rm -rf ${OBJ_DIR}
#	rm -rf ${OBJ_BONUS_DIR}

fclean: clean
	${RM} ${NAME}
	${RM} ${LIBFT_DIR}/${LIBFT_NAME}

re:
	make fclean
	make all

.PHONY: all clean fclean re #bonus