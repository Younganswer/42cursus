# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 16:03:07 by younhwan          #+#    #+#              #
#    Updated: 2022/08/01 00:25:48 by younhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS_DIR = ./srcs
OBJS_DIR = ./objs
INCS_DIR = ./includes

SRCS =  ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c
		
SRCS_BONUS = 	ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c

SRCS := ${addprefix ${SRC_DIR}/, ${SRCS}}
SRCS_BONUS := ${addprefix ${SRC_BONUS_DIR}/, ${SRCS_BONUS}}

OBJS = ${SRCS:${SRC_DIR}/%.c=${OBJS_DIR}/%.o}
OBJS_BONUS = ${SRCS_BONUS:${SRC_DIR}/%.c=${OBJS_DIR}/%.o}

ifdef WITH_BONUS
	OBJ_FILES = ${OBJS} ${OBJS_BONUS}
else
	OBJ_FILES = ${OBJS}
endif

bonus:
	WITH_BONUS=1 make all

${NAME}: ${OBJ_FILES}
	${AR} $@ $^

${OBJ_FILES}: %.o: ${addsuffix .c,${subst obj,src,${%}}}| ${OBJS_DIR}
	${CC} ${CFLAGS} -c ${patsubst %.o,%.c,${subst obj,src,$@}} -o $@ -I ${INCS_DIR}

${OBJS_DIR}:
	mkdir -p objs

all: ${NAME}

clean:
	rm -rf ${OBJS_DIR}

fclean: clean
	${RM} ${NAME}

re:
	make fclean
	make all

.PHONY: bonus all clean fclean re