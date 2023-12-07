/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:06:11 by mpietrza          #+#    #+#             */
/*   Updated: 2023/12/02 14:36:22 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_map_check_content(t_data *data)
{
	int	y;
	int	exit;

	y = 0;
	exit = 0;
	while (data->map->arr && data->map->arr[y])
	{
		exit += ft_count_chars(data->map->arr[y], 'E');
		data->map->collectibles += ft_count_chars(data->map->arr[y], 'C');
		y++;
	}
	if (exit == 0)
		cleanup_and_exit(data,
			"Error\nThere must be at least one exit on a loaded map\n");
	if (exit > 1)
		cleanup_and_exit(data,
			"Error\nThere must be only one exit on a loaded map\n");
	if (data->map->collectibles <= 0)
		cleanup_and_exit(data,
			"Error\nThere is no collectibles on a loaded map\n");
}

static void	ft_map_parse_core_core(t_data *data, char **argv, char *buf)
{
	int	i;
	int	fd;
	int	bytes_read;

	i = 0;
	bytes_read = 1;
	fd = open(argv[1], O_RDONLY);
	//Debug start
	ft_printf("Debug 7.1 fd = %d, argv[1] = %s\n", fd, argv[1]);
	//
	while (bytes_read > 0 && i < data->size_y / IMG_H)
	{
		bytes_read = read(fd, buf, data->size_x / IMG_W + 1);
		//Debug start
		ft_printf("Debug 7.1.1 bytes read = %d,\n buf = \"%s\"\n", bytes_read, buf);
		//
		if (bytes_read == -1)
			ft_error_exit("Error\nFailed to read from the file\n");
		if (buf[bytes_read - 1] == '\n')
		{
			buf[bytes_read - 1] = '\0';
			//Debug start
			ft_printf("Debug 7.1.2\n buf = \"%s\"\n", buf);
			//
		}
		//Debug start
		ft_printf("Debug 7.2 bytes_read = %d, buf= %s\n", bytes_read, buf);
		//
		data->map->arr[i] = ft_strdup(buf);
		//Debug start
		ft_printf("Debug 7.3 data->map->arr[%d] = %s\n", i, data->map->arr[i]);
		//
		i++;
	}
	data->map->arr[i] = NULL;
	ft_printf("Debug 7.3.1 data->map->arr[%d] = %s\n", i, data->map->arr[i]);
	close(fd);
}

static void	ft_map_parse_core(t_data *data, char **argv)
{
	char	*buf;

	data->map->arr
		= (char **)malloc((data->size_y / IMG_H + 1) * sizeof(char *));
	if (!data->map->arr)
		ft_error_exit("Error\nMemory allocation failed\n");
	buf = (char *)malloc((data->size_x / IMG_W) + 1);
	if (!buf)
		ft_error_exit("Error\nMemory allocation failed\n");
	ft_map_parse_core_core(data, argv, buf);
	free(buf);
}

void	ft_map_parse(t_data *data, char **argv, int argc)
{
	if (argc != 2)
		cleanup_and_exit(data, "Error\nUse: './so_long mappath/mapname.ber'\n");
	ft_map_parse_core(data, argv);
	ft_map_find_start_pos(data);
	ft_map_check_content(data);
	ft_map_check_scan(data);
	ft_map_check_path(data);
}
