/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_find_start_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:02:56 by mpietrza          #+#    #+#             */
/*   Updated: 2023/12/13 17:53:20 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_map_find_start_pos_core(t_map *map)
{
	int	player;
	int	x;
	int	y;

	player = 0;
	y = 0;
	while (y < map->map_size->y)
	{
		x = 0;
		while (x < map->map_size->x)
		{
			if (map->arr[y][x] == 'P')
			{
				map->player_pos->x = x;
				map->player_pos->y = y;
				player += 1;
			}
			x++;
		}
		y++;
	}
	return (player);
}

void	ft_map_find_start_pos(t_map *map)
{
	int		player_count;

	player_count = ft_map_find_start_pos_core(map);
	if (player_count == 0)
		ft_clup_map_and_exit(map, "Error\nThere is no players on a map\n");
	if (player_count > 1)
		ft_clup_map_and_exit(map,
			"Error\nThere are to many players on a map\n");
}
