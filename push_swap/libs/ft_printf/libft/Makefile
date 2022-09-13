# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 16:03:07 by younhwan          #+#    #+#              #
#    Updated: 2022/09/13 22:23:47 by younhwan         ###   ########.fr        #
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
		ft_toupper.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_exit_with_error.c \
		ft_is_space.c

SRCS := ${SRCS:%.c=${SRCS_DIR}/%.c}
OBJS := ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}

all: ${NAME}
	@echo "done"

${NAME}: ${OBJS}
	@${AR} $@ $^

${OBJS}: ${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJS_DIR}
	@${CC} ${CFLAGS} -c $< -o $@ -I ${INCS_DIR}

${OBJS_DIR}:
	@echo "Build libft.a"
	@mkdir -p objs

clean:
	@echo "Remove dependencies in libft"
	@rm -rf ${OBJS_DIR}

fclean: clean
	@echo "Remove libft.a"
	@${RM} ${NAME}

re:
	@echo "Re-build libft.a"
	@make fclean
	@make all

.PHONY: bonus all clean fclean re