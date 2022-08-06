/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:19:11 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/06 23:48:38 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool			init_game(t_game *game, char *file);
static t_bool	game_mlx_init(t_game *game);
static t_bool	game_window_init(t_game *game);

t_bool	init_game(t_game *game, char *file)
{
	game = (t_game *) malloc(sizeof(game));
	if (!game)
		exit_with_error("Error: Fail to malloc at game.\n");
	init_map(game, file);
	while (TRUE)
		;
	init_player(game);
	game_mlx_init(game);
	game_window_init(game);
	init_img(game);
	mlx_hook(game->mlx, ON_DESTROY, 0, end_game, game);
	return (TRUE);
}

static t_bool	game_mlx_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_all(game);
		exit_with_error("Error: Fail to init mlx.\n");
	}
	return (TRUE);
}

static t_bool	game_window_init(t_game *game)
{
	game->img_sz.x = TILE_SIZE;
	game->img_sz.y = TILE_SIZE;
	game->window_sz.x = game->map->size.x * TILE_SIZE;
	game->window_sz.y = game->map->size.y * TILE_SIZE;
	game->window = mlx_new_window(\
		game->mlx, game->window_sz.x, game->window_sz.y, "so_long");
	if (!game->window)
	{
		free_all(game);
		exit_with_error("Error: Fail to open window.\n");
	}
	return (TRUE);
}
