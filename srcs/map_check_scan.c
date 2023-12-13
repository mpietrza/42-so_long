/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_scan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:07:26 by mpietrza          #+#    #+#             */
/*   Updated: 2023/12/13 17:52:42 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_map_check_scan_core(t_map *map, int x, int y)
{
	char	c;

	c = map->arr[y][x];
	if (!(c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P'))
	{
		ft_clup_map_and_exit(map,
			"Error\nLoaded map file has wrong symbols\n");
	}
	if ((y == 0 || x == 0 || y == map->map_size->y - 1
			|| x == map->map_size->x - 1) && c != '1')
		ft_clup_map_and_exit(map,
			"Error\nLoaded map is not closed by walls\n");
}

void	ft_map_check_scan(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->map_size->y)
	{
		x = 0;
		while (x < map->map_size->x)
		{
			ft_map_check_scan_core(map, x, y);
			x++;
		}
		y++;
	}
}
