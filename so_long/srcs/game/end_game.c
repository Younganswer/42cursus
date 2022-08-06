/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 19:23:20 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/06 22:02:05 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int				end_game(t_game *game);
t_bool			free_all(t_game *game);
static t_bool	free_img(t_game *game);
static t_bool	free_map(t_game *game);

int	end_game(t_game *game)
{
	free_all(game);
	exit(0);
	return (1);
}

t_bool	free_all(t_game *game)
{
	if (!game)
		return (TRUE);
	free_img(game);
	free_map(game);
	free(game->img);
	free(game->map);
	free(game->player);
	free(game);
	return (TRUE);
}

static t_bool	free_img(t_game *game)
{
	if (!game->img)
		return (TRUE);
	free(game->img->road_img);
	free(game->img->wall_img);
	free(game->img->under_wall_img);
	free(game->img->collects_img);
	free(game->img->player_img);
	free(game->img->exit_img);
	free(game->img);
	return (TRUE);
}

static t_bool	free_map(t_game *game)
{
	int	i;

	if (!game->map)
		return (TRUE);
	if (game->map->saved)
	{
		i = 0;
		while (i < game->map->size.x)
			free(game->map->saved[i++]);
		free(game->map->saved);
	}
	if (game->map->board)
	{
		i = 0;
		while (i < game->map->size.x)
			free(game->map->board[i++]);
		free(game->map->board);
	}
	free(game->map);
	return (TRUE);
}
