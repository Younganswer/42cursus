# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 16:03:07 by younhwan          #+#    #+#              #
#    Updated: 2022/10/05 11:17:51 by younhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL	= /bin/bash
SPINNER	= /-\|/
IDX		= 0

NAME	= philo_bonus

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

INCS_DIR	= ./incs
SRCS_DIR	= ./srcs
OBJS_DIR	= ./objs

SRCS = 	philo_bonus.c\
		utils/ft_atoi_bonus.c\
		utils/ft_exit_with_error_bonus.c\
		utils/ft_putstr_fd_bonus.c\
		utils/ft_sem_open_bonus.c\
		utils/diff_time_bonus.c\
		utils/kill_all_with_error_bonus.c\
		utils/time_passed_bonus.c\
		monitor/monitor_bonus.c\
		routine/routine_bonus.c
		
SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}
OBJS = ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}


all: ${NAME}


${OBJS_DIR}:
	@echo "Build philo"
	@mkdir -p objs
	@mkdir -p objs/utils
	@mkdir -p objs/monitor
	@mkdir -p objs/routine


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
	@${CC} ${CFLAGS} -g -c $< -o $@ -I ${INCS_DIR} -fsanitize=thread


clean:
	@echo "Remove dependencies in philo"
	@rm -rf ${OBJS_DIR}


fclean: clean
	@echo "Remove philo"
	@${RM} ${NAME}
	

re:
	@make fclean
	@make all


.PHONY: all clean fclean re