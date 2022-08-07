/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_collect_imgs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 00:48:18 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/08 00:53:57 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool			init_collect_imgs(t_game *game);
static t_bool	init_collect_imgs_04(t_game *game);
static t_bool	init_collect_imgs_08(t_game *game);

t_bool	init_collect_imgs(t_game *game)
{
	init_collect_imgs_04(game);
	init_collect_imgs_08(game);
	return (TRUE);
}

static t_bool	init_collect_imgs_04(t_game *game)
{
	game->img->collect_imgs[0] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/coin/coin01.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->collect_imgs[1] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/coin/coin02.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->collect_imgs[2] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/coin/coin03.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->collect_imgs[3] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/coin/coin04.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->collect_imgs[0] || !game->img->collect_imgs[1] || \
		!game->img->collect_imgs[2] || !game->img->collect_imgs[3])
	{
		free_all(game);
		exit_with_error("Error\nFail to open collect images.\n");
	}
	return (TRUE);
}

static t_bool	init_collect_imgs_04(t_game *game)
{
	game->img->collect_imgs[4] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/coin/coin05.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->collect_imgs[5] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/coin/coin06.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->collect_imgs[6] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/coin/coin07.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->collect_imgs[7] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/coin/coin08.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->collect_imgs[4] || !game->img->collect_imgs[5] || \
		!game->img->collect_imgs[6] || !game->img->collect_imgs[7])
	{
		free_all(game);
		exit_with_error("Error\nFail to open collect images.\n");
	}
	return (TRUE);
}
