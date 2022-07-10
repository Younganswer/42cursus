# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 16:03:07 by younhwan          #+#    #+#              #
#    Updated: 2022/07/10 11:14:06 by younhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
NAME = libft.a

ESSENTIAL_SOURCE =  ft_atoi.c \
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
					ft_toupper.c \

BONUS_SOURCES = 	ft_lstadd_back.c \
					ft_lstadd_front.c \
					ft_lstclear.c \
					ft_lstdelone.c \
					ft_lstiter.c \
					ft_lstlast.c \
					ft_lstmap.c \
					ft_lstnew.c \
					ft_lstsize.c \


ESSENTIAL_OBJECTS = ${ESSENTIAL_SOURCE:%.c=%.o}
BONUS_OBJECTS = ${BONUS_SOURCES:%.c=%.o}

${ESSENTIAL_OBJECTS}: ${ESSENTIAL_SOURCE}
	${CC} ${CFLAGS} -c $< -o $@ -I .

${NAME}: ${ESSENTIAL_OBJECTS}
	${AR} $@ $^

bonus: ${BONUS_OBJECTS}
	${AR} ${NAME} $^

all: ${NAME}

clean:
	rm -f ${ESSENTIAL_OBJECTS} ${BONUS_OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: bonus all clean fclean re ${NAME}