/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:16:30 by mpietrza          #+#    #+#             */
/*   Updated: 2023/12/02 14:36:15 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_put_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			mlx_put_image_to_window(data->mlx, data->window,
				data->img->background, x, y);
			x += IMG_W;
		}
		y += IMG_H;
	}
}

void	ft_put_player(t_data *data, t_map *map)
{
	data->pos_x = map->x;
	data->pos_y = map->y;
	mlx_put_image_to_window(data->mlx, data->window, data->img->player_up,
		(data->pos_x * IMG_W), (data->pos_y * IMG_H));
}

void	ft_put_object(t_data *data, t_map *map, void *img)
{
	mlx_put_image_to_window(data->mlx, data->window, img,
		(map->x * IMG_W), (map->y * IMG_H));
}

void	ft_map_load_textures(t_data *data, t_map *map)
{
	map->x = 0;
	map->y = 0;
	while (map->y < map->map_size->y)
	{
		if (map->arr[map->y][map->x] == '1')
			ft_put_object(data, map, data->img->wall);
		else if (map->arr[map->y][map->x] == 'C')
			ft_put_object(data, map, data->img->collectible);
		else if (map->arr[map->y][map->x] == 'E')
			ft_put_object(data, map, data->img->exit);
		else if (map->arr[map->y][map->x] == 'P')
		{
			ft_put_player(data, map);
			map->player_pos->x = map->x;
			map->player_pos->y = map->y;
		}
		if (map->x < map->map_size->x)
			map->x++;
		else
		{
			map->y++;
			map->x = 0;
		}
	}
}
