/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:05:35 by mpietrza          #+#    #+#             */
/*   Updated: 2023/12/02 14:26:47 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strlen_int(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_1st_line_len(int fd)
{
	char	buffer[1];
	int		len;
	int		bytes;

	bytes = 1;
	len = 0;
	while (1)
	{
		bytes = read(fd, buffer, sizeof(buffer));
		if (bytes <= 0)
			break ;
		if (buffer[0] == '\n')
			return (len);
		len++;
		if (bytes == -1)
			return (-1);
	}
	return (len);
}

int	ft_count_lines(int fd, t_data *data, int img_w)
{
	char	*line;
	int		num_of_lines;
	int		line_len;

	num_of_lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		line_len = (int)ft_strlen(line);
		if ((line_len < (data->size_x / img_w))
			|| (line_len == 1 && *line != '\n'))
		{
			free(line);
			ft_free_and_exit(data, "Error\nThe map is corrupted\n");
		}
		else
		{
			free(line);
			num_of_lines++;
		}
	}
	free(line);
	return (num_of_lines);
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
