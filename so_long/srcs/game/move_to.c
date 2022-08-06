/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:43:21 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/07 02:37:23 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool			move_to(t_game *game, int dx, int dy);
static t_bool	move_to_empty(t_game *game, int dx, int dy);
static t_bool	move_to_collect(t_game *game, int dx, int dy);
static t_bool	move_to_exit(t_game *game, int dx, int dy);

t_bool	move_to(t_game *game, int dx, int dy)
{
	int	next_x;
	int	next_y;

	next_x = game->player->position.x + dx;
	next_y = game->player->position.y + dy;
	if (next_x < 0 || next_y < 0)
		return (FALSE);
	if (game->map->size.x <= next_x || game->map->size.y <= next_y)
		return (FALSE);
	if (game->map->board[next_x][next_y] == '0')
		move_to_empty(game, dx, dy);
	else if (game->map->board[next_x][next_y] == 'C')
		move_to_collect(game, dx, dy);
	else if (game->map->board[next_x][next_y] == 'E'\
			&& game->collects == game->player->collects)
	{
		move_to_exit(game, dx, dy);
		end_game(game);
	}
	else
		return (FALSE);
	return (TRUE);
}

static t_bool	move_to_empty(t_game *game, int dx, int dy)
{
	game->map->board[game->player->position.x][game->player->position.y] = '0';
	game->player->position.x += dx;
	game->player->position.y += dy;
	game->map->board[game->player->position.x][game->player->position.y] = 'P';
	return (TRUE);
}

static t_bool	move_to_collect(t_game *game, int dx, int dy)
{
	game->map->board[game->player->position.x][game->player->position.y] = '0';
	game->player->position.x += dx;
	game->player->position.y += dy;
	game->map->board[game->player->position.x][game->player->position.y] = 'P';
	game->player->collects++;
	return (TRUE);
}

static t_bool	move_to_exit(t_game *game, int dx, int dy)
{
	game->map->board[game->player->position.x][game->player->position.y] = '0';
	game->player->position.x += dx;
	game->player->position.y += dy;
	game->map->board[game->player->position.x][game->player->position.y] = 'P';
	return (TRUE);
}
