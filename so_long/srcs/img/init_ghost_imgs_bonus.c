/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ghost_imgs_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 00:48:18 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/12 23:24:41 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

t_bool			init_ghost_imgs(t_game *game);
static t_bool	init_ghost_imgs_04(t_game *game);
static t_bool	init_ghost_imgs_08(t_game *game);

t_bool	init_ghost_imgs(t_game *game)
{
	init_ghost_imgs_04(game);
	init_ghost_imgs_08(game);
	return (TRUE);
}

static t_bool	init_ghost_imgs_04(t_game *game)
{
	game->img->ghost_imgs[0] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/ghost/ghost01.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->ghost_imgs[1] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/ghost/ghost02.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->ghost_imgs[2] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/ghost/ghost03.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->ghost_imgs[3] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/ghost/ghost04.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->ghost_imgs[0] || !game->img->ghost_imgs[1] || \
		!game->img->ghost_imgs[2] || !game->img->ghost_imgs[3])
	{
		free_all(game);
		exit_with_error("Error\nFail to open ghost images.\n");
	}
	return (TRUE);
}

static t_bool	init_ghost_imgs_08(t_game *game)
{
	game->img->ghost_imgs[4] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/ghost/ghost05.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->ghost_imgs[5] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/ghost/ghost06.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->ghost_imgs[6] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/ghost/ghost07.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->ghost_imgs[7] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/ghost/ghost08.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->ghost_imgs[4] || !game->img->ghost_imgs[5] || \
		!game->img->ghost_imgs[6] || !game->img->ghost_imgs[7])
	{
		free_all(game);
		exit_with_error("Error\nFail to open ghost images.\n");
	}
	return (TRUE);
}
