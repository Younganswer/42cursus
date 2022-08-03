/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:08:30 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/03 21:50:27 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define TILE_SIZE 64

typedef enum e_x_event_key
{
	ON_KEYDOWN = 2,
	ON_MOUSEDOWN = 4,
	ON_DESTROY = 17
}	t_x_event_key;

typedef enum e_keycode
{
	KEY_RESET = 15,
	KEY_ESC = 53,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
	KEY_UP = 126
}	t_keycode;

typedef struct s_obj_img
{
	void	*road_img;
	void	*wall_img;
	void	*under_wall_img;
	void	*collects_img;
	void	*player_img;
	void	*exit_img;
}	t_obj_img;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_coord		window_sz;
	t_obj_img	*img;
	t_map		*map;
	t_player	*player;
	int			collects;
}	t_game;

// init_game.c
t_bool	init_game(t_game *game, int argc, char **argv);

// init_img.c
t_bool	init_img(t_game *game);

// key_pressed.c
int		key_pressed(int key, t_game *game);

// move_to.c
t_bool	move_to(t_game *game, int dx, int dy);

int		update_game(t_game *game);

// reset.c
int		reset_game(t_game *game);

// end_game.c
void	end_game(t_game *game);
t_bool	free_all(t_game *game);

#endif