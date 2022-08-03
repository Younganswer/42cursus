/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:19:11 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/03 18:30:41 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool			init_game(t_game *game, int argc, char **argv);
static t_bool	init_img(t_obj_img *obj_img, void *mlx);

t_bool	init_game(t_game *game, int argc, char **argv)
{
	game = (t_game *) malloc(sizeof(game));
	if (!game)
		exit_with_error("Error: Fail to malloc at game.\n");
	init_map(game->map, argc, argv);
	init_player(game->player, game->map);
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_with_error("Error: Fail to init mlx.\n");
	game->window_sz.x = game->map->size.x * TILE_SIZE;
	game->window_sz.y = game->map->size.y * TILE_SIZE;
	game->window = mlx_new_window(game->mlx,
					game->window_sz.x,
					game->window_sz.y,
					"so_long");	
	if (!game->window)
		exit_with_error("Error: Fail to open window.\n");
	init_img(game->img, game->mlx);
	return (TRUE);
}

static t_bool	init_img(t_obj_img *obj_img, void *mlx)
{
	obj_img->road_img = mlx_xpm_file_to_image(\
		mlx, "../../assets/road.xpm", TILE_SIZE, TILE_SIZE);
	if (!obj_img->road_img)
		exit_with_error("Error: Fail to read road image.\n");
	obj_img->wall_img = mlx_xpm_file_to_image(\
		mlx, "../../assets/trees.xpm", TILE_SIZE, TILE_SIZE);
	if (!obj_img->wall_img)
		exit_with_error("Error: Fail to read wall image.\n");
	obj_img->under_wall_img = mlx_xpm_file_to_image(\
		mlx, "../../assets/grass.xpm", TILE_SIZE, TILE_SIZE);
	if (!obj_img->under_wall_img)
		exit_with_error("Error: Fail to read under wall image.\n");
	obj_img->collects_img = mlx_xpm_file_to_image(\
		mlx, "../../assets/apple.xpm", TILE_SIZE, TILE_SIZE);
	if (!obj_img->collects_img)
		exit_with_error("Error: Fail to read collects image.\n");
	obj_img->exit_img = mlx_xpm_file_to_image(\
		mlx, "../../assets/door_close.xpm", TILE_SIZE, TILE_SIZE);
	if (!obj_img->exit_img)
		exit_with_error("Error: Fail to read exit image.\n");
	obj_img->player_img = mlx_xpm_file_to_image(\
		mlx, "../../assets/BryceSlime/idle/BryceIdle1.xpm", TILE_SIZE, TILE_SIZE);
	if (!obj_img->player_img)
		exit_with_error("Error: Fail to read player image.\n");
	return (TRUE);
}
