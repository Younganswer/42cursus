/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:43:27 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/18 16:24:22 by younhwan         ###   ########.fr       */
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
	ft_memset(game->img, 0, sizeof(game->img));
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
	game->img->empty = mlx_xpm_file_to_image(\
		game->mlx, "./assets/empty/empty.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->wall = mlx_xpm_file_to_image(\
		game->mlx, "./assets/wall/wall.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->empty || !game->img->wall)
	{
		free_all(game);
		exit_with_error("Error: Fail to read map images.\n");
	}
	return (TRUE);
}

static t_bool	init_message_imgs(t_game *game)
{
	game->message_sz.start.x = 32;
	game->message_sz.start.y = 192;
	game->message_sz.game_clear.x = 32;
	game->message_sz.game_clear.y = 96;
	game->message_sz.game_over.x = 32;
	game->message_sz.game_over.y = 96;
	game->img->start = mlx_xpm_file_to_image(\
		game->mlx, "./assets/message/start.xpm", \
			&game->message_sz.start.y, &game->message_sz.start.x);
	game->img->game_clear = mlx_xpm_file_to_image(\
		game->mlx, "./assets/message/clear.xpm", \
			&game->message_sz.game_clear.y, &game->message_sz.game_clear.x);
	game->img->game_over = mlx_xpm_file_to_image(\
		game->mlx, "./assets/message/game_over.xpm", \
			&game->message_sz.game_over.y, &game->message_sz.game_over.x);
	if (!game->img->start || !game->img->game_clear || !game->img->game_over)
	{
		free_all(game);
		exit_with_error("Error: Fail to read map images.\n");
	}
	return (TRUE);
}
