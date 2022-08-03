/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:08:30 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/03 18:43:04 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define TILE_SIZE 64

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
}	t_game;

// init_game.c
t_bool	init_game(t_game *game, int argc, char **argv);

// init_img.c
t_bool	init_img(t_obj_img *img, void *mlx);

int		update_game(t_game *game);
int		reset_game(t_game *game);
int		end_game(t_game *game);

#endif