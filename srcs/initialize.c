/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:03:18 by mpietrza          #+#    #+#             */
/*   Updated: 2023/12/02 14:36:17 by mpietrza         ###   ########.fr       */
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

void	ft_init_img(t_data *data)
{
	int		img_width;
	int		img_height;
	char	img_path[50];

	img_width = 0;
	img_height = 0;
	ft_init_img_core(data, img_width, img_height, img_path);
}

void	ft_init_map(t_data *data)
{
	data->map->x = 0;
	data->map->y = 0;
	data->map->collectibles = 0;
	data->map->player_pos_x = 0;
	data->map->player_pos_y = 0;
	ft_printf("Debug 6.5\n");
}

void	ft_init_data(t_data *data)
{
	data->mlx = NULL;
	data->window = NULL;
	data->size_x = 0;
	data->size_y = 0;
	data->pos_x = 0;
	data->pos_y = 0;
	data->counter = 0;
	data->collected = 0;
	data->map = (t_map *)malloc(sizeof(t_map));
	ft_printf("Debug 1.1\n");
	if (!data->map)
	{
		free(data);
		ft_error_exit("Error\nMemory allocation not succesful\n");
	}
	data->img = (t_img *)malloc(sizeof(t_img));
	if (!data->img)
	{
		free(data->map);
		free(data);
		ft_error_exit("Error\nMemory allocation not succesful\n");
	}
}
