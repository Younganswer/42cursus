/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:27:03 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/12 17:57:44 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	render_game(t_game *game);

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
		x++;
	}
	return (1);
}
