/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:55:15 by mpietrza          #+#    #+#             */
/*   Updated: 2023/07/12 12:47:32 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*ch1;
	unsigned const char	*ch2;
	size_t				i;
	size_t				result;

	ch1 = s1;
	ch2 = s2;
	i = 0;
	while (i < n)
	{
		result = ch1[i] - ch2[i];
		if (result != 0)
			return (result);
		i++;
	}
	return (0);
}
