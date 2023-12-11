/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:55:41 by mpietrza          #+#    #+#             */
/*   Updated: 2023/12/08 14:44:04 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_wrong_map_exit(t_data *data, int fd, char **argv)
{
	ft_printf("fd = %d\n", fd);
	if (fd < 0)
		ft_free_and_exit(data, "Error\nReading the map not successful\n");
	if (ft_strnstr(argv[1], ".ber", ft_strlen_int(argv[1])) == NULL)
		ft_free_and_exit(data, "Error\nWrong map extension, must be a '.ber' file\n");
}


