/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milosz <milosz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:03:02 by mpietrza          #+#    #+#             */
/*   Updated: 2026/04/21 22:41:51 by milosz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_clup_map_size(t_point *map_size)
{
	if (map_size)
		free(map_size);
}

void	ft_clup_img(t_data *data)
{
	if (data->img)
	{
		if (data->img->player_up)
			mlx_destroy_image(data->mlx, data->img->player_up);
		if (data->img->player_left)
			mlx_destroy_image(data->mlx, data->img->player_left);
		if (data->img->player_down)
			mlx_destroy_image(data->mlx, data->img->player_down);
		if (data->img->player_right)
			mlx_destroy_image(data->mlx, data->img->player_right);
		if (data->img->background)
			mlx_destroy_image(data->mlx, data->img->background);
		if (data->img->wall)
			mlx_destroy_image(data->mlx, data->img->wall);
		if (data->img->collectible)
			mlx_destroy_image(data->mlx, data->img->collectible);
		if (data->img->exit)
			mlx_destroy_image(data->mlx, data->img->exit);
	}
	free(data->img);
}

void	ft_clup_map(t_map *map)
{
	int	i;

	i = 0;
	if (map)
	{
		if (map->arr)
		{
			while (i < map->map_size->y)
			{
				free(map->arr[i]);
				i++;
			}
			free(map->arr);
			if (map->map_size)
				free(map->map_size);
			if (map->player_pos)
				free(map->player_pos);
		}
		free(map);
	}
}

void	ft_clup_data(t_data *data)
{
	if (data)
	{
		if (data->img)
			ft_clup_img(data);
		if (data->mlx && data->window)
			mlx_destroy_window(data->mlx, data->window);
		if (data->mlx)
		{
			mlx_destroy_display(data->mlx);
			free(data->mlx);
		}
		if (data->map)
			ft_clup_map(data->map);
		free(data);
	}
}
