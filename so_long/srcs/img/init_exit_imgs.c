/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exit_imgs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 00:54:20 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/08 01:01:12 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool			init_exit_imgs(t_game *game);
static t_bool	init_closed_exit_img(t_game *game);
static t_bool	init_exit_img_04(t_game *game);
static t_bool	init_exit_img_08(t_game *game);

t_bool	init_exit_imgs(t_game *game)
{
	init_closed_exit_img(game);
	init_exit_img_04(game);
	init_exit_img_08(game);
	return (TRUE);
}

static t_bool	init_closed_exit_img(t_game *game)
{
	game->img->exit_imgs[8] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/exit/exit.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->exit_imgs[8])
	{
		free_all(game);
		exit_with_error("Error\nFail to open closed exit image.\n");
	}
	return (TRUE);
}

static t_bool	init_exit_img_04(t_game *game)
{
	game->img->exit_imgs[0] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/exit/exit01.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->exit_imgs[1] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/exit/exit02.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->exit_imgs[2] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/exit/exit03.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->exit_imgs[3] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/exit/exit04.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->exit_imgs[0] || !game->img->exit_imgs[1] || \
		!game->img->exit_imgs[2] || !game->img->exit_imgs[3])
	{
		free_all(game);
		exit_with_error("Error\nFail to open exit images.\n");
	}
	return (TRUE);
}

static t_bool	init_exit_img_04(t_game *game)
{
	game->img->exit_imgs[4] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/exit/exit05.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->exit_imgs[5] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/exit/exit06.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->exit_imgs[6] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/exit/exit07.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->exit_imgs[7] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/exit/exit08.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->exit_imgs[4] || !game->img->exit_imgs[5] || \
		!game->img->exit_imgs[6] || !game->img->exit_imgs[7])
	{
		free_all(game);
		exit_with_error("Error\nFail to open exit images.\n");
	}
	return (TRUE);
}
