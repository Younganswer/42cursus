/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_collect_imgs_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 00:48:18 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/17 23:24:35 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

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
	game->img->collect[0] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/coin/coin01.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->collect[1] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/coin/coin02.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->collect[2] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/coin/coin03.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->collect[3] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/coin/coin04.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->collect[0] || !game->img->collect[1] || \
		!game->img->collect[2] || !game->img->collect[3])
	{
		free_all(game);
		exit_with_error("Error\nFail to open collect images.\n");
	}
	return (TRUE);
}

static t_bool	init_collect_imgs_08(t_game *game)
{
	game->img->collect[4] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/coin/coin05.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->collect[5] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/coin/coin06.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->collect[6] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/coin/coin07.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->collect[7] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/coin/coin08.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->collect[4] || !game->img->collect[5] || \
		!game->img->collect[6] || !game->img->collect[7])
	{
		free_all(game);
		exit_with_error("Error\nFail to open collect images.\n");
	}
	return (TRUE);
}
