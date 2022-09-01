/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_input.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:29:18 by younhwan          #+#    #+#             */
/*   Updated: 2022/09/01 13:34:42 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHK_INPUT_H
# define CHK_INPUT_H

# include "../libs/ft_printf/includes/ft_printf.h"
# include "../libs/get_next_line/includes/get_next_line.h"

// has_duplicated.c
t_bool	has_duplicated(int *arr, int n);

// is_not_integer.c
t_bool	is_not_integer(const char *input);

// sort.c
void	sort(int *arr, int start, int end);

#endif