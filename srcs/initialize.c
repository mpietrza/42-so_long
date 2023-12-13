/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:03:18 by mpietrza          #+#    #+#             */
/*   Updated: 2023/12/13 16:45:19 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_init_img_core(t_data *data,
		int img_width, int img_height, char *img_path)
{
	ft_strlcpy(img_path, "./textures/player_up.xpm\0", 49);
	data->img->player_up = mlx_xpm_file_to_image(data->mlx,
			img_path, &img_width, &img_height);
	ft_strlcpy(img_path, "./textures/player_left.xpm\0", 49);
	data->img->player_left = mlx_xpm_file_to_image(data->mlx,
			img_path, &img_width, &img_height);
	ft_strlcpy(img_path, "./textures/player_down.xpm\0", 49);
	data->img->player_down = mlx_xpm_file_to_image(data->mlx,
			img_path, &img_width, &img_height);
	ft_strlcpy(img_path, "./textures/player_right.xpm\0", 49);
	data->img->player_right = mlx_xpm_file_to_image(data->mlx,
			img_path, &img_width, &img_height);
	ft_strlcpy(img_path, "./textures/background.xpm\0", 49);
	data->img->background = mlx_xpm_file_to_image(data->mlx,
			img_path, &img_width, &img_height);
	ft_strlcpy(img_path, "./textures/wall.xpm\0", 49);
	data->img->wall = mlx_xpm_file_to_image(data->mlx,
			img_path, &img_width, &img_height);
	ft_strlcpy(img_path, "./textures/collectible.xpm\0", 49);
	data->img->collectible = mlx_xpm_file_to_image(data->mlx,
			img_path, &img_width, &img_height);
	ft_strlcpy(img_path, "./textures/exit.xpm\0", 49);
	data->img->exit = mlx_xpm_file_to_image(data->mlx,
			img_path, &img_width, &img_height);
}

static int	ft_init_img(t_data *data)
{
	int		img_width;
	int		img_height;
	char	img_path[50];
	
	data->img = (t_img *)malloc(sizeof(t_img));
	if (!data->img)
		return (-1);
	img_width = 0;
	img_height = 0;
	ft_init_img_core(data, img_width, img_height, img_path);
	return (0);
}

static char	**map_str_to_arr(char *buf_for_arr)
{
	char	**arr = NULL;
	char	c;
	int		y;
	int		x;

	c = 10;
	arr = ft_split(buf_for_arr, c);
	if (!arr)
		return (NULL);
	y = 0;
	while (arr[y])
	{
		x = 0;
		while (arr[y][x])
		{
			if (arr[y][x] == 10)
				arr[y][x] = '\0';
			x++;
		}
		y++;
	}
	return (arr);
}

t_map	*ft_init_map(char *buf_for_arr, t_point *map_size)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		free(buf_for_arr);
		free(map_size);
		ft_error_exit("Error\nNot able to initialize the program\n");
	}
	map->arr = map_str_to_arr(buf_for_arr);
	if (!map->arr)
	{
		free(buf_for_arr);
		free(map_size);
		ft_error_exit("Error\nNot able to initialize the program\n");
	}
	map->map_size = (t_point *)malloc(sizeof(t_point));
	if (!map->map_size)
		{
			free(map->arr);
			free(map_size);
			ft_error_exit("Error\nNot able to initialize the program\n");
		}
	map->map_size->x = map_size->x;
	map->map_size->y = map_size->y;
	ft_clup_map_size(map_size);
	map->player_pos = (t_point *)malloc(sizeof(t_point));
	if (!map->player_pos)
		{
			free(map->arr);
			free(map->map_size);
			ft_error_exit("Error\nNot able to initialize the program\n");
		}
	map->player_pos->x = 0;
	map->player_pos->y = 0;
	map->x = 0;
	map->y = 0;
	map->collectibles = 0;
	return (map);
}

t_data	*ft_init_data(t_map *map)
{
	t_data	*data;
	int		init_img_status;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free(data);
		return (NULL);
	}
	data->window = NULL;
	data->size_x = map->map_size->x * IMG_W;
	data->size_y = map->map_size->y * IMG_H;
	data->pos_x = 0;
	data->pos_y = 0;
	data->counter = 0;
	data->collected = 0;
	init_img_status = ft_init_img(data);
	if (init_img_status == -1)
	{
		free(data->mlx);
		free(data);
		return (NULL);
	}
	data->map = map;
	return (data);
}
