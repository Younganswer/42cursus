# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 16:03:07 by younhwan          #+#    #+#              #
#    Updated: 2022/07/18 16:27:02 by younhwan         ###   ########.fr        #
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

MANDATORY_SRC_DIR = ./mandatory_srcs
MANDATORY_OBJ_DIR = ./mandatory_objs
BONUS_SRC_DIR = ./bonus_srcs
BONUS_OBJ_DIR = ./bonus_objs

MANDATORY_SOURCES = ft_print_char.c \
					ft_print_hex.c \
					ft_print_nbr.c \
					ft_print_ptr.c \
					ft_print_str.c \
					ft_print_unsigned_int.c \
					ft_printf.c
BONUS_SOURCES = dummy.c

MANDATORY_SOURCES := ${addprefix ${MANDATORY_SRC_DIR}/, ${MANDATORY_SOURCES}}
BONUS_SOURCES := ${addprefix ${BONUS_SRC_DIR}/, ${BONUS_SOURCES}}

MANDATORY_OBJECTS = ${MANDATORY_SOURCES:${MANDATORY_SRC_DIR}/%.c=${MANDATORY_OBJ_DIR}/%.o}
BONUS_OBJECTS = ${BONUS_SOURCES:${BONUS_SRC_DIR}/%.c=${BONUS_OBJ_DIR}/%.o}

ifdef WITH_BONUS
	OBJ_FILES = ${MANDATORY_OBJECTS} ${BONUS_OBJECTS}
	OBJ_DIRS = ${MANDATORY_OBJ_DIR} ${BONUS_OBJ_DIR}
else
	OBJ_FILES = ${MANDATORY_OBJECTS}
	OBJ_DIRS = ${MANDATORY_OBJ_DIR}
endif

#bonus:
#	WITH_BONUS=1 make all

all: ${NAME}

${MANDATORY_OBJ_DIR}:
	mkdir -p mandatory_objs

${BONUS_OBJ_DIR}:
	mkdir -p bonus_objs

${OBJ_FILES}: %.o: ${addsuffix .c,${subst obj,src,${%}}} | ${OBJ_DIRS}
	${CC} ${CFLAGS} -c ${patsubst %.o,%.c,${subst obj,src,$@}} -o $@ -I ${INC_DIR}

${NAME}: ${OBJ_FILES}
	make -C ${LIBFT_DIR}
	cp ${LIBFT_DIR}/${LIBFT_NAME} .
	mv ${LIBFT_NAME} ${NAME}
	${AR} $@ $^

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