/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:27:03 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/12 23:43:58 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int				render_game(t_game *game);
static t_bool	draw_moves(t_game *game);

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
			draw_images(game, x, y);
			y++;
		}
		if (!x)
			draw_moves(game);
		x++;
	}
	return (1);
}

static t_bool	draw_moves(t_game *game)
{
	char	*str;
	int		offset;

	str = ft_itoa(game->player->moves);
	offset = 10 * ft_strlen(str);
	if (game->player->collects < game->collects)
		mlx_string_put(game->mlx, game->window, \
			game->window_sz.y - 4 - offset, TILE_SIZE / 2, \
				-1, str);
	else
		mlx_string_put(game->mlx, game->window, \
			game->window_sz.y - 4 - offset, TILE_SIZE / 2, \
				15921152, str);
	free(str);
	return (TRUE);
}
