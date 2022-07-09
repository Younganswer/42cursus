# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 16:03:07 by younhwan          #+#    #+#              #
#    Updated: 2022/07/10 01:49:00 by younhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
NAME = libft.a

SRCS_DIR = .
OBJS_DIR = .
INCS_DIR = .

ESSENTIAL_SOURCE =  ft_atoi.c \
					ft_bzero.c \
					ft_calloc.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_itoa.c \
					ft_lstsize.c \
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
					ft_toupper.c \

BONUS_SOURCES = 	ft_lstadd_back.c \
					ft_lstadd_front.c \
					ft_lstclear.c \
					ft_lstdelone.c \
					ft_lstiter.c \
					ft_lstlast.c \
					ft_lstmap.c \
					ft_lstnew.c \

ESSETIAL_OBJECTS = ${ESSENTIAL_SOURCE:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}
BONUS_OBJECTS = ${BONUS_SOURCES:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}

${ESSETIAL_OBJECTS}: ${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	${CC} ${CFLAGS} -c $< -o $@ -I INCS_DIR

${NAME}: ${ESSETIAL_OBJECTS}
	${AR} $@ $^

bonus: ${BONUS_OBJECTS}
	${AR} ${NAME} $^

all: ${NAME}

clean:
	rm -f ${ESSETIAL_OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: bonus all clean fclean re ${NAME}