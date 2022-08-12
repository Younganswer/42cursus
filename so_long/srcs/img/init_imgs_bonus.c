/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:43:27 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/13 01:18:12 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

t_bool			init_imgs(t_game *game);
static t_bool	init_map_imgs(t_game *game);
static t_bool	init_message_imgs(t_game *game);

t_bool	init_imgs(t_game *game)
{
	game->img = (t_objs_img *) malloc(sizeof(t_objs_img));
	if (!game->img)
	{
		free_all(game);
		exit_with_error("Error\nFail to malloc images.\n");
	}
	game->message_sz.x = 96;
	game->message_sz.x = 32;
	init_map_imgs(game);
	init_collect_imgs(game);
	init_ghost_imgs(game);
	init_player_imgs(game);
	init_exit_imgs(game);
	init_message_imgs(game);
	return (TRUE);
}

static t_bool	init_map_imgs(t_game *game)
{
	game->img->empty_img = mlx_xpm_file_to_image(\
		game->mlx, "./assets/empty/empty.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->wall_img = mlx_xpm_file_to_image(\
		game->mlx, "./assets/wall/wall.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->empty_img || !game->img->wall_img)
	{
		free_all(game);
		exit_with_error("Error: Fail to read map images.\n");
	}
	return (TRUE);
}

static t_bool	init_message_imgs(t_game *game)
{
	game->img->clear_img = mlx_xpm_file_to_image(\
		game->mlx, "./assets/message/clear.xpm", \
			&game->message_sz.x, &game->message_sz.y);
	game->img->game_over_img = mlx_xpm_file_to_image(\
		game->mlx, "./assets/message/game_over.xpm", \
			&game->message_sz.x, &game->message_sz.y);
	if (!game->img->clear_img || !game->img->game_over_img)
	{
		free_all(game);
		exit_with_error("Error: Fail to read map images.\n");
	}
	return (TRUE);
}
