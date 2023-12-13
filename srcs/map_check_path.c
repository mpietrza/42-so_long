/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:04:28 by mpietrza          #+#    #+#             */
/*   Updated: 2023/12/13 16:42:23 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_clup_arr_copy(char **arr_copy)
{
	int	y;

	y = 0;
	if (arr_copy)
	
	{
		while (arr_copy[y])
		{
			free(arr_copy[y]);
			y++;
		}
		free(arr_copy);
	}
}

static void ft_map_check_path_core(t_map *map, char **arr_copy)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->map_size->y)
	{
		x = 0;
		while (x < map->map_size->x)
		{
			if (arr_copy[y][x] == 'C')
				ft_clup_map_and_exit(map,
					"Error\nThere is no valid path on the map\n");
			x++;
		}
		y++;
	}
}

void	ft_map_check_path(t_map *map)
{
	char	**arr_copy;

	arr_copy = ft_arr_temp(map);
	ft_flood_fill(arr_copy, map->map_size, map->player_pos);
	ft_map_check_path_core(map, arr_copy);
	ft_clup_arr_copy(arr_copy);
}
