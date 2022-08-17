/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:08:30 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/17 23:01:20 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_BONUS_H
# define GAME_BONUS_H

# include "so_long_bonus.h"

typedef enum e_x_event_key
{
	ON_KEYDOWN = 2,
	ON_MOUSEDOWN = 4,
	ON_DESTROY = 17
}	t_x_event_key;

typedef enum e_keycode
{
	KEY_RESET = 15,
	KEY_RETURN = 36,
	KEY_ESC = 53,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
	KEY_UP = 126
}	t_keycode;

// init_game_bonus.c
t_bool	init_game(t_game **game, char *file);

// init_img_bonus.c
t_bool	init_img(t_game *game);

// key_pressed_bonus.c
int		key_pressed(int key, t_game *game);

// move_to_bonus.c
t_bool	move_to(t_game *game, int dx, int dy);

// render_game_bonus.c
int		render_game(t_game *game);

// draw_images_bonus.c
t_bool	draw_images(t_game *game, int x, int y);

// reset_bonus.c
int		reset_game(t_game *game);

// end_game_bonus.c
int		end_game(t_game *game);
t_bool	free_all(t_game *game);

#endif