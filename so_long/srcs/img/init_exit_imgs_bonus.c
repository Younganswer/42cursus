/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exit_imgs_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 00:54:20 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/17 23:25:23 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

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
	game->img->exit[8] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/exit/exit.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->exit[8])
	{
		free_all(game);
		exit_with_error("Error\nFail to open closed exit image.\n");
	}
	return (TRUE);
}

static t_bool	init_exit_img_04(t_game *game)
{
	game->img->exit[0] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/exit/exit01.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->exit[1] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/exit/exit02.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->exit[2] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/exit/exit03.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->exit[3] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/exit/exit04.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->exit[0] || !game->img->exit[1] || \
		!game->img->exit[2] || !game->img->exit[3])
	{
		free_all(game);
		exit_with_error("Error\nFail to open exit images.\n");
	}
	return (TRUE);
}

static t_bool	init_exit_img_08(t_game *game)
{
	game->img->exit[4] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/exit/exit05.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->exit[5] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/exit/exit06.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->exit[6] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/exit/exit07.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	game->img->exit[7] = mlx_xpm_file_to_image(\
		game->mlx, "./assets/exit/exit08.xpm", \
			&game->img_sz.x, &game->img_sz.y);
	if (!game->img->exit[4] || !game->img->exit[5] || \
		!game->img->exit[6] || !game->img->exit[7])
	{
		free_all(game);
		exit_with_error("Error\nFail to open exit images.\n");
	}
	return (TRUE);
}
