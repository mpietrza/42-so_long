/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:15:08 by mpietrza          #+#    #+#             */
/*   Updated: 2023/12/12 14:26:04 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**ft_arr_temp(t_map *map)
{
	int		y;
	char	**arr_temp;

	arr_temp = (char **)malloc(map->map_size->y * sizeof(char *));
	if (!arr_temp)
		return (NULL);
	y = 0;
	while (y < map->map_size->y)
	{
		arr_temp[y] = (char *)malloc((map->map_size->x + 1) * sizeof(char));
		if (!arr_temp[y])
			return (NULL);
		arr_temp[y] = ft_strdup(map->arr[y]);
		arr_temp[y][map->map_size->x] = '\0';
		y++;
	}
	arr_temp[y] = NULL;
	return (arr_temp);
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
