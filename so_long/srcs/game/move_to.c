/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:43:21 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/03 22:05:58 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool			move_to(t_game *game, int dx, int dy);
static t_bool	move_to_empty(t_game *game, int dx, int dy);
static t_bool	move_to_collect(t_game *game, int dx, int dy);
static t_bool	move_to_exit(t_game *game, int dx, int dy);

t_bool	move_to(t_game *game, int dx, int dy)
{
	if (game->map->board
		[game->player->position.x + dx][game->player->position.y] == '0')
		move_to_empty(game, dx, dy);
	else if (game->map->board
		[game->player->position.x + dx][game->player->position.y] == 'C')
		move_to_collect(game, dx, dy);
	else if (game->map->board
		[game->player->position.x + dx][game->player->position.y] == 'E'
			&& !game->collects)
		move_to_exit(game, dx, dy);
	else
		return (FALSE);
	return (TRUE);
}

static t_bool	move_to_empty(t_game *game, int dx, int dy)
{
	return (TRUE);
}

static t_bool	move_to_collect(t_game *game, int dx, int dy)
{
	return (TRUE);
}

static t_bool	move_to_exit(t_game *game, int dx, int dy)
{
	return (TRUE);
}
