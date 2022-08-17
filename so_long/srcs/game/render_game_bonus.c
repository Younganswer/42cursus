/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:27:03 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/17 23:56:07 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int				render_game(t_game *game);
static t_bool	draw_message(t_game *game);
static t_bool	draw_tiles(t_game *game);
static t_bool	draw_moves(t_game *game);

int	render_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	if (game->status != PLAYING)
		draw_message(game);
	else
		draw_tiles(game);
	return (1);
}

static t_bool	draw_message(t_game *game)
{
	if (game->status == WAITING)
		mlx_put_image_to_window(\
			game->mlx, game->window, game->img->start, \
				(game->window_sz.y - game->message_sz.start.y) / 2, \
					(game->window_sz.x - game->message_sz.start.x) / 2);
	else if (game->status == GAME_CLEAR)
		mlx_put_image_to_window(\
			game->mlx, game->window, game->img->game_clear, \
				(game->window_sz.y - game->message_sz.game_clear.y) / 2, \
					(game->window_sz.x - game->message_sz.game_clear.x) / 2);
	else if (game->status == GAME_OVER)
		mlx_put_image_to_window(\
			game->mlx, game->window, game->img->game_over, \
				(game->window_sz.y - game->message_sz.game_over.y) / 2, \
					(game->window_sz.x - game->message_sz.game_over.x) / 2);
	else
	{
		free_all(game);
		exit_with_error("Error\nUnexpected game status");
	}
	return (TRUE);
}

static t_bool	draw_tiles(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map->size.x)
	{
		y = 0;
		while (y < game->map->size.y)
		{
			draw_images(game, x, y);
			y++;
		}
		if (!x)
			draw_moves(game);
		x++;
	}
	return (TRUE);
}

static t_bool	draw_moves(t_game *game)
{
	char	*str;
	int		offset;

	str = ft_itoa(game->player->moves);
	offset = 10 * ft_strlen(str);
	if (game->player->collects < game->collects)
		mlx_string_put(game->mlx, game->window, \
			game->window_sz.y - 8 - offset, 18, -1, str);
	else
		mlx_string_put(game->mlx, game->window, \
			game->window_sz.y - 8 - offset, 18, 15921152, str);
	free(str);
	return (TRUE);
}
