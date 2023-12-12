/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:03:02 by mpietrza          #+#    #+#             */
/*   Updated: 2023/12/12 14:26:08 by mpietrza         ###   ########.fr       */
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
		if (data->img->player_up)
			data->img->player_up = NULL;
		if (data->img->player_left)
			mlx_destroy_image(data->mlx, data->img->player_left);
		if (data->img->player_left)
			data->img->player_left = NULL;
		if (data->img->player_down)
			mlx_destroy_image(data->mlx, data->img->player_down);
		if (data->img->player_down)
			data->img->player_down = NULL;
		if (data->img->player_right)
			mlx_destroy_image(data->mlx, data->img->player_right);
		if (data->img->player_right)
			data->img->player_right = NULL;
		if (data->img->background)
			mlx_destroy_image(data->mlx, data->img->background);
		if (data->img->background)
			data->img->background = NULL;
		if (data->img->wall)
			mlx_destroy_image(data->mlx, data->img->wall);
		if (data->img->wall)
			data->img->wall = NULL;
		if (data->img->collectible)
			mlx_destroy_image(data->mlx, data->img->collectible);
		if (data->img->collectible)
			data->img->collectible = NULL;
		if (data->img->exit)
			mlx_destroy_image(data->mlx, data->img->exit);
		if (data->img->exit)
			data->img->exit = NULL;
		ft_printf("Debug: ft_cleanup_img->\n");
	}
	free(data->img);
	ft_printf("Debug: ft_cleanup_img\n");

}

void	ft_clup_map(t_map *map)
{
	int	i;

	i = 0;
	if (map)
	{
		if (map->arr)
		{
			if (map->arr[i])
			{
				while (map->arr[i])
				{
					free(map->arr[i]);
					ft_printf("debug: freed ft_cleanup_map->arr[%d]\n", i);
					i++;
				}
			}
			free(map->arr);
			ft_printf("debug: freed ft_cleanup_map->arr\n");
			if (map->map_size)
				free(map->map_size);
			if (map->player_pos)
				free(map->player_pos);
		}
		free(map);
		ft_printf("debug: free(map) - ft_cleanup_map complete\n");
	}
}

void	ft_clup_data(t_data *data)
{
	if (data)
	{
		if (data->mlx && data->window)
		{
			ft_printf("debug: ft_cleanup_data->mlx && data->window started\n");
			mlx_destroy_window(data->mlx, data->window);
			ft_printf("debug: mlx_destroy_window(data->mlx, data->window) done\n");

		}
		if (data->img)
		{
			ft_clup_img(data);
			ft_printf("debug: ft_cleanup_img complete\n");
		}
		if (data->mlx)
		{
			data->mlx = NULL;
			ft_printf("debug: free(data->mlx) done\n");
		}
		free(data);
		ft_printf("debug: ft_cleanup_data complete\n");
	}
}

