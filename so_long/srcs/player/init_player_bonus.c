/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:31:55 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/12 23:26:15 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

t_bool			init_player(t_game *game);
static t_bool	init_player_pos(t_game *game);

t_bool	init_player(t_game *game)
{
	game->player = (t_player *) malloc(sizeof(t_player));
	if (!game->player)
	{
		free_all(game);
		exit_with_error("Error: Fail to malloc at player.\n");
	}
	game->player->direction.x = 0;
	game->player->direction.y = 1;
	game->player->moves = 0;
	game->player->collects = 0;
	init_player_pos(game);
	return (FALSE);
}

static t_bool	init_player_pos(t_game *game)
{
	int	i;
	int	j;

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
	return (TRUE);
}
