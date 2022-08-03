/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:31:55 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/03 18:36:25 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool	init_player(t_player *player, t_map *map)
{
	int	i;
	int	j;

	player = (t_player *) malloc(sizeof(t_player));
	if (!player)
		exit_with_error("Error: Fail to malloc at player.\n");
	player->moves = 0;
	player->collects = 0;
	i = 0;
	while (i < map->size.x)
	{
		j = 0;
		while (j < map->size.y)
		{
			if (map->char_map[i][j] == 'P')
			{
				player->position.x = i;
				player->position.y = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}
