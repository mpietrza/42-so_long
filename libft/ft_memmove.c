/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:36:20 by mpietrza          #+#    #+#             */
/*   Updated: 2023/06/14 14:06:25 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_ptr;
	const char	*src_ptr;
	size_t		i;

	dst_ptr = (char *)dst;
	src_ptr = (const char *)src;
	if (dst_ptr > src_ptr)
	{
		i = len;
		while (i != 0)
		{
			dst_ptr[i - 1] = src_ptr[i - 1];
			i--;
		}
	}
	else if (dst_ptr < src_ptr)
	{
		i = 0;
		while (i < len)
		{
			dst_ptr[i] = src_ptr[i];
			i++;
		}
	}
	return (dst);
}
