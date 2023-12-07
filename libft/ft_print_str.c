/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:23:19 by mpietrza          #+#    #+#             */
/*   Updated: 2023/11/19 16:42:17 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "unistd.h"

int	ft_print_str(char *s)
{
	int		ret;
	size_t	len;

	ret = 0;
	if (!s)
	{
		ret = write(1, "(null)", 6);
		if (ret < 0)
			return (-1);
		return (6);
	}
	else if (!*s)
		return (0);
	else
	{
		len = ft_strlen(s);
		ret = write(1, s, len);
		if (ret < 0)
			return (-1);
	}
	return (ret);
}
