# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 16:03:07 by younhwan          #+#    #+#              #
#    Updated: 2022/11/25 20:11:52 by younhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL	= /bin/bash
SPINNER	= /-\|/
IDX		= 0

NAME	= megaphone

CC		= clang++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
LDFLAGS	=
AR		= ar rcs
RM		= rm -f

SRCS_DIR	= ./srcs
OBJS_DIR	= ./objs

SRCS = megaphone.cpp
		
SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}
OBJS = ${SRCS:${SRCS_DIR}/%.cpp=${OBJS_DIR}/%.o}


all: ${NAME}


${OBJS_DIR}:
	@echo "Build ${NAME}"
	@mkdir -p objs


${NAME}: ${OBJS}
	@printf "\bdone\n"
	@${CC} ${LDFLAGS} -g -o ${NAME} ${OBJS}
	@echo "Build ${NAME}: done"


${OBJS_DIR}/%.o: ${SRCS_DIR}/%.cpp | ${OBJS_DIR}
	${eval IDX = ${shell expr ${IDX} + 1}}
	${eval T_IDX = ${shell expr ${IDX} % 32}}
	${eval T_IDX = ${shell expr ${T_IDX} / 8 + 1}}
	${eval CHR = ${shell echo ${SPINNER} | cut -c ${T_IDX}}}
	@if [ ${IDX} = 1 ]; then\
		echo -n "Build dependencies in ${NAME} ...  ";\
	fi
	@printf "\b${CHR}"
	@${CC} ${CFLAGS} -g -c $< -o $@


clean:
	@echo "Remove dependencies in ${NAME}"
	@rm -rf ${OBJS_DIR}


fclean: clean
	@echo "Remove ${NAME}"
	@${RM} ${NAME}
	

re:
	@make fclean
	@make all


.PHONY: all clean fclean re