/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:15:08 by mpietrza          #+#    #+#             */
/*   Updated: 2023/11/30 14:35:38 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**ft_map_temp(t_data *data)
{
	int		y;
	char	**map_temp;

	map_temp = (char **)malloc(data->size_y * sizeof(char *));
	if (!map_temp)
		return (NULL);
	y = 0;
	while (y < data->size_y / IMG_H)
	{
		map_temp[y] = (char *)malloc((data->size_x / IMG_W + 1) * sizeof(char));
		if (!map_temp[y])
			return (NULL);
		map_temp[y] = ft_strdup(data->map->arr[y]);
		map_temp[y][data->size_x / IMG_W] = '\0';
		y++;
	}
	map_temp[y] = NULL;
	return (map_temp);
}

static void	ft_fill(char **tab, t_point *size, t_point *cur, char to_fill)
{
	t_point	temp;
	if (cur->y < 0 || cur->y >= size->y || cur->x < 0 || cur->x >= size->x
		|| tab[cur->y][cur->x] == 'F' || tab[cur->y][cur->x] == '1'
		|| tab[cur->y][cur->x] == 'E')
		return ;
	tab[cur->y][cur->x] = 'F';
	temp = (t_point){cur->x - 1, cur->y};
	ft_fill(tab, size, &temp, to_fill);
	temp = (t_point){cur->x + 1, cur->y};
	ft_fill(tab, size, &temp, to_fill);
	temp = (t_point){cur->x, cur->y - 1};
	ft_fill(tab, size, &temp, to_fill);
	temp = (t_point){cur->x, cur->y + 1};
	ft_fill(tab, size, &temp, to_fill);
}

void	ft_flood_fill(char **tab, t_point *size, t_point *begin)
{
	ft_fill(tab, size, begin, tab[begin->y][begin->x]);
}
