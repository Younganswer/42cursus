/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:13:15 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/17 23:21:29 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int				key_pressed(int key, t_game *game);
static t_bool	key_pressed_while_playing(int key, t_game *game);

int	key_pressed(int key, t_game *game)
{
	if (key == KEY_ESC)
		end_game(game);
	if (game->status == WAITING)
	{
		if (key == KEY_RETURN)
			game->status = PLAYING;
		return (1);
	}
	if (game->status == GAME_CLEAR || game->status == GAME_OVER)
	{
		if (key == KEY_RESET)
			return (reset_game(game));
		if (key == KEY_RETURN)
			end_game(game);
		return (1);
	}
	return (key_pressed_while_playing(key, game));
}

static t_bool	key_pressed_while_playing(int key, t_game *game)
{
	t_bool	moved;

	if (key == KEY_RESET)
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
