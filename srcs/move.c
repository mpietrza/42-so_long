/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:28:19 by mpietrza          #+#    #+#             */
/*   Updated: 2023/12/12 14:25:42 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_player_move(t_data *data, char pos, int direction)
{
	if (pos == 'y' && direction == UP)
		mlx_put_image_to_window(data->mlx, data->window, data->img->player_up,
			(data->pos_x * IMG_W), (data->pos_y * IMG_H));
	if (pos == 'x' && direction == LEFT)
		mlx_put_image_to_window(data->mlx, data->window, data->img->player_left,
			(data->pos_x * IMG_W), (data->pos_y * IMG_H));
	if (pos == 'y' && direction == DOWN)
		mlx_put_image_to_window(data->mlx, data->window, data->img->player_down,
			(data->pos_x * IMG_W), (data->pos_y * IMG_H));
	if (pos == 'x' && direction == RIGHT)
		mlx_put_image_to_window(data->mlx, data->window,
			data->img->player_right, (data->pos_x * IMG_W),
			(data->pos_y * IMG_H));
}

static void	ft_collect(t_data *data, t_map *map, char pos, int dir)
//sums up collectibles and removes them from the list and screen
{
	data->collected++;
	map->arr[data->pos_y][data->pos_x] = '0';
	mlx_put_image_to_window(data->mlx, data->window, data->img->background,
		(data->pos_x * IMG_W), (data->pos_y * IMG_H));
	ft_player_move(data, pos, dir);
}

static void	ft_move_message(t_data *data, t_point *prev_pos)
{
	if (data->pos_x != prev_pos->x || data->pos_y != prev_pos->y)
		ft_printf("Current number of movements: %d\n", ++data->counter);
}

static void	ft_move_filter(t_data *data, t_map *map, char pos, int dir)
{
	if (pos == 'y' && map->arr[data->pos_y + dir][data->pos_x] != '1'
		&& (map->arr[data->pos_y + dir][data->pos_x] != 'E'
		|| data->collected == map->collectibles))
		data->pos_y = data->pos_y + dir;
	else if (pos == 'x' && map->arr[data->pos_y][data->pos_x + dir]
		!= '1' && (map->arr[data->pos_y][data->pos_x + dir] != 'E'
		|| data->collected == map->collectibles))
		data->pos_x = data->pos_x + dir;
	else if (pos == 'y' && map->arr[data->pos_y + dir][data->pos_x]
		== 'E' && data->collected != map->collectibles)
		ft_printf("You must collect all the collectibles first\n");
	else if (pos == 'x' && map->arr[data->pos_y][data->pos_x + dir]
		== 'E' && data->collected != map->collectibles)
		ft_printf("You must collect all the collectibles first\n");
}

void	ft_move(t_data *data, t_map *map, char pos, int dir)
{
	t_point	*prev_pos;

	prev_pos = (t_point *)malloc(sizeof(t_point));
	prev_pos->x = data->pos_x;
	prev_pos->y = data->pos_y;
	mlx_put_image_to_window(data->mlx, data->window, data->img->background,
		(data->pos_x * IMG_W), (data->pos_y * IMG_H));
	ft_move_filter(data, map, pos, dir);
	ft_player_move(data, pos, dir);
	if (map->arr[data->pos_y][data->pos_x] == 'C')
		ft_collect(data, map, pos, dir);
	ft_move_message(data, prev_pos);
	free(prev_pos);
	mlx_do_sync(data->mlx);
}
