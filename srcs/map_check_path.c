/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:04:28 by mpietrza          #+#    #+#             */
/*   Updated: 2023/11/29 18:40:46 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	cleanup_t_point_and_map_copy(t_point *size,
		t_point *start, char **map_copy)
{
	int	y;

	y = 0;
	if (size)
		free(size);
	if (start)
		free(start);
	if (map_copy)
	{
		while (map_copy[y])
		{
			free(map_copy[y]);
			y++;
		}
		free(map_copy);
	}
}

static void	ft_map_check_path_core(t_data *data,
		t_point *size, t_point *start, char **map_copy)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->size_y / IMG_H)
	{
		x = 0;
		while (x < data->size_x / IMG_W)
		{
			if (map_copy[y][x] == 'C')
			{
				cleanup_t_point_and_map_copy(size, start, map_copy);
				cleanup_and_exit(data,
					"Error\nThere is no valid path on the map\n");
			}
			x++;
		}
		y++;
	}
}

void	ft_map_check_path(t_data *data)
{
	char	**map_copy;
	t_point	*size;
	t_point	*start;

	map_copy = ft_map_temp(data);
	size = (t_point *)malloc(sizeof(t_point));
	start = (t_point *)malloc(sizeof(t_point));
	if (!size || !start)
	{
		cleanup_t_point_and_map_copy(size, start, map_copy);
		cleanup_and_exit(data, "Error\nMemory allocation failed\n");
	}
	size->x = data->size_x / IMG_W;
	size->y = data->size_y / IMG_H;
	start->x = data->map->player_pos_x;
	start->y = data->map->player_pos_y;
	ft_flood_fill(map_copy, size, start);
	ft_map_check_path_core(data, size, start, map_copy);
	cleanup_t_point_and_map_copy(size, start, map_copy);
}
