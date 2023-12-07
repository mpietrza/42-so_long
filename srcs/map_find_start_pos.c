/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_find_start_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:02:56 by mpietrza          #+#    #+#             */
/*   Updated: 2023/11/27 15:03:22 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_map_find_start_pos_core(t_data *data)
{
	int	player;
	int	x;
	int	y;

	player = 0;
	y = 0;
	while (y < (data->size_y / IMG_H))
	{
		x = 0;
		while (x < (data->size_x / IMG_W))
		{
			if (data->map->arr[y][x] == 'P')
			{
				data->map->player_pos_x = x;
				data->map->player_pos_y = y;
				player += 1;
			}
			x++;
		}
		y++;
	}
	return (player);
}

void	ft_map_find_start_pos(t_data *data)
{
	int	player_count;

	player_count = ft_map_find_start_pos_core(data);
	if (player_count == 0)
		cleanup_and_exit(data, "Error\nThere is no players on a map\n");
	if (player_count > 1)
		cleanup_and_exit(data, "Error\nThere are to many players on a map\n");
}
