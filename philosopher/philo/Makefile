# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 16:03:07 by younhwan          #+#    #+#              #
#    Updated: 2022/09/28 12:47:31 by younhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL	= /bin/bash
SPINNER	= /-\|/
IDX		= 0

NAME	= philo

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

INCS_DIR	= ./incs
SRCS_DIR	= ./srcs
OBJS_DIR	= ./objs

SRCS = 	philo.c\
		utils/ft_atoi.c\
		utils/ft_exit_with_error.c\
		utils/ft_putstr_fd.c\
		monitor/monitor.c\
		behavior/behavior.c
		
SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}
OBJS = ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}

all: ${NAME}


${OBJS_DIR}:
	@echo "Build philo"
	@mkdir -p objs
	@mkdir -p objs/utils
	@mkdir -p objs/monitor
	@mkdir -p objs/behavior


${NAME}: ${OBJS}
	@printf "\bdone\n"
	@${CC} -g -o ${NAME} ${OBJS} -I ${INCS_DIR}
	@echo "Build philo: done"


${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJS_DIR}
	${eval IDX = ${shell expr ${IDX} + 1}}
	${eval T_IDX = ${shell expr ${IDX} % 32}}
	${eval T_IDX = ${shell expr ${T_IDX} / 8 + 1}}
	${eval CHR = ${shell echo ${SPINNER} | cut -c ${T_IDX}}}
	@if [ ${IDX} = 1 ]; then\
		echo -n "Build dependencies in philo ...  ";\
	fi
	@printf "\b${CHR}"
	@${CC} ${CFLAGS} -g -c $< -o $@ -I ${INCS_DIR}


clean:
	@echo "Remove dependencies in philo"
	@rm -rf ${OBJS_DIR}


fclean: clean
	@echo "Remove philo"
	@${RM} ${NAME}
	

re:
	@make fclean
	@make all


.PHONY: all clean fclean re bonus