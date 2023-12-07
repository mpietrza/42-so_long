/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:34:00 by mpietrza          #+#    #+#             */
/*   Updated: 2023/06/20 16:54:43 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	delta_s;
	size_t	i;

	delta_s = 0;
	i = 0;
	while (i < n)
	{
		delta_s = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (delta_s != 0)
			return (delta_s);
		if ((unsigned char)s1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
