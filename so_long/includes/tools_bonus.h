/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:14:53 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/13 14:21:04 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_BONUS_H
# define TOOLS_BONUS_H

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

typedef struct s_map
{
	t_coord		size;
	char		**saved;
	char		**board;
}	t_map;

typedef struct s_player
{
	t_coord	position;
	t_coord	direction;
	int		moves;
	int		collects;
}	t_player;

typedef struct s_objs_img
{
	void	*empty_img;
	void	*wall_img;
	void	*clear_img;
	void	*game_over_img;
	void	*collect_imgs[8];
	void	*player_imgs[32];
	void	*ghost_imgs[8];
	void	*exit_imgs[9];
}	t_objs_img;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_coord		window_sz;
	t_objs_img	*img;
	t_coord		img_sz;
	t_coord		message_sz;
	t_map		*map;
	t_player	*player;
	int			collects;
}	t_game;

//	main_bonus.c
void	exit_with_error(const char *str);

#endif