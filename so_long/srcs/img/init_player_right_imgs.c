/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_right_imgs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 01:04:36 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/08 01:15:48 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool			init_player_right_imgs(t_game *game);
static t_bool	init_player_right_imgs_12(t_game *game);
static t_bool	init_player_right_imgs_16(t_game *game);

t_bool	init_player_right_imgs(t_game *game)
{
	init_player_right_imgs_12(game);
	init_player_right_imgs_16(game);
	return (TRUE);
}

static t_bool	init_player_right_imgs_12(t_game *game)
{
	game->img->player_imgs[8] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/right/p_right01.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->player_imgs[9] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/right/p_right02.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->player_imgs[10] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/right/p_right03.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->player_imgs[11] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/right/p_right04.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->player_imgs[8] || !game->img->player_imgs[9] || \
		!game->img->player_imgs[10] || !game->img->player_imgs[11])
	{
		free_all(game);
		exit_with_error("Error\nFail to open player right images.\n");
	}
	return (TRUE);
}

static t_bool	init_player_right_imgs_16(t_game *game)
{
	game->img->player_imgs[12] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/right/p_right05.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->player_imgs[13] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/right/p_right06.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->player_imgs[14] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/right/p_right07.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->player_imgs[15] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/player/right/p_right08.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->player_imgs[12] || !game->img->player_imgs[13] || \
		!game->img->player_imgs[14] || !game->img->player_imgs[15])
	{
		free_all(game);
		exit_with_error("Error\nFail to open player right images.\n");
	}
	return (TRUE);
}
