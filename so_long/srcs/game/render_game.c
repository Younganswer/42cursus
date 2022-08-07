/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:27:03 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/08 01:21:59 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int				render_game(t_game *game);
static t_bool	draw_image(t_game *game, int x, int y);

int	render_game(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map->size.x)
	{
		y = 0;
		while (y < game->map->size.y)
		{
			draw_image(game, x, y);
			y++;
		}
		x++;
	}
	return (1);
}

static t_bool	draw_image(t_game *game, int x, int y)
{
	if (game->map->board[x][y] == '1')
	{
		mlx_put_image_to_window(\
			game->mlx, game->window, game->img->wall_img, \
				y * TILE_SIZE, x * TILE_SIZE);
	}
	else
	{
		mlx_put_image_to_window(\
			game->mlx, game->window, game->img->empty_img, \
				y * TILE_SIZE, x * TILE_SIZE);
		if (game->map->board[x][y] == 'C')
			mlx_put_image_to_window(\
				game->mlx, game->window, game->img->collect_imgs[0], \
					y * TILE_SIZE, x * TILE_SIZE);
		else if (game->map->board[x][y] == 'P')
			mlx_put_image_to_window(\
				game->mlx, game->window, game->img->player_imgs[0], \
					y * TILE_SIZE, x * TILE_SIZE);
		else if (game->map->board[x][y] == 'E')
			mlx_put_image_to_window(\
				game->mlx, game->window, game->img->exit_imgs[8], \
					y * TILE_SIZE, x * TILE_SIZE);
	}
	return (TRUE);
}
