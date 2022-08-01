/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:14:53 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/01 23:42:04 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# define IMG_SIZE 64

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

void	exit_with_error(const char *str);

#endif