/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_down_imgs_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 01:04:36 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/17 23:26:46 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

t_bool			init_player_down_imgs(t_game *game);
static t_bool	init_player_down_imgs_20(t_game *game);
static t_bool	init_player_down_imgs_24(t_game *game);

t_bool	init_player_down_imgs(t_game *game)
{
	init_player_down_imgs_20(game);
	init_player_down_imgs_24(game);
	return (TRUE);
}

static t_bool	init_player_down_imgs_20(t_game *game)
{
	game->img->player[16] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/down/p_down01.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->player[17] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/down/p_down02.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->player[18] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/down/p_down03.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->player[19] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/down/p_down04.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->player[16] || !game->img->player[17] || \
		!game->img->player[18] || !game->img->player[19])
	{
		free_all(game);
		exit_with_error("Error\nFail to open player down images.\n");
	}
	return (TRUE);
}

static t_bool	init_player_down_imgs_24(t_game *game)
{
	game->img->player[20] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/down/p_down05.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->player[21] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/down/p_down06.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->player[22] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/down/p_down07.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->player[23] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/down/p_down08.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->player[20] || !game->img->player[21] || \
		!game->img->player[22] || !game->img->player[23])
	{
		free_all(game);
		exit_with_error("Error\nFail to open player down images.\n");
	}
	return (TRUE);
}
