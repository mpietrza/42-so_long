/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:25:43 by mpietrza          #+#    #+#             */
/*   Updated: 2023/12/12 14:26:06 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error_exit(const char *error_message)
{
	perror(error_message);
	exit(EXIT_FAILURE);
}

int	ft_exit(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data)
		ft_clup_data(data);
	ft_printf("Thank you for playing this silly game ;)\n");
	exit(EXIT_SUCCESS);
}

void	ft_win(t_data *data)
{
	if (data)
		ft_clup_data(data);
	ft_printf("Congratulations, you have won!\n");
	exit(EXIT_SUCCESS);
}

void	ft_clup_and_exit(t_data *data, const char *error_message)
{	
	if (data)
		ft_clup_data(data);
	ft_error_exit(error_message);
}

void	ft_clup_map_and_exit(t_map *map, const char *error_message)
{
	if (map)
		ft_clup_map(map);
	ft_error_exit(error_message);
}
