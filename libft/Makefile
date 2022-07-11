# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 16:03:07 by younhwan          #+#    #+#              #
#    Updated: 2022/07/11 14:21:20 by younhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

MANDATORY_SOURCE =  ft_atoi.c \
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

BONUS_SOURCES = 	ft_lstadd_back.c \
					ft_lstadd_front.c \
					ft_lstclear.c \
					ft_lstdelone.c \
					ft_lstiter.c \
					ft_lstlast.c \
					ft_lstmap.c \
					ft_lstnew.c \
					ft_lstsize.c

MANDATORY_OBJECTS = ${MANDATORY_SOURCE:%.c=%.o}
BONUS_OBJECTS = ${BONUS_SOURCES:%.c=%.o}

ifdef WITH_BONUS
	OBJ_FILES = ${MANDATORY_OBJECTS} ${BONUS_OBJECTS}
else
	OBJ_FILES = ${MANDATORY_OBJECTS}
endif

.c.o:
	${CC} ${CFLAGS} -c $< -o $@ -I .

${NAME}: ${OBJ_FILES}
	${AR} $@ $^

bonus:
	WITH_BONUS=1 make all

all: ${NAME}

clean:
	${RM} ${MANDATORY_OBJECTS} ${BONUS_OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: bonus all clean fclean re