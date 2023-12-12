/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:06:11 by mpietrza          #+#    #+#             */
/*   Updated: 2023/12/12 14:25:48 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_map_check_content(t_map *map)
{
	int	y;
	int	exit;

	y = 0;
	exit = 0;
	while (map->arr && map->arr[y])
	{
		exit += ft_count_chars(map->arr[y], 'E');
		map->collectibles += ft_count_chars(map->arr[y], 'C');
		y++;
	}
	if (exit == 0)
		ft_clup_map_and_exit(map,
			"Error\nThere must be at least one exit on a loaded map\n");
	if (exit > 1)
		ft_clup_map_and_exit(map,
			"Error\nThere must be only one exit on a loaded map\n");
	if (map->collectibles <= 0)
		ft_clup_map_and_exit(map,
			"Error\nThere is no collectibles on a loaded map\n");
}


void	ft_map_checks(t_map *map)
{
	ft_map_find_start_pos(map);
	ft_map_check_content(map);
	ft_map_check_scan(map);
	ft_map_check_path(map);
}

char	*ft_map_parse(int fd, t_point *map_size)
{
	char	*line;
	char	*buf_for_arr = NULL;
	int		num_of_lines;
	int		line_len;
	int		prev_line_len;

	prev_line_len = 0;
	num_of_lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		line_len = (int)ft_strlen(line);
		if (line_len != prev_line_len)
		{
			free(line);
			free(map_size);
			ft_error_exit("Error\nThe map is not rectangular\n");
		}
		else
		{
			ft_strlcat(buf_for_arr, line, line_len);
			free(line);
			prev_line_len = line_len;
			num_of_lines++;
		}
	}
	buf_for_arr[(int)ft_strlen(line) - 1] = '\0';
	free(line);
	close(fd);
	map_size->x = line_len;
	map_size->y = num_of_lines;
	return (buf_for_arr);
}
