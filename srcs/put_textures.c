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

void	ft_put_player(t_data *data)
{
	data->pos_x = data->map->x;
	data->pos_y = data->map->y;
	mlx_put_image_to_window(data->mlx, data->window, data->img->player_up,
		(data->pos_x * IMG_W), (data->pos_y * IMG_H));
}

void	ft_put_object(t_data *data, void *img)
{
	mlx_put_image_to_window(data->mlx, data->window, img,
		(data->map->x * IMG_W), (data->map->y * IMG_H));
}

void	ft_map_load_textures(t_data *data)
{
	data->map->x = 0;
	data->map->y = 0;
	while (data->map->y < data->map->map_size->y)
	{
		if (data->map->arr[data->map->y][data->map->x] == '1')
			ft_put_object(data, data->img->wall);
		else if (data->map->arr[data->map->y][data->map->x] == 'C')
			ft_put_object(data, data->img->collectible);
		else if (data->map->arr[data->map->y][data->map->x] == 'E')
			ft_put_object(data, data->img->exit);
		else if (data->map->arr[data->map->y][data->map->x] == 'P')
		{
			ft_put_player(data);
			data->map->player_pos->x = data->map->x;
			data->map->player_pos->y = data->map->y;
		}
		if (data->map->x < data->map->map_size->x)
			data->map->x++;
		else
		{
			data->map->y++;
			data->map->x = 0;
		}
	}
}
