/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:13:15 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/12 17:45:24 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	key_pressed(int key, t_game *game);

int	key_pressed(int key, t_game *game)
{
	t_bool	moved;

	if (key == KEY_ESC)
		end_game(game);
	else if (key == KEY_RESET)
		return (reset_game(game));
	if (key == KEY_LEFT)
		moved = move_to(game, 0, -1);
	else if (key == KEY_RIGHT)
		moved = move_to(game, 0, 1);
	else if (key == KEY_DOWN)
		moved = move_to(game, 1, 0);
	else if (key == KEY_UP)
		moved = move_to(game, -1, 0);
	else
		return (0);
	if (moved)
		ft_printf("Moves: %d\n", ++game->player->moves);
	return (1);
}
