/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:31:55 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/03 21:26:36 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool	init_player(t_game *game)
{
	int	i;
	int	j;

	game->player = (t_player *) malloc(sizeof(t_player));
	if (!game->player)
	{
		free_all(game);
		exit_with_error("Error: Fail to malloc at player.\n");
	}
	game->player->moves = 0;
	game->player->collects = 0;
	i = -1;
	while (++i < game->map->size.x)
	{
		j = -1;
		while (++j < game->map->size.y)
		{
			if (game->map->saved[i][j] == 'P')
			{
				game->player->position.x = i;
				game->player->position.y = j;
				return (TRUE);
			}
		}
	}
}
