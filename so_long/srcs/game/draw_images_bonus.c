/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:29:59 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/17 22:59:03 by younhwan         ###   ########.fr       */
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

	cur_frame = (cur_frame + 1) % 6144;
	if (game->map->board[x][y] == '1')
		mlx_put_image_to_window(\
			game->mlx, game->window, game->img->wall, \
				y * TILE_SIZE, x * TILE_SIZE);
	else
	{
		mlx_put_image_to_window(\
			game->mlx, game->window, game->img->empty, \
				y * TILE_SIZE, x * TILE_SIZE);
		if (game->map->board[x][y] == 'C')
			draw_collects(game, x, y, cur_frame / 768);
		else if (game->map->board[x][y] == 'P')
			draw_player(game, x, y, cur_frame / 768);
		else if (game->map->board[x][y] == 'G')
			draw_ghost(game, x, y, cur_frame / 768);
		else if (game->map->board[x][y] == 'E')
			draw_exit(game, x, y, cur_frame / 768);
	}
	return (TRUE);
}

static t_bool	draw_collects(t_game *game, int x, int y, int cur_img)
{
	mlx_put_image_to_window(\
		game->mlx, game->window, game->img->collect[cur_img], \
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
			game->img->player[8 * direction + cur_img], \
				y * TILE_SIZE, x * TILE_SIZE);
	return (TRUE);
}

static t_bool	draw_ghost(t_game *game, int x, int y, int cur_img)
{
	mlx_put_image_to_window(\
		game->mlx, game->window, game->img->ghost[cur_img], \
			y * TILE_SIZE, x * TILE_SIZE);
	return (TRUE);
}

static t_bool	draw_exit(t_game *game, int x, int y, int cur_img)
{
	if (game->collects != game->player->collects)
	{
		mlx_put_image_to_window(\
			game->mlx, game->window, game->img->exit[8], \
				y * TILE_SIZE, x * TILE_SIZE);
		return (TRUE);
	}
	mlx_put_image_to_window(\
		game->mlx, game->window, game->img->exit[cur_img], \
			y * TILE_SIZE, x * TILE_SIZE);
	return (TRUE);
}
