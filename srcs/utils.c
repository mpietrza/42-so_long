/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:05:35 by mpietrza          #+#    #+#             */
/*   Updated: 2023/12/13 17:11:41 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_count_chars(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (-1);
	while (s[i])
		if (s[i++] == c)
			count++;
	return (count);
}

char	**ft_map_str_to_arr(char *buf_for_arr)
{
	char	**arr;
	char	c;
	int		y;
	int		x;

	c = 10;
	arr = ft_split(buf_for_arr, c);
	if (!arr)
		return (NULL);
	y = 0;
	while (arr[y])
	{
		x = 0;
		while (arr[y][x])
		{
			if (arr[y][x] == 10)
				arr[y][x] = '\0';
			x++;
		}
		y++;
	}
	return (arr);
}
