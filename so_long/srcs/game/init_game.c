/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:19:11 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/01 16:57:41 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool	init_game(t_game *game, int argc, char **argv);

t_bool	init_game(t_game *game, int argc, char **argv)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
					game->window_sz.x,
					game->window_sz.y,
					"so_long");	
	if (!init_map(game->map, argc, argv))
		return (FALSE);
	if (!init_player(game->player, game->map))
		return (FALSE);
	return (TRUE);
}
