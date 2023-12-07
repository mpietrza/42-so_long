/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:06:32 by mpietrza          #+#    #+#             */
/*   Updated: 2023/06/14 14:07:27 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	char	*s1;
	size_t	i;

	s1 = (char *)s;
	i = 0;
	while (i < len)
	{
		s1[i] = c;
		i++;
	}
	return (s);
}
