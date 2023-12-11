/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:03:18 by mpietrza          #+#    #+#             */
/*   Updated: 2023/12/11 18:30:06 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_init_img_core(t_map *map,
		int img_width, int img_height, char *img_path)
{
	ft_strlcpy(img_path, "./textures/player_up.xpm\0", 49);
	mg->player_up = mlx_xpm_file_to_image(data->mlx,
			img_path, &img_width, &img_height);
	ft_strlcpy(img_path, "./textures/player_left.xpm\0", 49);
	img->player_left = mlx_xpm_file_to_image(data->mlx,
			img_path, &img_width, &img_height);
	ft_strlcpy(img_path, "./textures/player_down.xpm\0", 49);
	img->player_down = mlx_xpm_file_to_image(data->mlx,
			img_path, &img_width, &img_height);
	ft_strlcpy(img_path, "./textures/player_right.xpm\0", 49);
	img->player_right = mlx_xpm_file_to_image(data->mlx,
			img_path, &img_width, &img_height);
	ft_strlcpy(img_path, "./textures/background.xpm\0", 49);
	img->background = mlx_xpm_file_to_image(data->mlx,
			img_path, &img_width, &img_height);
	ft_strlcpy(img_path, "./textures/wall.xpm\0", 49);
	img->wall = mlx_xpm_file_to_image(data->mlx,
			img_path, &img_width, &img_height);
	ft_strlcpy(img_path, "./textures/collectible.xpm\0", 49);
	img->collectible = mlx_xpm_file_to_image(data->mlx,
			img_path, &img_width, &img_height);
	ft_strlcpy(img_path, "./textures/exit.xpm\0", 49);
	img->exit = mlx_xpm_file_to_image(data->mlx,
			img_path, &img_width, &img_height);
}

t_img	*ft_init_img(void)
{
	int		img_width;
	int		img_height;
	char	img_path[50];
	t_img	img;
	
	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img_width = 0;
	img_height = 0;
	ft_init_img_core(img, img_width, img_height, img_path);
	return (img);
}

static char	**map_str_to_arr(char *buff_for_arr, t_point window_size)
{
	char	**arr = NULL;
	char	c;
	int		y;

	c = 10;
	arr = ft_split(map_str_to_arr, c);
	if (!arr)
		return (NULL);
	return (arr);
}

t_map	ft_init_map(char *buff_for_arr, t_point *window_size)
{
	t_map	map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		free(window_size);
		ft_error_exit("Error\nNot able to initialize the program\n");
	}
	map->arr = map_str_to_arr(buf_for_arr, window_size);
	if (!map->arr)
	{
		free(window_size);
		free(map);
		ft_error_exit("Error\nNot able to initialize the program\n");
	}
	map->x = 0;
	map->y = 0;
	map->collectibles = 0;
	map->player_pos_x = 0;
	map->player_pos_y = 0;
	ft_printf("Debug 6.5\n");
	return (map);
}

t_data	*ft_init_data(t_point *map_size)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx = mlx_init();
	if (!data->mlx)
		reuturn (NULL);//!
	data->window = NULL;
	data->size_x = map_size->x * IMG_W;
	data->size_y = map_size->y * IMG_H;
	ft_cleanup_map_size(map_size);
	data->pos_x = 0;
	data->pos_y = 0;
	data->counter = 0;
	data->collected = 0;
	ft_printf("Debug 1.1\n");
	data->img = ft_init_img(void);
	if (!data->img)
		return (NULL);
	return (data);
}
