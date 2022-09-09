/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:29:18 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/09 15:04:14 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INPUT_H
# define PARSE_INPUT_H

# include "../libs/ft_printf/includes/ft_printf.h"
# include "../libs/get_next_line/includes/get_next_line.h"
# include "structs.h"
# include "tools.h"
# include "stack.h"

// parse_input.c
t_bool	parse_input(t_stack *a, int argc, char **argv);

// has_duplicated.c
t_bool	has_duplicated(t_stack *a);

// is_not_integer.c
t_bool	is_not_integer(const char *input);

// sort_arr.c
void	sort_arr(int *arr, int start, int end);

#endif