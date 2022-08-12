/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:14:53 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/12 23:30:08 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "so_long_bonus.h"

# define TILE_SIZE 32

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

//	main_bonus.c
void	exit_with_error(const char *str);

#endif