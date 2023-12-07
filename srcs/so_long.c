/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:20:32 by mpietrza          #+#    #+#             */
/*   Updated: 2023/12/02 14:36:20 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_exit(data);
	else if (keycode == W || keycode == ARR_UP)
		ft_move(data, 'y', UP);
	else if (keycode == A || keycode == ARR_LEFT)
		ft_move(data, 'x', LEFT);
	else if (keycode == S || keycode == ARR_DOWN)
		ft_move(data, 'y', DOWN);
	else if (keycode == D || keycode == ARR_RIGHT)
		ft_move(data, 'x', RIGHT);
	if (data->map->arr[data->pos_y][data->pos_x] == 'E')
		ft_win(data);
	return (0);
}

static int	ft_render_next_frame(t_data *data)
{
	ft_put_background(data);
	ft_map_load_textures(data);
	mlx_hook(data->window, 17, 1L << 2, ft_exit, data);
	mlx_key_hook(data->window, ft_key_hook, data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		ft_error_exit("Error\nNot able to initialize the program\n");
	//Debug start
	ft_printf("Debug1 %d\n%", data->size_x);
	//data initialized debug end
	ft_init_data(data);
	//Debug start
	ft_printf("Debug2 %d\n%", data->size_x);
	//all in data set to 0 and NULL
	ft_window_size(data, argv);
	//Debug start
	ft_printf("Debug3 window size:y = %d x = %d\n%", data->size_y, data->size_x);
	//checked if the map file name and extension is alright and what is the map size
	data->mlx = mlx_init();
	//Debug start
	ft_printf("Debug4 mlx_init %s\n", data->mlx);
	//
	if (!data->mlx)
		ft_free_and_exit(data, "Error\nNot able to initialize the program\n");
	//Debug start
	ft_printf("Debug5 mlx_init check %s\n", data->mlx);
	//
	ft_init_img(data);
	//Debug start
	ft_printf("Debug6 ft_init_img:\nplayer_up = %s,\nexit = %s\n",
		data->img->player_up, data->img->exit);
	ft_init_map(data);
	//Debug start
	ft_printf("Debug 7\n");
	//
	ft_map_parse(data, argv, argc);
	data->window = mlx_new_window(data->mlx,
			data->size_x, data->size_y, "./so_long");
	if (!data->window)
		cleanup_and_exit(data, "Error\nFailed to create window\n");
	ft_render_next_frame(data);
	mlx_loop(data->mlx);
	return (0);
}
