/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_perc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:37:09 by mpietrza          #+#    #+#             */
/*   Updated: 2023/08/09 12:31:30 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_print_perc(void)
{
	int	ret;

	ret = write(1, "%", 1);
	if (ret != 1)
		return (-1);
	return (ret);
}
