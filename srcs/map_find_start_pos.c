/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_find_start_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:02:56 by mpietrza          #+#    #+#             */
/*   Updated: 2023/12/12 14:25:45 by mpietrza         ###   ########.fr       */
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

t_point	*ft_map_find_start_pos(t_map *map)
{
	int		player_count;
	t_point	*player_pos = NULL;


	player_pos = (t_point *)malloc(sizeof(t_point));
	if (!player_pos)
		ft_clup_map_and_exit(map, "Error\nNot able to initialize the program\n");
	player_count = ft_map_find_start_pos_core(map);
	if (player_count == 0)
		ft_clup_map_and_exit(map, "Error\nThere is no players on a map\n");
	if (player_count > 1)
		ft_clup_map_and_exit(map, "Error\nThere are to many players on a map\n");
	return (player_pos);
}
