/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 00:39:43 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/03 15:10:31 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool			validate_map(t_map *map);
static t_bool	border_is_not_valid(t_map *map);
static t_bool	init_chk_map(t_chk_map *chk_map);
static t_bool	check_data(t_map *map, const char c, t_chk_map *chk_map);
static t_bool	char_is_not_valid(const char c);

t_bool	validate_map(t_map *map)
{
	int			x;
	int			y;
	t_chk_map	*chk_map;

	if (border_is_not_valid(map))
		exit_with_error("Error: Border is not valid.\n");
	init_chk_map(chk_map);
	x = 1;
	while (x < map->size.x)
	{
		y = 1;
		while (y < map->size.y)
		{
			check_data(map, map->char_map[x][y], chk_map);
			y++;
		}
		x++;
	}
	if (!chk_map->exit)
		exit_with_error("Error: There must be at lease one exit.\n");
	if (!chk_map->player)
		exit_with_error("Error: There must be a player.\n");
	if (!chk_map->collects)
		exit_with_error("Error: There must be at least one collect.\n");
	return (TRUE);
}

static t_bool	border_is_not_valid(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->size.x)
	{
		if (!x || x == map->size.x - 1)
		{
			y = 0;
			while (y < map->size.y)
			{
				if (map->char_map[x][y] != '1')
					return (TRUE);
			}
			y++;
		}
		else
		{
			if (map->char_map[x][0] != '1')
				return (TRUE);
			if (map->char_map[x][map->size.y - 1] != '1')
				return (TRUE);
		}
	}
	return (FALSE);
}

static t_bool	init_chk_map(t_chk_map *chk_map)
{
	chk_map->player = FALSE;
	chk_map->exit = 0;
	chk_map->collects = 0;
	return (TRUE);
}

static t_bool	check_data(t_map *map, const char c, t_chk_map *chk_map)
{
	if (char_is_not_valid(c))
		exit_with_error("Error: Map character is not valid.\n");
	if (c == 'P')
	{
		if (!chk_map->player)
			chk_map->player = TRUE;
		else
			exit_with_error("Error: There must be only one player.\n");
	}
	if (c == 'E')
		chk_map->exit++;
	if (c == 'C')
		chk_map->collects++;
	return (TRUE);
}

static t_bool	char_is_not_valid(const char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (TRUE);
	return (FALSE);
}
