/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 23:42:32 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/03 21:12:17 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_with_error(const char *str);

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		exit_with_error("Usage: ./so_long [MAP_FILE.ber]\n");
	init_game(game, argc, argv);
	mlx_hook(game->window, ON_KEYDOWN, 0, key_pressed, (void *) game);
	return (0);
}

void	exit_with_error(const char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
	return ;
}
