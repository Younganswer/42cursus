/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:31:55 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/18 16:37:23 by younhwan         ###   ########.fr       */
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
	ft_memset(game->player, 0, sizeof(game->player));
	game->player->direction.x = 0;
	game->player->direction.y = 1;
	init_player_pos(game);
	return (TRUE);
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
