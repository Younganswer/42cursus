/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:29:18 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/05 21:25:34 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INPUT_H
# define PARSE_INPUT_H

# include "../libs/ft_printf/libft/incs/libft.h"
# include "structs.h"
# include "stack.h"

// parse_input.c
t_bool	parse_input(t_stack *a, int argc, char **argv);

// has_duplicated.c
t_bool	has_duplicated(t_stack *a);

// sort_arr.c
t_bool	sort_arr(int *arr, int start, int end);

#endif