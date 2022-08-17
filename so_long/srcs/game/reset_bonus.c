/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:16:55 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/17 23:04:12 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	reset_game(t_game *game)
{
	int	i;
	int	j;

	game->status = PLAYING;
	i = -1;
	while (++i < game->map->size.x)
	{
		j = -1;
		while (++j < game->map->size.y)
		{
			game->map->board[i][j] = game->map->saved[i][j];
			if (game->map->board[i][j] == 'P')
			{
				game->player->collects = 0;
				game->player->moves = 0;
				game->player->position.x = i;
				game->player->position.y = j;
				game->player->direction.x = 0;
				game->player->direction.y = 1;
			}
		}
	}
	return (1);
}
