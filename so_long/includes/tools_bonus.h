/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:14:53 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/25 18:44:59 by younhwan         ###   ########.fr       */
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
	void	*empty;
	void	*wall;
	void	*start;
	void	*game_clear;
	void	*game_over;
	void	*collect[8];
	void	*player[32];
	void	*ghost[8];
	void	*exit[9];
}	t_objs_img;

typedef enum e_status
{
	WAITING = 0,
	PLAYING = 1,
	GAME_CLEAR = 2,
	GAME_OVER = 3,
}	t_status;

typedef struct s_message
{
	t_coord	start;
	t_coord	game_clear;
	t_coord	game_over;
}	t_message;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_coord		window_sz;
	t_objs_img	*img;
	t_coord		img_sz;
	t_message	message_sz;
	t_map		*map;
	t_player	*player;
	t_status	status;
	int			collects;
	int			frame;
}	t_game;

//	main_bonus.c
void	exit_with_error(const char *str);

#endif