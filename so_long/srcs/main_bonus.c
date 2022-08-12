/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 23:42:32 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/13 00:06:55 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	exit_with_error(const char *str);

int	main(int argc, char **argv)
{
	t_game	*game;

	game = 0;
	if (argc != 2)
		exit_with_error("Error\nUsage: ./so_long [MAP_FILE.ber]\n");
	init_game(&game, argv[1]);
	mlx_hook(game->window, ON_KEYDOWN, 0, key_pressed, game);
	mlx_loop_hook(game->mlx, render_game, game);
	mlx_loop(game->mlx);
	return (0);
}

void	exit_with_error(const char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
	return ;
}
