/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:13:54 by mpietrza          #+#    #+#             */
/*   Updated: 2023/12/13 17:55:39 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_free_and_exit1(char *buf_for_arr, t_point *map_size)
{
	free(buf_for_arr);
	free(map_size);
	ft_error_exit("Error\nNot able to initialize the program\n");
}

static void	ft_free_and_exit2(t_point *map_size, t_map *map)
{
	if (map)
	{
		ft_cleanup_map_array(map->arr, map_size->y);
		free(map);
	}
	free(map_size);
	ft_error_exit("Error\nNot able to initialize the program\n");
}

void	ft_cleanup_map_array(char **arr, int j)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (i < j)
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

static void	ft_init_map_rest(t_map *map)
{
	map->player_pos = (t_point *)malloc(sizeof(t_point));
	if (!map->player_pos)
	{
		ft_cleanup_map_array(map->arr, map->map_size->y);
		free(map->map_size);
		ft_error_exit("Error\nNot able to initialize the program\n");
	}
	map->player_pos->x = 0;
	map->player_pos->y = 0;
	map->x = 0;
	map->y = 0;
	map->collectibles = 0;
}

t_map	*ft_init_map(char *buf_for_arr, t_point *map_size)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		ft_free_and_exit1(buf_for_arr, map_size);
	map->arr = ft_map_str_to_arr(buf_for_arr);
	if (!map->arr)
	{
		ft_free_and_exit1(buf_for_arr, map_size);
		free(map);
	}
	map->map_size = (t_point *)malloc(sizeof(t_point));
	if (!map->map_size)
		ft_free_and_exit2(map_size, map);
	map->map_size->x = map_size->x;
	map->map_size->y = map_size->y;
	ft_clup_map_size(map_size);
	ft_init_map_rest(map);
	return (map);
}
