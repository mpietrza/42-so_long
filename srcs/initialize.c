/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milosz <milosz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:03:18 by mpietrza          #+#    #+#             */
/*   Updated: 2026/04/21 22:41:51 by milosz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_img_loaded(t_data *data)
{
	return (data->img->player_up && data->img->player_left
		&& data->img->player_down && data->img->player_right
		&& data->img->background && data->img->wall
		&& data->img->collectible && data->img->exit);
}

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

	data->img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!data->img)
		return (-1);
	img_width = 0;
	img_height = 0;
	ft_init_img_core(data, img_width, img_height, img_path);
	if (!ft_img_loaded(data))
		return (-1);
	return (0);
}

static void	ft_init_data_rest(t_data *data, t_map *map)
{
	data->window = NULL;
	data->size_x = map->map_size->x * IMG_W;
	data->size_y = map->map_size->y * IMG_H;
	data->pos_x = 0;
	data->pos_y = 0;
	data->counter = 0;
	data->collected = 0;
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
	ft_init_data_rest(data, map);
	init_img_status = ft_init_img(data);
	if (init_img_status == -1)
	{
		if (data->img)
			ft_clup_img(data);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free(data);
		return (NULL);
	}
	data->map = map;
	return (data);
}
