/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_dup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:29:18 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/31 23:50:02 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHK_DUP_H
# define CHK_DUP_H

# include "../libs/ft_printf/includes/ft_printf.h"
# include "../libs/get_next_line/includes/get_next_line.h"

// sort.c
void	sort(int *arr, int start, int end);

// has_duplicated.c
t_bool	has_duplicated(int *arr);

#endif