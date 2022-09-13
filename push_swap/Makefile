# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 16:03:07 by younhwan          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2022/09/13 23:27:07 by younhwan         ###   ########.fr        #
=======
#    Updated: 2022/09/13 23:20:29 by younhwan         ###   ########.fr        #
>>>>>>> d73e10b600cb6c9d7f5c18fcdefa726da90484c6
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FT_PRINTF_DIR = ./libs/ft_printf
GNL_DIR = ./libs/get_next_line

LIBS =	./libs/ft_printf/libftprintf.a\
		./libs/get_next_line/libgnl.a

INCS_DIR = ./incs
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

SRCS = 	push_swap.c\
		divide/divide.c\
		divide/set_triangles.c\
		divide/push_2_a_to_b.c\
		divide/push_2_b_to_a.c\
		divide/push_3_a_to_b.c\
		divide/push_3_b_to_a.c\
		divide/push_4_a_to_b.c\
		divide/push_4_b_to_a.c\
		divide/push_5_a_to_b.c\
		divide/push_5_b_to_a.c\
		merge/merge.c\
		merge/make_normal.c\
		merge/make_reversed.c\
		parse_input/parse_input.c\
		parse_input/has_duplicated.c\
		parse_input/sort_arr.c\
		sort_small/sort_small.c\
		sort_small/sort_small_2.c\
		sort_small/sort_small_3.c\
		sort_small/sort_small_4.c\
		sort_small/sort_small_5.c\
		stack/init_node.c\
		stack/init_stack.c\
		stack/pop.c\
		stack/push.c\
		stack/push_ab.c\
		stack/rotate.c\
		stack/reverse_rotate.c\
		stack/stack_utils.c\
		stack/swap.c
		
SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}
OBJS = ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}

INCS_BONUS_DIR = ./incs_bonus
SRCS_BONUS_DIR = ./srcs_bonus
OBJS_BONUS_DIR = ./objs_bonus

SRCS_BONUS = main_bonus.c
SRCS_BONUS := ${addprefix ${SRCS_BONUS_DIR}/, ${SRCS_BONUS}}
OBJS_BONUS = ${SRCS_BONUS:${SRCS_BONUS_DIR}/%.c=${OBJS_BONUS_DIR}/%.o}

OUTPUT = output.txt


all: ${OBJS_DIR} ${NAME}


bonus: ${NAME_BONUS}
	@make all


# Default argc = 100
ARGC = 100

# Use with pipe pbcopy
# make generate_arguments | pbcopy
generate_arguments:
	@ruby -e "puts (1..${ARGC}).to_a.shuffle.join(' ')"

# Check memory leaks with lldb push_swap argc
chk_leaks: ${OBJS_DIR} ${NAME}
	while true; do leaks `ps | grep /push_swap/push_swap | awk 'NR==1 {print $$1}'`; sleep 1; done;

# make run ARGC=[number_of_input]
run: ${OBJS_DIR} ${NAME}
	./push_swap `ruby -e "puts (1..${ARGC}).to_a.shuffle.join(' ')"` > ${OUTPUT}
	@wc -l output.txt | awk '{print "Number of instructions:", $$1}'

${OBJS_DIR}:
	@echo "Build push_swap"
	@mkdir -p objs
	@mkdir -p objs/divide
	@mkdir -p objs/merge
	@mkdir -p objs/parse_input
	@mkdir -p objs/sort_small
	@mkdir -p objs/stack


${NAME}: ${OBJS}
	@make -C ${FT_PRINTF_DIR}
	@make -C ${GNL_DIR}
	@${CC} -g -o ${NAME} ${OBJS} ${LIBS} -I ${INCS_DIR}
	@echo "Build push_swap: done"


${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@${CC} ${CFLAGS} -g -c $< -o $@ -I ${INCS_DIR}


${OBJS_BONUS_DIR}:
	@echo "Build checker"
	@mkdir -p objs_bonus


${OBJS_BONUS}: %.o: ${addsuffix .c,${subst obj,src,${%}}} | ${OBJS_BONUS_DIR}
	@${CC} ${CFLAGS} -g -c ${patsubst %.o,%.c,${subst obj,src,$@}} -o $@ -I ${INCS_BONUS_DIR}


${NAME_BONUS}: ${OBJS_BONUS}
	@make -C ${FT_PRINTF_DIR}
	@make -C ${GNL_DIR}
	@${CC} -g -o ${NAME_BONUS} ${OBJS_BONUS} ${LIBS} -I ${INCS_BONUS_DIR}
	@echo "Build checker: done"


clean:
	@echo "Remove dependencies in push_swap"
	@make -C ${FT_PRINTF_DIR} clean
	@make -C ${GNL_DIR} clean
	@rm -rf ${OBJS_DIR} ${OBJS_BONUS_DIR}


fclean: clean
	@echo "Remove push_swap, checker"
	@make -C ${FT_PRINTF_DIR} fclean
	@make -C ${GNL_DIR} fclean
	@${RM} ${NAME} ${NAME_BONUS}
	@${RM} ${OUTPUT}
	

re:
	@echo "Re-build push_swap"
	@make fclean
	@make all


.PHONY: all clean fclean re bonus