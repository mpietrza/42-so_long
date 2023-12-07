/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_scan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:07:26 by mpietrza          #+#    #+#             */
/*   Updated: 2023/12/02 13:28:52 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_map_check_scan_core(t_data *data, int x, int y)
{
	char	c;

	c = data->map->arr[y][x];
	if (!(c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P'))
	{
		if (c == '\n')
			cleanup_and_exit(data, "Error\nLoaded map is not rectangular\n");
		cleanup_and_exit(data, "Error\nLoaded map file has wrong symbols\n");
	}
	if ((y == 0 || x == 0 || y == data->size_y / IMG_H - 1
			|| x == data->size_x / IMG_W - 1) && c != '1')
		cleanup_and_exit(data, "Error\nLoaded map is not closed by walls\n");
}

void	ft_map_check_scan(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < (data->size_y / IMG_H))
	{
		x = 0;
		while (x < (data->size_x / IMG_W))
		{
			ft_map_check_scan_core(data, x, y);
			x++;
		}
		y++;
	}
}
