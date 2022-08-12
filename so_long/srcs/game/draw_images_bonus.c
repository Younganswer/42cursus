/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:29:59 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/12 23:23:18 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

t_bool			draw_images(t_game *game, int x, int y);
static t_bool	draw_collects(t_game *game, int x, int y, int cur_img);
static t_bool	draw_player(t_game *game, int x, int y, int cur_img);
static t_bool	draw_ghost(t_game *game, int x, int y, int cur_img);
static t_bool	draw_exit(t_game *game, int x, int y, int cur_img);

t_bool	draw_images(t_game *game, int x, int y)
{
	static int	cur_frame;

	cur_frame = (cur_frame + 1) % 4096;
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
			draw_collects(game, x, y, cur_frame / 512);
		else if (game->map->board[x][y] == 'P')
			draw_player(game, x, y, cur_frame / 512);
		else if (game->map->board[x][y] == 'G')
			draw_ghost(game, x, y, cur_frame / 512);
		else if (game->map->board[x][y] == 'E')
			draw_exit(game, x, y, cur_frame / 512);
	}
	return (TRUE);
}

static t_bool	draw_collects(t_game *game, int x, int y, int cur_img)
{
	mlx_put_image_to_window(\
		game->mlx, game->window, game->img->collect_imgs[cur_img], \
			y * TILE_SIZE, x * TILE_SIZE);
	return (TRUE);
}

static t_bool	draw_player(t_game *game, int x, int y, int cur_img)
{
	int	direction;

	direction = 0;
	if (game->player->direction.y == 1)
		direction = 1;
	else if (game->player->direction.x == 1)
		direction = 2;
	else if (game->player->direction.x == -1)
		direction = 3;
	mlx_put_image_to_window(\
		game->mlx, game->window, \
			game->img->player_imgs[8 * direction + cur_img], \
				y * TILE_SIZE, x * TILE_SIZE);
	return (TRUE);
}

static t_bool	draw_ghost(t_game *game, int x, int y, int cur_img)
{
	mlx_put_image_to_window(\
		game->mlx, game->window, game->img->ghost_imgs[cur_img], \
			y * TILE_SIZE, x * TILE_SIZE);
	return (TRUE);
}

static t_bool	draw_exit(t_game *game, int x, int y, int cur_img)
{
	if (game->collects != game->player->collects)
	{
		mlx_put_image_to_window(\
			game->mlx, game->window, game->img->exit_imgs[8], \
				y * TILE_SIZE, x * TILE_SIZE);
		return (TRUE);
	}
	mlx_put_image_to_window(\
		game->mlx, game->window, game->img->exit_imgs[cur_img], \
			y * TILE_SIZE, x * TILE_SIZE);
	return (TRUE);
}
