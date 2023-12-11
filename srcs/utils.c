/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:05:35 by mpietrza          #+#    #+#             */
/*   Updated: 2023/12/11 18:29:51 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_map_parse(int fd, t_point map_size)
{
	char	*line;
	char	*buff_for_ar
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
			ft_free_and_exit(data, "Error\nThe map is not rectangular\n");
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
	return (buff_for_arr);
}

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
