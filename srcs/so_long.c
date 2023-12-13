/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:20:32 by mpietrza          #+#    #+#             */
/*   Updated: 2023/12/13 16:30:45 by mpietrza         ###   ########.fr       */
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

int	ft_open_map_file(char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error_exit("Error\nReading the map not successful\n");
	if (ft_strnstr(argv[1], ".ber", (int)ft_strlen(argv[1])) == NULL)
		ft_error_exit("Error\nWrong map extension, must be a '.ber' file\n");
	return (fd);
}


int	main(int argc, char **argv)
{
	t_data	*data = NULL;
	t_point	*map_size = NULL;
	t_map	*map = NULL;
	char	*buf_for_arr = NULL;
	int		fd;

	if (argc != 2)
		ft_error_exit("Error\nUse: './so_long mappath/mapname.ber'\n");
	if (ft_strnstr(argv[1], ".ber", (int)ft_strlen(argv[1])) == NULL)
		ft_error_exit("Error\nWrong map extension, must be a '.ber' file\n");
	fd = ft_open_map_file(argv);
	map_size = (t_point *)malloc(sizeof(t_point));
	if (!map_size)
	{
		close(fd);
		ft_error_exit("Error\nNot able to initialize the program\n");
	}
	buf_for_arr = ft_map_parse(fd, map_size);
	map = ft_init_map(buf_for_arr, map_size);
	ft_map_checks(map);
	data = ft_init_data(map);
	if (!data)
		ft_clup_map_and_exit(map, "Error\nNot able to initialize the program\n");
	data->window = mlx_new_window(data->mlx,
			data->size_x, data->size_y, "./so_long");
	if (!data->window)
		ft_clup_and_exit(data, "Error\nFailed to create window\n");
	ft_render_next_frame(data);
	mlx_loop(data->mlx);
	return (0);
}
