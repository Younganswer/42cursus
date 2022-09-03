/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:29:18 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/03 15:17:15 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INPUT_H
# define PARSE_INPUT_H

# include "../libs/ft_printf/includes/ft_printf.h"
# include "../libs/get_next_line/includes/get_next_line.h"
# include "tools.h"
# include "stack.h"

// parse_input.c
t_bool	parse_input(t_stack *a, int argc, char **argv);

// has_duplicated.c
t_bool	has_duplicated(int *arr, int n);

// init_arr.c
t_arr	*init_arr(t_stack *a);

// is_not_integer.c
t_bool	is_not_integer(const char *input);

// sort.c
void	sort(int *arr, int start, int end);

#endif